#ifndef SCENE_H
#define SCENE_H

#include <QMap>
#include <QString>

#include "item.h"
#include "location.h"
#include "object.h"
#include "person.h"
#include "player.h"

class Scene
{
	public:
		// Variables
		QMap<QString, Object> *scene_objects;
		QMap<QString, Item> *scene_items;
		QMap<QString, Character> *scene_characters;
		Player *player;
		QMap<QString, Location> *scene_locations;
		// Constructors/destructors
		Scene();
		~Scene();
		// Functions
		void start();
		QString go(const char direction);
		QString location_string();
		Location* get_current_location();

	private:
		Location *current_location;
};

#endif // SCENE_H
