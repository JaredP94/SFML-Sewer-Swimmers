#ifndef ENTITY_H
#define ENTITY_H

#include "characterEntity.h"
#include "entityList.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

class Entity
{
public:
	Entity(EntityList entityKey, Vector2f position);
	CharacterEntity character() const;
	static void setMapBounds(const Vector2f& maxBounds);
	static Vector2f getMapBounds();
	Vector2f getPosition() const;
	EntityList getEntityKey() const;
	bool checkIfDestroyed() const;
	void destroy();
	virtual list<Vector2f> hitboxPoints() = 0;
	virtual void collide(const shared_ptr<Entity>& collider) = 0;
	void setPosition(float x, float y);
	void setCentre();
	
protected:
	void setPosition(const Vector2f& positionChange);
	
	
private:
	EntityList _entityKey;
	Vector2f _position;
	bool _destroyed = false;
	static Vector2f _positionBounds;
};

#endif