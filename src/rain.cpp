/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "rain.h"

void SpawnRainDrop(Rain& rain, int index)
{
	rain.src_splash[index].top = (rand() % (2 - (0) + 1) + (0)) * 64;
	rain.src_splash[index].left = 0;
	rain.position[index].x = rand() % (480-64 - (0) + 1) + (0);
	rain.position[index].y = (rand() % 320 - 0 + 1 + 0) - 320;
	rain.depth[index] = rand() % (64 - (1) + 1) + (1);
	float s = 1 - (rain.depth[index] / 128);
	rain.sprite_splash[index].setScale(sf::Vector2f(s, s));
	rain.sprite_drop[index].setScale(sf::Vector2f(s, s));
	rain.sprite_drop[index].setPosition(rain.position[index]);
	rain.impact[index] = false;
}
bool PreRenderSplashSpriteSheet(sf::Texture& texture, sf::Color color_main, sf::Color color_highlight, sf::RenderTexture& result)
{
	sf::Vector2u dimensions = texture.getSize();

	if (!result.create(dimensions.x, dimensions.y))
	{
		return false;
	}
	else
	{
		result.clear(sf::Color::Transparent);

		sf::Sprite sprite;

		sprite.setTexture(texture);
		sprite.setScale(1, -1);
		sprite.setOrigin(0, (int)(dimensions.y));

		sprite.setTextureRect(sf::IntRect(0, 0, dimensions.x, dimensions.y / 2));
		sprite.setColor(color_main);
		result.draw(sprite);

		sprite.setTextureRect(sf::IntRect(0, dimensions.y / 2, dimensions.x, dimensions.y / 2));
		sprite.setColor(color_highlight);
		result.draw(sprite);

		return true;
	}
}
bool PreRenderDropSpriteSheet(sf::Texture& texture, sf::Color color_main, sf::Color color_highlight, sf::RenderTexture& result)
{
	sf::Vector2u dimensions = texture.getSize();

	if (!result.create(dimensions.x/2, dimensions.y))
	{
		return false;
	}
	else
	{
		result.clear(sf::Color::Transparent);

		sf::Sprite sprite;

		sprite.setTexture(texture);
		sprite.setScale(1, -1);
		sprite.setOrigin(0, (int)(dimensions.y));

		sprite.setTextureRect(sf::IntRect(0, 0, dimensions.x / 2, dimensions.y));
		sprite.setColor(color_main);
		result.draw(sprite);

		sprite.setTextureRect(sf::IntRect(dimensions.x / 2, 0, dimensions.x / 2, dimensions.y));
		sprite.setColor(color_highlight);
		result.draw(sprite);

		return true;
	}
}
void SetUpRain(Rain& rain)
{
	sf::Texture* texture_splash_original = new sf::Texture();
	texture_splash_original->loadFromFile("content/textures/rain_impacts.png");
	PreRenderSplashSpriteSheet(*texture_splash_original, sf::Color(0, 204, 255), sf::Color::White, rain.texture_splash);
	delete texture_splash_original;

	sf::Texture* texture_drop_original = new sf::Texture();
	texture_drop_original->loadFromFile("content/textures/rain_drop.png");
	PreRenderDropSpriteSheet(*texture_drop_original, sf::Color(0, 204, 255), sf::Color::White, rain.texture_drop);
	delete texture_drop_original;

	rain.texture_ripple.loadFromFile("content/textures/surface_wave.png");

}
void UpdateRain(Rain& rain, float dt)
{

	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		if (rain.impact[i])
		{
			rain.animation_time_splash[i] += dt;

			if (rain.animation_time_splash[i] >= ANIMATION_DURATION_SPLASH)
			{
				rain.src_splash[i].left += 64;
				if (rain.src_splash[i].left > 64 * 12)
				{
					SpawnRainDrop(rain, i);
				}

				rain.sprite_splash[i].setTextureRect(rain.src_splash[i]);
				rain.animation_time_splash[i] = ANIMATION_DURATION_SPLASH - rain.animation_time_splash[i];
			}
		}
		else
		{
			rain.position[i] += rain.velocity[i];
			rain.sprite_drop[i].setPosition(rain.position[i]);
		}

		if (rain.ripple[i])
		{
			rain.animation_time_ripple[i] += dt;

			if (rain.animation_time_ripple[i] >= ANIMATION_DURATION_RIPPLE)
			{
				rain.src_ripple_distortion[i].left += 128;
				rain.src_ripple_highlight[i].left += 128;

				rain.sprite_ripple_distortion[i].setTextureRect(rain.src_ripple_distortion[i]);
				rain.sprite_ripple_highlight[i].setTextureRect(rain.src_ripple_highlight[i]);
				rain.animation_time_ripple[i] = ANIMATION_DURATION_RIPPLE - rain.animation_time_ripple[i];
			}

		}

		if (rain.position[i].y > 240 - rain.depth[i] * 0.5f)
		{

			rain.impact[i] = true;
			rain.sprite_splash[i].setPosition(rain.position[i]);

			if (!rain.ripple[i])
			{
				rain.ripple[i] = true;
				float s = 1 - (rain.depth[i] / 128);
				rain.sprite_ripple_distortion[i].setScale(s, s);
				rain.sprite_ripple_highlight[i].setScale(s, s);

				rain.sprite_ripple_distortion[i].setTextureRect(rain.src_ripple_distortion[i]);
				float x = rain.position[i].x - (64 * s) / 2;
				float y = 320 - (rain.position[i].y + (32 * s) / 2) - 64 * s;

				float xhl = rain.position[i].x - (64 * s) / 2;
				float yhl = rain.position[i].y + (24 * s) / 2;

				rain.sprite_ripple_highlight[i].setPosition(xhl, yhl);
				rain.sprite_ripple_distortion[i].setPosition(x, y);
			}
		}
		else
		{
			if (rain.src_ripple_distortion[i].left > 128 * 15)
			{
				rain.src_ripple_distortion[i].left = 0;
				rain.src_ripple_highlight[i].left = 0;
				rain.animation_time_ripple[i] = 0;
				rain.ripple[i] = false;
			}
		}
	}
}

void ConfigureRain(Rain& rain)
{
	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		rain.animation_time_splash[i] = 0;
		rain.animation_time_ripple[i] = 0;
		rain.velocity[i].y = 22;
		rain.src_splash[i] = sf::IntRect(0, 0, 64, 64);
		rain.src_drop[i] = sf::IntRect(0, 0, 64, 64);
		rain.src_ripple_distortion[i] = sf::IntRect(0, 0, 128, 64);
		rain.src_ripple_highlight[i] = sf::IntRect(0, 64, 128, 64);
		rain.color[i] = sf::Color(0, 204, 255);
		rain.ripple[i] = false;
		rain.impact[i] = false;
		rain.sprite_ripple_highlight[i].setColor(sf::Color(255, 255, 255, 100));

		rain.sprite_drop[i].setTexture(rain.texture_drop.getTexture());
		rain.sprite_splash[i].setTexture(rain.texture_splash.getTexture());
		rain.sprite_ripple_distortion[i].setTexture(rain.texture_ripple);
		rain.sprite_ripple_highlight[i].setTexture(rain.texture_ripple);
	}
}

void DrawRainDrop(sf::RenderWindow& window, Rain& rain)
{
	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		if (rain.impact[i])
		{
			window.draw(rain.sprite_splash[i]);
		}
		else
		{
			window.draw(rain.sprite_drop[i]);;
		}
	}
}
void DrawSurfaceRipple(sf::RenderTexture& window, Rain& rain)
{
	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		if (rain.ripple[i])
		{
			window.draw(rain.sprite_ripple_distortion[i]);
		}
	}
}
void DrawSurfaceRippleHighlight(sf::RenderWindow& window, Rain& rain)
{
	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		if (rain.ripple[i])
		{
			window.draw(rain.sprite_ripple_highlight[i]);
		}
	}
}
