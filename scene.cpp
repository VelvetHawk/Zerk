#include "scene.h"
#include <iostream>

Scene::Scene(QMap<QString, Object> &objects, QMap<QString, Item> &items, QMap<QString, Character> &characters,
			 Player *player, QMap<QString, Location> &locations) :
	scene_objects(objects), scene_items(items), scene_characters(characters), player(player),
	scene_locations(locations)
{
	/*
		This might be unnecessary if the stack remains in scope the entire duration
		- Look into this
	*/
}

Scene::~Scene()
{
	delete player;

	std::cout << "Deleting scene" << std::endl;
}

/**
 * @brief
 * @return
 */
void Scene::start()
{
	/* Movement */
	// Start at fishing spot
	current_location = &scene_locations["The Fishing Spot"];
	// The Fishing Spot <--> By the Lake
	scene_locations["The Fishing Spot"].set_adjacency('E', &scene_locations["By the Lake"]);
	scene_locations["By the Lake"].set_adjacency('W', &scene_locations["The Fishing Spot"]);
	// By the Lake <--> Far Down the Lake
	scene_locations["By the Lake"].set_adjacency('E', &scene_locations["Far Down the Lake"]);
	scene_locations["Far Down the Lake"].set_adjacency('W', &scene_locations["By the Lake"]);
	// Far Down the Lake <--> Barely See the Fishing Spot
	scene_locations["Far Down the Lake"].set_adjacency('E', &scene_locations["Barely See the Fishing Spot"]);
	scene_locations["Barely See the Fishing Spot"].set_adjacency('W', &scene_locations["Far Down the Lake"]);
	// The Fishing Spot || By the Car
	scene_locations["The Fishing Spot"].set_adjacency('S', &scene_locations["By the Car"]);
	scene_locations["By the Car"].set_adjacency('N', &scene_locations["By the Lake"]);
	// By the Car <--> Outer Treeline
	scene_locations["By the Car"].set_adjacency('E', &scene_locations["Outer Treeline"]);
	scene_locations["Outer Treeline"].set_adjacency('W', &scene_locations["By the Car"]);
	// Outer Treeline || By the Lake
	scene_locations["By the Lake"].set_adjacency('S', &scene_locations["Outer Treeline"]);
	scene_locations["Outer Treeline"].set_adjacency('N', &scene_locations["By the Lake"]);
	// Outer Treeline || Outer Woodland (N)
	scene_locations["Outer Woodland (N)"].set_adjacency('N', &scene_locations["Outer Treeline"]);
	scene_locations["Outer Treeline"].set_adjacency('S', &scene_locations["Outer Woodland (N)"]);
	// Barely See the Fishing Spot || Outer Woodland (NE)
	scene_locations["Outer Woodland (NE)"].set_adjacency('N', &scene_locations["Barely See the Fishing Spot"]);
	scene_locations["Barely See the Fishing Spot"].set_adjacency('S', &scene_locations["Outer Woodland (NE)"]);

	/* Objects */
	scene_locations["The Fishing Spot"].add_object(&scene_objects["Stool"]);

	/* Items */
	scene_locations["The Fishing Spot"].add_item(&scene_items["Fishing Rod"]);
}

/**
 * @brief
 * @return
 */
QString Scene::go(const char direction)
{
	if (current_location->has_adjacency(direction))
	{
		current_location = current_location->get_adjacency(direction);
		return "";
	}
	return current_location->get_direction_text(direction);
}

/**
 * @brief
 * @return
 */
QString Scene::location_string()
{
	return "\"" + current_location->get_name() + "\"\n" + current_location->get_description() + "\n";
}

/**
 * @brief
 * @return
 */
Location* Scene::get_current_location()
{
	return current_location;
}
