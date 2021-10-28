/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"

struct Drone
{
	sf::IntRect src_engine_back_left = sf::IntRect(0, 0, 36, 12);
	sf::IntRect src_engine_back_right = sf::IntRect(0, 12, 36, 12);
	sf::IntRect src_engine_front_left = sf::IntRect(0, 24, 36, 12);
	sf::IntRect src_engine_front_right = sf::IntRect(0, 36, 36, 12);
	sf::IntRect src_body = sf::IntRect(36, 0, 64, 48);
	sf::IntRect src_light = sf::IntRect(100, 0, 64, 64);
	sf::IntRect src_bag = sf::IntRect(172, 0, 40, 48);

	sf::Vector2f pos = sf::Vector2f(150, 150);

	sf::Vector2f pos_engine_back_left = sf::Vector2f(-12, -19);
	sf::Vector2f pos_engine_back_right = sf::Vector2f(30, -19);
	sf::Vector2f pos_engine_front_left = sf::Vector2f(-31, -8);
	sf::Vector2f pos_engine_front_right = sf::Vector2f(42, -8);
	sf::Vector2f pos_body = sf::Vector2f(-26, -29);
	sf::Vector2f pos_light = sf::Vector2f(-37, -31);
	sf::Vector2f pos_bag = sf::Vector2f();

	sf::Sprite sprite_engine_back_left;
	sf::Sprite sprite_engine_back_right;
	sf::Sprite sprite_engine_front_left;
	sf::Sprite sprite_engine_front_right;
	sf::Sprite sprite_body;
	sf::Sprite sprite_light;
	sf::Sprite sprite_bag;

	float rotation_engine_back_left = 0;
	float rotation_engine_back_right = 0;
	float rotation_engine_front_left = 0;
	float rotation_engine_front_right = 0;
	float rotation_bag = 0;

	float vel_x = 0;
	float vel_y = 0;
	float t = 0;

	sf::Vertex line[2];

};

void UpdateDrone(Drone& drone, float dt);
void DrawDrone(sf::RenderWindow& window, Drone& drone);
void ConfigureDrone(Drone& drone, sf::Texture& sprite_sheet);