#include "collisionManager.h"

CollisionManager::CollisionManager(const entityIterator& start_pos, const entityIterator& end_pos):
	_start_pos{start_pos},
	_end_pos{end_pos}
	{}
	
void CollisionManager::collisionHandler()
{
	for(auto iterator1 = _start_pos; iterator1 != prev(_end_pos); iterator1++)
	{
		for(auto iterator2 = next(iterator1); iterator2 != _end_pos; iterator2++)
		{
			if(collision(*iterator2, *iterator1))
			{
				(*iterator2)->collide(*iterator1);
				(*iterator1)->collide(*iterator2);
			}
		}
	}
}
	
bool CollisionManager::collision(shared_ptr<Entity> obj1, shared_ptr<Entity> obj2) const
{
	std::list<Vector2f> obj1_coords = obj1->hitboxPoints();
	std::list<Vector2f> obj2_coords = obj2->hitboxPoints();
	std::list<Vector2f> obj1_normalCoords = normalCoords(obj1_coords);
	std::list<Vector2f> obj2_normalCoords = normalCoords(obj2_coords);
	
	for(auto obj1_normal : obj1_normalCoords)
	{
		auto split = maxProjection(obj1_coords, obj1_normal) < minProjection(obj2_coords, obj1_normal) || maxProjection(obj2_coords, obj1_normal) < minProjection(obj1_coords, obj1_normal);
		if(split)
		{
			return false;
		}
	}
	
	for(auto obj2_normal : obj2_normalCoords)
	{
		auto split = maxProjection(obj1_coords, obj2_normal) < minProjection(obj2_coords, obj2_normal) || maxProjection(obj2_coords, obj2_normal) < minProjection(obj1_coords, obj2_normal);
		if(split)
		{
			return false;			
		}
	}
	
	return true;
}

list<Vector2f> CollisionManager::normalCoords(const list<Vector2f>& perimiterVals) const
{
	list<Vector2f> normalCoords;
	for(auto iterator = begin(perimiterVals); iterator != prev(end(perimiterVals)); iterator++)
	{
		Vector2f tempCoords(-next(iterator)->_y + iterator->_y, next(iterator)->_x - iterator->_x);
		normalCoords.push_back(tempCoords.unitVector());
	}
	
	Vector2f tempCoords(-(begin(perimiterVals))->_y + prev(end(perimiterVals))->_y, begin(perimiterVals)->_x - prev(end(perimiterVals))->_x);
	normalCoords.push_back(tempCoords.unitVector());
	
	return normalCoords;
}

float CollisionManager::maxProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const
{
	auto max = 0.f;
	for(const auto& value : perimeterVals)
	{
		auto tempMax = value * obj_normal;
		if(tempMax > max)
		{
			max = tempMax;
		}
	}
	
	return max;
}

float CollisionManager::minProjection(const list<Vector2f>& perimeterVals, const Vector2f& obj_normal) const
{
	auto min = numeric_limits<float>::max();
	for(const auto& value : perimeterVals)
	{
		auto tempMin = value * obj_normal;
		if(tempMin < min)
		{
			min = tempMin;
		}
	}
	
	return min;
}