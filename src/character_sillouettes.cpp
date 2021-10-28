/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "character_sillouettes.h"

void DrawCharacterSillouette(sf::RenderTexture& window, CharacterSillouette& character_sillouette)
{
	for (size_t i = 0; i < BACKGROUND_CHARACTERS; i++)
	{
		window.draw(character_sillouette.sprite[i]);
	}
}
void ConfigureCharacterSillouette(CharacterSillouette& character_sillouette)
{
	for (size_t i = 0; i < BACKGROUND_CHARACTERS; i++)
	{
		character_sillouette.source[i].width = 32;
		character_sillouette.source[i].height = 32;
		character_sillouette.sprite[i].setTextureRect(character_sillouette.source[i]);
		character_sillouette.sprite[i].setColor(sf::Color(38, 53, 64));
		character_sillouette.frame[i] = 0;
		character_sillouette.counter[i] = 0;
		character_sillouette.interval[i] = 0.1;
		character_sillouette.animation_index[i] = 0;
		character_sillouette.idle[i] = false;
	}

	character_sillouette.duration[0] = 12;
	character_sillouette.animations[0] = 3;

	character_sillouette.duration[1] = 14;
	character_sillouette.animations[1] = 3;

	character_sillouette.sprite[0].setPosition(sf::Vector2f(300, 174));
	character_sillouette.sprite[1].setPosition(sf::Vector2f(320, 174));


	
}
void UpdateCharacterSillouette(CharacterSillouette& character_sillouette, float dt)
{
	for (size_t i = 0; i < BACKGROUND_CHARACTERS; i++)
	{
		character_sillouette.counter[i] += dt;

		if (character_sillouette.counter[i] >= character_sillouette.interval[i])
		{
			character_sillouette.frame[i] ++;
			character_sillouette.counter[i] = character_sillouette.interval[i] - character_sillouette.counter[i];
		}

		if (character_sillouette.frame[i] >= character_sillouette.duration[i])
		{
			int dist = rand() % (100 - (1) + 1) + (1) - 1;
			character_sillouette.idle[i] = false;
			if (dist > 95)
			{
				character_sillouette.animation_index[i] = 0;
			}
			else if (dist > 80)
			{
				character_sillouette.animation_index[i] = 1;
			}
			else if (dist > 70)
			{
				character_sillouette.animation_index[i] = 2;
			}
			else
			{
				character_sillouette.idle[i] = true;
			}
			character_sillouette.frame[i] = 0;
		}

		if (character_sillouette.idle[i])
		{
			character_sillouette.source[i].left = 0;
			character_sillouette.source[i].top = 0;
		}
		else
		{
			character_sillouette.source[i].left = 32 * character_sillouette.frame[i];
			character_sillouette.source[i].top = 32 * character_sillouette.animation_index[i];
		}


		character_sillouette.sprite[i].setTextureRect(character_sillouette.source[i]);
	}
}
