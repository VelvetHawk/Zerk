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
 * NOTE: If they leave the original area without breath, they do not get the achievement
 *
 * Achievement unlocked!
 * - You unlocked an achievement!
 *
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
	delete scene_objects;
	delete scene_items;
	delete scene_characters;
	delete player;
	delete scene_locations;
}

/**
 * @brief
 * @return
 */
void Scene::start()
{
	// Start at fishing spot
	current_location = &(*scene_locations)["The Fishing Spot"];

	/* Movement */
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
	(*scene_locations)["By the Car"].set_adjacency('N', &(*scene_locations)["The Fishing Spot"]);
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
	// Outer Woodland (N) || Inner Woodland (W)
	(*scene_locations)["Outer Woodland (N)"].set_adjacency('S', &(*scene_locations)["Inner Woodland (W)"]);
	(*scene_locations)["Inner Woodland (W)"].set_adjacency('N', &(*scene_locations)["Outer Woodland (N)"]);
	// Outer Woodland (NE) || Inner Woodland (E)
	(*scene_locations)["Outer Woodland (NE)"].set_adjacency('S', &(*scene_locations)["Inner Woodland (E)"]);
	(*scene_locations)["Inner Woodland (E)"].set_adjacency('N', &(*scene_locations)["Outer Woodland (NE)"]);
	// Inner Woodland (W) <--> Inner Woodland (E)
	(*scene_locations)["Inner Woodland (W)"].set_adjacency('E', &(*scene_locations)["Inner Woodland (E)"]);
	(*scene_locations)["Inner Woodland (E)"].set_adjacency('W', &(*scene_locations)["Inner Woodland (W)"]);
	// Inner Woodland (W), Inner Woodland (E) | Junction
	(*scene_locations)["Inner Woodland (W)"].set_adjacency('S', &(*scene_locations)["Junction"]);
	(*scene_locations)["Inner Woodland (E)"].set_adjacency('S', &(*scene_locations)["Junction"]);
	// Junction | Small Grove
	(*scene_locations)["Junction"].set_adjacency('N', &(*scene_locations)["Small Grove"]);
	// Strange Trees <--> Small Grove
	(*scene_locations)["Strange Trees"].set_adjacency('E', &(*scene_locations)["Small Grove"]);
	(*scene_locations)["Small Grove"].set_adjacency('W', &(*scene_locations)["Strange Trees"]);
	// Strange Trees, Junction, Clear Pond | Old Path
	(*scene_locations)["Strange Trees"].set_adjacency('S', &(*scene_locations)["Old Path"]);
	(*scene_locations)["Junction"].set_adjacency('S', &(*scene_locations)["Old Path"]);
	(*scene_locations)["Clear Pond"].set_adjacency('S', &(*scene_locations)["Old Path"]);
	// Old Path | Clearing
	(*scene_locations)["Old Path"].set_adjacency('E', &(*scene_locations)["Strange Trees"]);
	(*scene_locations)["Old Path"].set_adjacency('N', &(*scene_locations)["Clearing"]);
	(*scene_locations)["Old Path"].set_adjacency('S', &(*scene_locations)["Clearing"]);
	(*scene_locations)["Old Path"].set_adjacency('W', &(*scene_locations)["Clearing"]);
	// Clearing |Small Burrow
	(*scene_locations)["Clearing"].set_adjacency('E', &(*scene_locations)["Small Burrow"]);
	(*scene_locations)["Clearing"].set_adjacency('N', &(*scene_locations)["Small Burrow"]);
	(*scene_locations)["Clearing"].set_adjacency('S', &(*scene_locations)["Small Burrow"]);
	(*scene_locations)["Clearing"].set_adjacency('W', &(*scene_locations)["Small Burrow"]);
	// Small Burrow | Inner Woodland (W), Inner Woodland (E)
	(*scene_locations)["Small Burrow"].set_adjacency('E', &(*scene_locations)["Inner Woodland (W)"]);
	(*scene_locations)["Small Burrow"].set_adjacency('N', &(*scene_locations)["Inner Woodland (E)"]);
	(*scene_locations)["Small Burrow"].set_adjacency('S', &(*scene_locations)["Inner Woodland (E)"]);
	(*scene_locations)["Small Burrow"].set_adjacency('W', &(*scene_locations)["Inner Woodland (W)"]);

	/* Objects */
	(*scene_locations)["The Fishing Spot"].add_object(&(*scene_objects)["Stool"]);
	(*scene_locations)["Small Burrow"].add_object(&(*scene_objects)["Burrow"]);
	(*scene_locations)["Small Grove"].add_object(&(*scene_objects)["Tracks"]);

	/* Items in Objects */
	(*scene_objects)["Burrow"].add_item(&(*scene_items)["Car Keys"]);

	/* Items at locations */
	// Fishing Spot
	(*scene_locations)["The Fishing Spot"].add_item(&(*scene_items)["Fishing Rod"]);
	(*scene_locations)["The Fishing Spot"].add_item(&(*scene_items)["Grandad's Fishing Rod"]);

	/* Characters */
	// The Fishing Spot
	(*scene_locations)["The Fishing Spot"].add_character(&(*scene_characters)["Grandad"]);
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
