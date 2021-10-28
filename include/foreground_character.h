/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>

struct ForegroundCharacter
{
	sf::IntRect source = sf::IntRect(0, 0, 120, 260);
	sf::Sprite sprite;
	int frame = 0;
	float duration = 57;
	float counter = 0;
	float interval = 0.1f;
};

void ConfigureForegroundCharacter(ForegroundCharacter& fg_char, sf::Texture& sprite_sheet);
void UpdateForegroundCharacter(ForegroundCharacter& fg_char, float dt);