/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#pragma once
#include <SFML/Graphics.hpp>

struct Customer
{
	bool leaving_store = false;
	bool shopping_cart = false;
	sf::IntRect source = sf::IntRect(0, 0, 48, 48);
	sf::Vector2f pos = sf::Vector2f(0, 160);
	sf::Sprite sprite;
	float frame = 0;
	float duration = 8;
	float delay = 0;
	float delay_counter = 0;
	float counter = 0;
	float interval = 0.09f;
};
void UpdateCustomer(Customer& customer, float dt);
void DrawCustomer(sf::RenderTexture& window, Customer& customer);