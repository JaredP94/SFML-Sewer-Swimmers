#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "entity.h"
#include "entityContainer.h"
#include "vector2f.h"
#include <list>
#include <limits>
#include <memory>
#include <cmath>
#include <vector>

using std::shared_ptr;
using std::list;
using std::begin;
using std::end;
using std::next;
using std::prev;
using std::numeric_limits;

class CollisionManager
{
public:
	CollisionManager(const entityIterator& start_pos, const entityIterator& end_pos, Vector2f player_pos);
	void collisionHandler();
	
private:
	bool collision(shared_ptr<Entity> obj1, shared_ptr<Entity> obj2) const;
	std::list<Vector2f> normalCoords(const list<Vector2f>& perimiterVals) const;
	float maxProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const;
	float minProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const;
	entityIterator _start_pos;
	entityIterator _end_pos;
	Vector2f _player_pos;
	
};

#endif