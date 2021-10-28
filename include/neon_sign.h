/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>

struct NeonSign
{
	sf::IntRect layers[3] =
	{
		sf::IntRect(0, 0, 128, 96),
		sf::IntRect(128, 0, 128, 96),
		sf::IntRect(256, 0, 128, 96),
	};
	sf::Sprite sprite;
	sf::Color color = sf::Color(0, 204, 255);
	float flicker = 255;
};
void DrawNeonSign(sf::RenderTexture& window, NeonSign& neon_sign);
void UpdateNeonSign(NeonSign& neon_sign);