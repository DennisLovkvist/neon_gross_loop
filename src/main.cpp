/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include "world.h"
#include <SFML/Audio.hpp>


int main()
{

	sf::RenderWindow window(sf::VideoMode(480,320), "Neon Gross", sf::Style::Close);

	sf::Clock clock;
	float dt = 1.f / 30.f;
	float accumulator = 0.f;

	World* world = new	World();

	LoadTextures(*world);

	SetupWorld(*world);

	sf::Shader shader;

	shader.loadFromFile("content/shaders/distortion.frag", sf::Shader::Fragment);

	sf::SoundBuffer buffer_rain;
	buffer_rain.loadFromFile("content/sound/rain_loop.ogg");
	sf::SoundBuffer buffer_music;
	buffer_music.loadFromFile("content/sound/music.ogg");

	sf::Sound sound_rain;
	sound_rain.setLoop(true);
	sound_rain.setBuffer(buffer_rain);
	sound_rain.play();

	sf::Sound sound_music;
	sound_music.setLoop(true);
	sound_music.setBuffer(buffer_music);
	sound_music.setVolume(10);
	sound_music.play();


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if(event.type == sf::Event::KeyPressed)
			{
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
			}
		}
		while (accumulator >= dt)
		{

			UpdateWorld(*world, dt);

			accumulator -= dt;
		}


		accumulator += clock.getElapsedTime().asSeconds();

		clock.restart();

			DrawWorld(window, shader, *world);
			window.display();

	}

	return 0;
}
