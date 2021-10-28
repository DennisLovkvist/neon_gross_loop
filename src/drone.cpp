/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "drone.h"

void UpdateDrone(Drone& drone, float dt)
{
	drone.t += dt * ((rand() % 6 - 3 + 1 + 3) - 6);
	drone.vel_x = std::cos(drone.t) * 10;
	drone.vel_y = std::sin(drone.t) * 10;


	drone.rotation_engine_back_left = drone.vel_x * 0.5;
	drone.rotation_engine_back_right = drone.vel_x * 0.6;
	drone.rotation_engine_front_left = drone.vel_x * 0.7;
	drone.rotation_engine_front_right = drone.vel_x;
	drone.rotation_bag = drone.vel_x * 0.4;

	drone.pos.x += drone.vel_x * dt;
	drone.pos.y += drone.vel_y * dt;

	int n = 30;

	if (drone.pos.x < 150 - n)
	{
		drone.pos.x = 150 - n;
	}
	else if (drone.pos.x > 150 + n)
	{
		drone.pos.x = 150 + n;
	}
	if (drone.pos.y < 150 - n)
	{
		drone.pos.y = 150 - n;
	}
	else if (drone.pos.y > 150 + n)
	{
		drone.pos.y = 150 + n;
	}


	drone.pos_bag.y = drone.pos.y + 33;

	float delta = drone.pos.x - drone.pos_bag.x + 2;

	drone.pos_bag.x += delta * 0.1;

	drone.sprite_bag.setPosition(drone.pos_bag);

	drone.sprite_body.setPosition(drone.pos + drone.pos_body);
	drone.sprite_light.setPosition(drone.pos + drone.pos_light);

	drone.sprite_engine_back_left.setPosition(drone.pos + drone.pos_engine_back_left);
	drone.sprite_engine_back_right.setPosition(drone.pos + drone.pos_engine_back_right);
	drone.sprite_engine_front_left.setPosition(drone.pos + drone.pos_engine_front_left);
	drone.sprite_engine_front_right.setPosition(drone.pos + drone.pos_engine_front_right);


	float max_angle = 10;

	if (drone.rotation_engine_back_left > max_angle)
	{
		drone.rotation_engine_back_left = max_angle;
	}
	else if (drone.rotation_engine_back_left < -max_angle)
	{
		drone.rotation_engine_back_left = -max_angle;
	}

	if (drone.rotation_engine_back_right > max_angle)
	{
		drone.rotation_engine_back_right = max_angle;
	}
	else if (drone.rotation_engine_back_right < -max_angle)
	{
		drone.rotation_engine_back_right = -max_angle;
	}

	if (drone.rotation_engine_front_left > max_angle)
	{
		drone.rotation_engine_front_left = max_angle;
	}
	else if (drone.rotation_engine_front_left < -max_angle)
	{
		drone.rotation_engine_front_left = -max_angle;
	}

	if (drone.rotation_engine_front_right > max_angle)
	{
		drone.rotation_engine_front_right = max_angle;
	}
	else if (drone.rotation_engine_front_right < -max_angle)
	{
		drone.rotation_engine_front_right = -max_angle;
	}

	if (drone.rotation_bag > max_angle)
	{
		drone.rotation_bag = max_angle;
	}
	else if (drone.rotation_bag < -max_angle)
	{
		drone.rotation_bag = -max_angle;
	}

	drone.line[0] = drone.pos;
	drone.line[1].position.x = drone.pos_bag.x - 2;
	drone.line[1].position.y = drone.pos_bag.y - 2;

	drone.sprite_engine_back_left.setRotation(drone.rotation_engine_back_left);
	drone.sprite_engine_back_right.setRotation(drone.rotation_engine_back_right);
	drone.sprite_engine_front_left.setRotation(drone.rotation_engine_front_left);
	drone.sprite_engine_front_right.setRotation(drone.rotation_engine_front_right);
	drone.sprite_bag.setRotation(drone.rotation_bag);
}
void DrawDrone(sf::RenderWindow& window, Drone& drone)
{
	window.draw(drone.sprite_bag);
	window.draw(drone.line, 2, sf::Lines);
	window.draw(drone.sprite_engine_back_left);
	window.draw(drone.sprite_engine_back_right);
	window.draw(drone.sprite_body);
	window.draw(drone.sprite_light);
	window.draw(drone.sprite_engine_front_left);
	window.draw(drone.sprite_engine_front_right);

}
void ConfigureDrone(Drone& drone, sf::Texture& sprite_sheet)
{
	drone.sprite_engine_back_left.setTexture(sprite_sheet);
	drone.sprite_engine_back_right.setTexture(sprite_sheet);
	drone.sprite_engine_front_left.setTexture(sprite_sheet);
	drone.sprite_engine_front_right.setTexture(sprite_sheet);
	drone.sprite_body.setTexture(sprite_sheet);
	drone.sprite_light.setTexture(sprite_sheet);
	drone.sprite_bag.setTexture(sprite_sheet);

	drone.sprite_engine_back_left.setTextureRect(drone.src_engine_back_left);
	drone.sprite_engine_back_right.setTextureRect(drone.src_engine_back_right);
	drone.sprite_engine_front_left.setTextureRect(drone.src_engine_front_left);
	drone.sprite_engine_front_right.setTextureRect(drone.src_engine_front_right);
	drone.sprite_body.setTextureRect(drone.src_body);
	drone.sprite_light.setTextureRect(drone.src_light);
	drone.sprite_bag.setTextureRect(drone.src_bag);

	drone.sprite_engine_back_left.setOrigin(sf::Vector2f(18, 6));
	drone.sprite_engine_back_right.setOrigin(sf::Vector2f(18, 6));
	drone.sprite_engine_front_left.setOrigin(sf::Vector2f(18, 6));
	drone.sprite_engine_front_right.setOrigin(sf::Vector2f(18, 6));
	drone.sprite_bag.setOrigin(sf::Vector2f(20, 4));

	drone.pos_bag.x = drone.pos.x + 4;
	drone.pos_bag.y = drone.pos.y + 33.2;
}
