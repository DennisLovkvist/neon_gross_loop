/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "foreground_character.h"

void ConfigureForegroundCharacter(ForegroundCharacter& fg_char, sf::Texture& sprite_sheet)
{
	fg_char.sprite.setTexture(sprite_sheet);
	fg_char.sprite.setTextureRect(fg_char.source);
	fg_char.sprite.setPosition(sf::Vector2f(350, 60));
}
void UpdateForegroundCharacter(ForegroundCharacter& fg_char, float dt)
{
	fg_char.counter += dt;

	if (fg_char.counter >= fg_char.interval)
	{
		fg_char.frame++;
		fg_char.counter = fg_char.interval - fg_char.counter;
	}

	if (fg_char.frame >= fg_char.duration)
	{
		fg_char.frame = 0;
	}

	int x = fg_char.frame % 29;
	int y = fg_char.frame / 29;

	fg_char.source.left = (x * fg_char.source.width);
	fg_char.source.top = (y * fg_char.source.height);

	fg_char.sprite.setTextureRect(fg_char.source);

}
