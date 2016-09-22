#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

/**
* EntityList strongly typed enum class - used to enumerate list of game entities.
* For example used as a key within the CollisionManager class.
*/
enum class EntityList
{
	Player,
	Ground,
	Enemy,
	TunnelDigger,
	Harpoon,
	Rock,
	Num_Lives,
};

#endif