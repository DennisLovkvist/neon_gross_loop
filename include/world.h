/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "neon_sign.h"
#include "rain.h"
#include "rain.h"
#include "character_sillouettes.h"
#include "customer.h"
#include "drone.h"
#include "foreground_character.h"

struct World
{
	sf::Texture tex_skyline;
	sf::Texture tex_neon_signs;
	sf::Texture tex_cobblestone;
	sf::Texture tex_building;
	sf::Texture tex_background_character_0;
	sf::Texture tex_background_character_1;
	sf::Texture tex_customer_walk_cycles;
	sf::Texture tex_drone;
	sf::Texture tex_foreground_character;
	sf::Texture tex_glow;

	sf::RenderTexture rt_pass_0;
	sf::RenderTexture rt_pass_1;

	sf::RenderTexture rt_surface_distortion_map;

	sf::Sprite sprite_cobblestone;
	sf::Sprite sprite_building;
	sf::Sprite sprite_world_reflection;
	sf::Sprite sprite_skyline;
	sf::Sprite sprite_building_reflection;
	sf::Sprite sprite_building_real;

	sf::RectangleShape shape_indoor_ambient_light_bg;

	sf::Vertex shape_indoor_ambient_light_fade[4];
	sf::Vertex shape_indoor_ambient_light_fg[4];

	sf::Vertex ground[4];
	sf::Vertex ground2[4];
	sf::Vertex shape_sky[4];

	NeonSign neon_sign_left;
	NeonSign neon_sign_right;
	Rain rain;
	CharacterSillouette character_sillouette;

	Customer customer_entering;
	Customer customer_leaving;

	Drone drone;

	ForegroundCharacter foreground_character;

	sf::Sprite sprite_glow;


};
void UpdateWorld(World& world, float dt);
void LoadTextures(World& world);
void SetupWorld(World& world);
void DrawSurfaceDistortionMap(World& world);
void RenderPass0(World& world);
void RenderPass1(World& world);
void DrawWorld(sf::RenderWindow& window, sf::Shader& shader, World& world);
