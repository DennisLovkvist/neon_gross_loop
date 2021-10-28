/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "neon_sign.h"

void DrawNeonSign(sf::RenderTexture& window, NeonSign& neon_sign)
{
	neon_sign.color.a = 255;
	neon_sign.sprite.setColor(sf::Color::White);
	neon_sign.sprite.setTextureRect(neon_sign.layers[0]);
	window.draw(neon_sign.sprite);

	neon_sign.color.a = neon_sign.flicker;
	neon_sign.sprite.setColor(neon_sign.color);
	neon_sign.sprite.setTextureRect(neon_sign.layers[1]);
	window.draw(neon_sign.sprite);

	neon_sign.sprite.setColor(sf::Color::White);
	neon_sign.sprite.setTextureRect(neon_sign.layers[2]);
	window.draw(neon_sign.sprite);
	window.draw(neon_sign.sprite);
}
void UpdateNeonSign(NeonSign& neon_sign)
{
	neon_sign.flicker += rand() % (10 - (-10) + 1) + (-10);

    int n = rand() % (100 - (1) + 1) + (1);

	if(n < 2)
	{
        neon_sign.flicker = 200;
	}
	else if(n < 4)
	{
        neon_sign.flicker = 255;
	}

	if (neon_sign.flicker < 200)
	{
		neon_sign.flicker = 200;
	}
	if (neon_sign.flicker > 255)
	{
		neon_sign.flicker = 255;
	}
}
