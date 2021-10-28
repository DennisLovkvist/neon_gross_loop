/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>

const int BACKGROUND_CHARACTERS = 2;

struct CharacterSillouette
{
	sf::Sprite* sprite = new sf::Sprite[BACKGROUND_CHARACTERS];
	sf::IntRect* source = new sf::IntRect[BACKGROUND_CHARACTERS];
	float* counter = new float[BACKGROUND_CHARACTERS];
	float* interval = new float[BACKGROUND_CHARACTERS];
	int* frame = new int[BACKGROUND_CHARACTERS];
	int* duration = new int[BACKGROUND_CHARACTERS];
	int* animations = new int[BACKGROUND_CHARACTERS];
	int* animation_index = new int[BACKGROUND_CHARACTERS];
	bool* idle = new bool[BACKGROUND_CHARACTERS];
};

void DrawCharacterSillouette(sf::RenderTexture& window, CharacterSillouette& character_sillouette);
void ConfigureCharacterSillouette(CharacterSillouette& character_sillouette);
void UpdateCharacterSillouette(CharacterSillouette& character_sillouette, float dt);