#include "scene.h"

Scene::Scene() :
	scene_objects(new Object[10]), scene_items(new Item[10]),
	scene_characters(new Character[10]), player(new Player), scene_locations(new Location[10])
{
	/*
		This might be unnecessary if the stack remains in scope the entire duration
		- Look into this
	*/
}

Scene::~Scene()
{
	delete[] scene_objects;
	delete[] scene_items;
	delete[] scene_characters;
	delete player;
	delete[] scene_locations;
}
