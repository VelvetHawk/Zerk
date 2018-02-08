#ifndef SCENE_H
#define SCENE_H

#include "item.h"
#include "location.h"
#include "object.h"
#include "person.h"
#include "player.h"

class Scene
{
	public:
		Scene();
		~Scene();
		Object scene_objects[];
		Item scene_items[];
		Person scene_characters[];
		Player player;
		Location scene_locations[];


};

#endif // SCENE_H
