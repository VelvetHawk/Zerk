#include "scene.h"
#include "parser.h"
#include <QDebug>

/**
 * ########### ACHIEVEMENTS ##########
 *
 * Dirty Boy
 * - Complete the game covered in dirt.
 *
 * I'm in space! || I wanna be a spaceman! || Starve the trees!
 * - Complete the game while holding your breath.
 * NOTE: If they leave the original area, they do not get the achievement
 *
 * Achievement unlocked!
 * - You unlocked an achievement!
 *
 * Next tasks:
 * - Dialogue
 * - Menu system
 */



Scene::Scene() :
	scene_objects(new QMap<QString, Object>()), scene_items(new QMap<QString, Item>()),
	scene_characters(new QMap<QString, Character>()), player(new Player()),
	scene_locations(new QMap<QString, Location>())
{
	// Load data from files
	Parser::load("../Zerk/characters.xml", *scene_characters);
	Parser::load("../Zerk/items.xml", *scene_items);
	Parser::load("../Zerk/objects.xml", *scene_objects);
	Parser::load("../Zerk/locations.xml", *scene_locations);
}

Scene::~Scene()
{
	qDebug() << "Deleting scene_objects";
	delete scene_objects;
	qDebug() << "Scene_objects deleted";
	delete scene_items;
	qDebug() << "Deleting scene_items";
	delete scene_characters;
	qDebug() << "Deleting scene_characters";
	delete player;
	qDebug() << "Deleting player";
	delete scene_locations;
	qDebug() << "Deleting scene";
}

/**
 * @brief
 * @return
 */
void Scene::start()
{
	/* Movement */
	// Start at fishing spot
	current_location = &(*scene_locations)["The Fishing Spot"];
	// The Fishing Spot <--> By the Lake
	(*scene_locations)["The Fishing Spot"].set_adjacency('E', &(*scene_locations)["By the Lake"]);
	(*scene_locations)["By the Lake"].set_adjacency('W', &(*scene_locations)["The Fishing Spot"]);
	// By the Lake <--> Far Down the Lake
	(*scene_locations)["By the Lake"].set_adjacency('E', &(*scene_locations)["Far Down the Lake"]);
	(*scene_locations)["Far Down the Lake"].set_adjacency('W', &(*scene_locations)["By the Lake"]);
	// Far Down the Lake <--> Barely See the Fishing Spot
	(*scene_locations)["Far Down the Lake"].set_adjacency('E', &(*scene_locations)["Barely See the Fishing Spot"]);
	(*scene_locations)["Barely See the Fishing Spot"].set_adjacency('W', &(*scene_locations)["Far Down the Lake"]);
	// The Fishing Spot || By the Car
	(*scene_locations)["The Fishing Spot"].set_adjacency('S', &(*scene_locations)["By the Car"]);
	(*scene_locations)["By the Car"].set_adjacency('N', &(*scene_locations)["By the Lake"]);
	// By the Car <--> Outer Treeline
	(*scene_locations)["By the Car"].set_adjacency('E', &(*scene_locations)["Outer Treeline"]);
	(*scene_locations)["Outer Treeline"].set_adjacency('W', &(*scene_locations)["By the Car"]);
	// Outer Treeline || By the Lake
	(*scene_locations)["By the Lake"].set_adjacency('S', &(*scene_locations)["Outer Treeline"]);
	(*scene_locations)["Outer Treeline"].set_adjacency('N', &(*scene_locations)["By the Lake"]);
	// Outer Treeline || Outer Woodland (N)
	(*scene_locations)["Outer Woodland (N)"].set_adjacency('N', &(*scene_locations)["Outer Treeline"]);
	(*scene_locations)["Outer Treeline"].set_adjacency('S', &(*scene_locations)["Outer Woodland (N)"]);
	// Barely See the Fishing Spot || Outer Woodland (NE)
	(*scene_locations)["Outer Woodland (NE)"].set_adjacency('N', &(*scene_locations)["Barely See the Fishing Spot"]);
	(*scene_locations)["Barely See the Fishing Spot"].set_adjacency('S', &(*scene_locations)["Outer Woodland (NE)"]);

	/* Objects */
	(*scene_locations)["The Fishing Spot"].add_object(&(*scene_objects)["Stool"]);

	/* Items in Objects */
	(*scene_objects)["Stool"].add_item(&(*scene_items)["Car Keys"]);

	/* Items at locations */
	// Fishing Spot
	(*scene_locations)["The Fishing Spot"].add_item(&(*scene_items)["Fishing Rod"]);
	(*scene_locations)["The Fishing Spot"].add_item(&(*scene_items)["Grandad's Fishing Rod"]);

	/* Characters */
	// The Fishing Spot
	(*scene_locations)["The Fishing Spot"].add_character(&(*scene_characters)["Grandad"]);
	(*scene_locations)["The Fishing Spot"].add_character(&(*scene_characters)["Robert"]);
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
