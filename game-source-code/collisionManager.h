#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "entityContainer.h"
#include "movingEntity.h"
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
using movingEntityIterator = vector<shared_ptr<MovingEntity>>::iterator;

/**
* CollisionManager class - manages all collision detection between Entity objects.
*/
class CollisionManager
{
public:
	/** 
	* Constructor. Creates CollisionManager object.
	* @param start_pos is a reference to an entityIterator for the start position of Entity objects which requrie collision checking.
	* @param end_pos is a reference to an entityIterator for the end position of Entity objects which requrie collision checking.
	* @param start_pos2 is a reference to a movingEntityIterator for the start position of MovingEntity objects which requrie collision checking.
	* @param end_pos2 is a reference to a movingEntityIterator for the end position of MovingEntity objects which requrie collision checking.
	*/
	CollisionManager(const entityIterator& start_pos, const entityIterator& end_pos, const movingEntityIterator& start_pos2, const movingEntityIterator& end_pos2);
	/**
	* Runs protocol to check all collisions of required objects.
	*/
	void CollisionHandler();
	
private:
	/**
	* Implementation of collision checking between two Entity objects.
	* @param obj1 is a pointer to the first Entity object required to check collisions.
	* @param obj2 is a pointer to the second Entity object required to check collisions.
	*/
	bool collision(shared_ptr<Entity> obj1, shared_ptr<Entity> obj2) const;
	/**
	* Creates the normals of the vector connecting between the entered points.
	* @param perimiterVals is a const list of Vector2f coordinates which connect each egde of the shape. Points are required to be entered in clockwise direction.
	* @return Vector2f list which contains the created normal vectors.
	*/
	std::list<Vector2f> normalCoords(const list<Vector2f>& perimiterVals) const;
	/**
	* Calculation of maximum projection of set of vectors onto that of a normal vector.
	* @param perimeterVals is a const list of Vector2f coordinates which connect each egde of the shape. Points are required to be entered in clockwise direction.
	* @param obj_normal is a Vector2f which contains the normal vector of the object.
	* @return float which stores magnitude of calculated maximum projection. Should be positive.
	*/
	float maxProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const;
	/**
	* Calculation of minimum projection of set of vectors onto that of a normal vector.
	* @param perimeterVals is a const list of Vector2f coordinates which connect each egde of the shape. Points are required to be entered in clockwise direction.
	* @param obj_normal is a Vector2f which contains the normal vector of the object.
	* @return float which stores magnitude of calculated minimum projection. Should be positive.
	*/
	float minProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const;
	entityIterator _start_pos;
	entityIterator _end_pos;
	movingEntityIterator _start_pos2;
	movingEntityIterator _end_pos2;
	
};

#endif