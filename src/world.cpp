/*
 * Author: Dennis Lövkvist
 * Version: 1.0 (2020-05-01)
 */

#include <SFML/Graphics.hpp>
#include "world.h"
#include "rain.h"
#include "neon_sign.h"
#include "character_sillouettes.h"


void LoadTextures(World& world)
{
	world.tex_skyline.loadFromFile("content/textures/skyline.png");
	world.tex_neon_signs.loadFromFile("content/textures/neon_signs.png");
	world.tex_cobblestone.loadFromFile("content/textures/cobblestone2.png");
	world.tex_building.loadFromFile("content/textures/building.png");
	world.tex_background_character_0.loadFromFile("content/textures/bg_char_0.png");
	world.tex_background_character_1.loadFromFile("content/textures/bg_char_1.png");
	world.tex_customer_walk_cycles.loadFromFile("content/textures/customer_walkcycle.png");
	world.tex_drone.loadFromFile("content/textures/drone.png");
	world.tex_foreground_character.loadFromFile("content/textures/foreground_character.png");
	world.tex_glow.loadFromFile("content/textures/glow.png");
}
void SetupWorld(World& world)
{
	world.rt_pass_0.create(480, 320);
	world.rt_pass_1.create(480, 320);

	world.rt_surface_distortion_map.create(480, 320);

	world.sprite_building.setTexture(world.tex_building);

	world.sprite_cobblestone.setScale(1, -1);
	world.sprite_cobblestone.setPosition(0, 320);
	world.sprite_cobblestone.setColor(sf::Color(255, 255, 255, 255));

	world.sprite_skyline.setTexture(world.tex_skyline);
	world.sprite_skyline.setColor(sf::Color(4, 142, 200));
	world.sprite_skyline.setPosition(0,-4);

	world.shape_indoor_ambient_light_bg.setSize(sf::Vector2f(200, 64));
	world.shape_indoor_ambient_light_bg.setFillColor(sf::Color(215, 203, 156));
	world.shape_indoor_ambient_light_bg.setPosition(sf::Vector2f(160, 140));

	world.shape_indoor_ambient_light_fade[0].position = sf::Vector2f(186, 159);
	world.shape_indoor_ambient_light_fade[1].position = sf::Vector2f(251, 159);
	world.shape_indoor_ambient_light_fade[2].position = sf::Vector2f(251, 205);
	world.shape_indoor_ambient_light_fade[3].position = sf::Vector2f(186, 205);
	world.shape_indoor_ambient_light_fade[0].color = sf::Color(215, 203, 156, 0);
	world.shape_indoor_ambient_light_fade[1].color = sf::Color(215, 203, 156, 255);
	world.shape_indoor_ambient_light_fade[2].color = sf::Color(215, 203, 156, 255);
	world.shape_indoor_ambient_light_fade[3].color = sf::Color(215, 203, 156, 0);

	world.shape_indoor_ambient_light_fg[0].position = sf::Vector2f(251, 159);
	world.shape_indoor_ambient_light_fg[1].position = sf::Vector2f(291, 159);
	world.shape_indoor_ambient_light_fg[2].position = sf::Vector2f(291, 205);
	world.shape_indoor_ambient_light_fg[3].position = sf::Vector2f(251, 205);
	world.shape_indoor_ambient_light_fg[0].color = sf::Color(215, 203, 156, 255);
	world.shape_indoor_ambient_light_fg[1].color = sf::Color(215, 203, 156, 255);
	world.shape_indoor_ambient_light_fg[2].color = sf::Color(215, 203, 156, 255);
	world.shape_indoor_ambient_light_fg[3].color = sf::Color(215, 203, 156, 255);

	world.ground[0].position = sf::Vector2f(0, 190);
	world.ground[1].position = sf::Vector2f(480, 190);
	world.ground[2].position = sf::Vector2f(480, 320);
	world.ground[3].position = sf::Vector2f(0, 320);
	world.ground[0].color = sf::Color(51, 51, 51);
	world.ground[1].color = sf::Color(51, 51, 51);
	world.ground[2].color = sf::Color(37, 53, 64);
	world.ground[3].color = sf::Color(37, 53, 64);

	world.ground2[0].position = sf::Vector2f(0, 160);
	world.ground2[1].position = sf::Vector2f(480, 160);
	world.ground2[2].position = sf::Vector2f(480, 320);
	world.ground2[3].position = sf::Vector2f(0, 320);
	world.ground2[0].color = sf::Color(0, 0, 0, 255);
	world.ground2[1].color = sf::Color(0, 0, 0, 255);
	world.ground2[2].color = sf::Color(0, 204/3, 255/3, 100);
	world.ground2[3].color = sf::Color(0, 204/3, 255/3, 100);

	world.shape_sky[0].position = sf::Vector2f(0, 0);
	world.shape_sky[1].position = sf::Vector2f(480, 0);
	world.shape_sky[2].position = sf::Vector2f(480, 185);
	world.shape_sky[3].position = sf::Vector2f(0, 185);
	world.shape_sky[0].color = sf::Color(0, 0, 0);
	world.shape_sky[1].color = sf::Color(0, 0, 0);
	world.shape_sky[2].color = sf::Color(0, 129, 191);
	world.shape_sky[3].color = sf::Color(0, 129, 191);


	world.neon_sign_right.sprite.setPosition(sf::Vector2f(248, 8));
	world.neon_sign_left.sprite.setPosition(sf::Vector2f(72, 0));
	world.neon_sign_left.sprite.setTexture(world.tex_neon_signs);
	world.neon_sign_right.sprite.setTexture(world.tex_neon_signs);
	world.neon_sign_right.layers[0].top = 96;
	world.neon_sign_right.layers[1].top = 96;
	world.neon_sign_right.layers[2].top = 96;




	world.sprite_world_reflection.setTexture(world.rt_pass_0.getTexture());
	world.sprite_world_reflection.setScale(1, -0.5);
	world.sprite_world_reflection.setPosition(0, 320 / 2);

	world.sprite_building_reflection.setTexture(world.rt_pass_1.getTexture());
	world.sprite_building_reflection.setPosition(0, 0);
	world.sprite_building_reflection.setColor(sf::Color(255, 255, 255, 150));

	world.sprite_building_real.setTexture(world.rt_pass_0.getTexture());
	world.sprite_building_real.setScale(1, -1);
	world.sprite_building_real.setPosition(0, 320);

	world.sprite_cobblestone.setTexture(world.tex_cobblestone);
	world.sprite_cobblestone.setScale(1, -1);
	world.sprite_cobblestone.setColor(sf::Color(255, 255, 255, 255));
	world.sprite_cobblestone.setPosition(0, 320);


	SetUpRain(world.rain);
	ConfigureRain(world.rain);
	for (size_t i = 0; i < RAIN_DROP_COUNT; i++)
	{
		SpawnRainDrop(world.rain, i);
	}

	ConfigureCharacterSillouette(world.character_sillouette);
	world.character_sillouette.sprite[0].setTexture(world.tex_background_character_0);
	world.character_sillouette.sprite[1].setTexture(world.tex_background_character_1);


	world.customer_entering.sprite.setTexture(world.tex_customer_walk_cycles);
	world.customer_entering.sprite.setTextureRect(world.customer_entering.source);
	world.customer_entering.leaving_store = false;


	world.customer_leaving.sprite.setTexture(world.tex_customer_walk_cycles);
	world.customer_leaving.sprite.setTextureRect(world.customer_leaving.source);
	world.customer_leaving.leaving_store = true;

	ConfigureDrone(world.drone, world.tex_drone);

	ConfigureForegroundCharacter(world.foreground_character, world.tex_foreground_character);

	world.sprite_glow.setTexture(world.tex_glow);

}
void UpdateWorld(World& world, float dt)
{
	UpdateRain(world.rain, dt);
	UpdateCharacterSillouette(world.character_sillouette, dt);
	UpdateCustomer(world.customer_entering, dt);
	UpdateCustomer(world.customer_leaving, dt);
	UpdateDrone(world.drone, dt);
	UpdateForegroundCharacter(world.foreground_character, dt);
	UpdateNeonSign(world.neon_sign_left);
	UpdateNeonSign(world.neon_sign_right);
}
void DrawSurfaceDistortionMap(World& world)
{
	world.rt_surface_distortion_map.clear(sf::Color::Black);

	world.sprite_cobblestone.setScale(1, -1);
	world.sprite_cobblestone.setPosition(0, 320);
	world.sprite_cobblestone.setColor(sf::Color(255, 255, 255, 255));

	world.rt_surface_distortion_map.draw(world.sprite_cobblestone);
	DrawSurfaceRipple(world.rt_surface_distortion_map, world.rain);
}
void RenderPass0(World& world)
{

	world.rt_pass_0.clear(sf::Color::Transparent);

	world.rt_pass_0.draw(world.shape_sky, 4, sf::Quads);

	world.rt_pass_0.draw(world.sprite_skyline);
	world.rt_pass_0.draw(world.shape_indoor_ambient_light_bg);

	DrawCharacterSillouette(world.rt_pass_0, world.character_sillouette);


	world.sprite_building.setTextureRect(sf::IntRect(0, 0, 480, 320));
	world.sprite_building.setPosition(0, -32);
	world.rt_pass_0.draw(world.sprite_building);

	DrawCustomer(world.rt_pass_0, world.customer_entering);
	DrawCustomer(world.rt_pass_0, world.customer_leaving);

	world.rt_pass_0.draw(world.shape_indoor_ambient_light_fade, 4, sf::Quads);
	world.rt_pass_0.draw(world.shape_indoor_ambient_light_fg, 4, sf::Quads);

	world.sprite_building.setTextureRect(sf::IntRect(208, 186, 84, 62));
	world.sprite_building.setPosition(208, 186 - 32);
	world.rt_pass_0.draw(world.sprite_building);


	sf::Color c = world.neon_sign_left.color;
	c.a = world.neon_sign_left.flicker * 0.5f;
	world.sprite_glow.setPosition(-100, -85);
	world.sprite_glow.setColor(c);
	world.rt_pass_0.draw(world.sprite_glow);
	DrawNeonSign(world.rt_pass_0, world.neon_sign_left);

	c = world.neon_sign_right.color;
	c.a = world.neon_sign_right.flicker * 0.5f;
	world.sprite_glow.setPosition(60, -65);
	world.sprite_glow.setColor(c);
	world.rt_pass_0.draw(world.sprite_glow);
	DrawNeonSign(world.rt_pass_0, world.neon_sign_right);



}
void RenderPass1(World& world)
{
	world.rt_pass_1.draw(world.sprite_world_reflection);
}
void DrawWorld(sf::RenderWindow& window, sf::Shader& shader, World& world)
{
	DrawSurfaceDistortionMap(world);

	RenderPass0(world);

	RenderPass1(world);

	window.clear();
	window.draw(world.ground, 4, sf::Quads);
	shader.setUniform("texture", sf::Shader::CurrentTexture);
	shader.setUniform("hmap", world.rt_surface_distortion_map.getTexture());
	window.draw(world.sprite_building_reflection, &shader);


	DrawSurfaceRippleHighlight(window, world.rain);

	world.sprite_cobblestone.setScale(1, -1);
	world.sprite_cobblestone.setColor(sf::Color(255, 255, 255, 255));
	world.sprite_cobblestone.setPosition(0, 320);

	window.draw(world.sprite_cobblestone);

	window.draw(world.ground2, 4, sf::Quads);


	window.draw(world.sprite_building_real);

	DrawDrone(window, world.drone);

	DrawRainDrop(window,world.rain);



	window.draw(world.foreground_character.sprite);


}
