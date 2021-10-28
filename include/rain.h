/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once

static const int RAIN_DROP_COUNT = 12;
static const float ANIMATION_DURATION_SPLASH = 0.05f;
static const float ANIMATION_DURATION_RIPPLE = 0.04f;

#include <SFML/Graphics.hpp>
#include "rain.h"

struct Rain
{
	sf::IntRect* src_splash = new sf::IntRect[RAIN_DROP_COUNT];
	sf::IntRect* src_drop = new sf::IntRect[RAIN_DROP_COUNT];
	sf::IntRect* src_ripple_distortion = new sf::IntRect[RAIN_DROP_COUNT];
	sf::IntRect* src_ripple_highlight = new sf::IntRect[RAIN_DROP_COUNT];

	sf::Sprite* sprite_splash = new sf::Sprite[RAIN_DROP_COUNT];
	sf::Sprite* sprite_drop = new sf::Sprite[RAIN_DROP_COUNT];
	sf::Sprite* sprite_ripple_distortion = new sf::Sprite[RAIN_DROP_COUNT];
	sf::Sprite* sprite_ripple_highlight = new sf::Sprite[RAIN_DROP_COUNT];

	sf::Vector2f* position = new sf::Vector2f[RAIN_DROP_COUNT];
	sf::Vector2f* velocity = new sf::Vector2f[RAIN_DROP_COUNT];
	sf::Color* color = new sf::Color[RAIN_DROP_COUNT];

	float* animation_time_splash = new float[RAIN_DROP_COUNT];
	float* animation_time_ripple = new float[RAIN_DROP_COUNT];

	float* depth = new float[RAIN_DROP_COUNT];
	bool* impact = new bool[RAIN_DROP_COUNT];
	bool* ripple = new bool[RAIN_DROP_COUNT];

	sf::RenderTexture texture_drop;
	sf::RenderTexture texture_splash;
	sf::Texture texture_ripple;


};
void ConfigureRain(Rain& rain);
void SetUpRain(Rain& rain);
void SpawnRainDrop(Rain& rain, int index);
bool PreRenderSplashSpriteSheet(sf::Texture& texture, sf::Color color_main, sf::Color color_highlight, sf::RenderTexture& result);
bool PreRenderDropSpriteSheet(sf::Texture& texture, sf::Color color_main, sf::Color color_highlight, sf::RenderTexture& result);
void UpdateRain(Rain& rain, float dt);
void DrawRainDrop(sf::RenderWindow& window, Rain& rain);
void DrawSurfaceRipple(sf::RenderTexture& window, Rain& rain);
void DrawSurfaceRippleHighlight(sf::RenderWindow& window, Rain& rain);
