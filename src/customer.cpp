/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "customer.h"

void UpdateCustomer(Customer& customer, float dt)
{
	if (customer.delay_counter < customer.delay)
	{
		customer.delay_counter += dt;
		return;
	}
	if (customer.leaving_store)
	{
		customer.pos.x -= 30 * dt;
		if (customer.pos.x < -64)
		{
			customer.pos.x = 240;
			customer.shopping_cart = ((rand() % 100 - 0 + 1 + 0) > 50);
			customer.delay_counter = 0;
			customer.delay = (rand() % 10 - 1 + 1 + 1);
		}
		customer.sprite.setScale(-1, 1);
	}
	else
	{
		customer.pos.x += 30 * dt;
		if (customer.pos.x > 240)
		{
			customer.pos.x = -64;
			customer.shopping_cart = ((rand() % 100 - 0 + 1 + 0) > 50);
			customer.delay_counter = 0;
			customer.delay = (rand() % 10 - 1 + 1 + 1);

		}
		customer.sprite.setScale(1, 1);
	}

	customer.counter += dt;

	if (customer.counter >= customer.interval)
	{
		customer.frame++;
		customer.counter = customer.interval - customer.counter;
	}
	if (customer.frame >= customer.duration)
	{
		customer.frame = 0;
	}
	if (customer.shopping_cart)
	{
		if (customer.leaving_store)
		{
			customer.source.top = 48 * 3;
		}
		else
		{
			customer.source.top = 48 * 2;
		}
	}
	else
	{
		if (customer.leaving_store)
		{
			customer.source.top = 48 * 1;
		}
		else
		{
			customer.source.top = 48 * 0;
		}
	}

	customer.source.left = 48 * customer.frame;
	customer.sprite.setPosition(customer.pos);
	customer.sprite.setTextureRect(customer.source);
}
void DrawCustomer(sf::RenderTexture& window, Customer& customer)
{
	if (customer.delay_counter >= customer.delay)
	{
		window.draw(customer.sprite);
	}
}
