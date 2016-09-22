#ifndef ENTITY_H
#define ENTITY_H

#include "characterEntity.h"
#include "entityList.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

/**
* Entity class - manages properties of all game Entity objects. This can be categorised as any iteractive object in the game.
* Entity objects contain a position and EntityList ID. These objects can collide with and be destroyed by other Entity objects.
*/
class Entity
{
public:
	/**
	* Constructor.
	* @param entityKey is a scoped enumeration containing the identity ID of the Entity. Used to correctly assign textures to Entity objects during rendering.
	* @param position is a Vector2f containing the coordinates of the Entity object position of creation.
	*/
	Entity(EntityList entityKey, Vector2f position);
	/**
	* Returns CharacterEntity information to correctly render Entity object.
	* @return CharacterEntity object containing entityKey and position.
	*/
	CharacterEntity character() const;
	/**
	* Static function. Sets map bounds whereby Entity objects are restricted to.
	* @param maxBounds is a const reference to a Vector2f containing the maxiumum bounds for the map. Bounds must be positive.
	*/
	static void setMapBounds(const Vector2f& maxBounds);
	/**
	* Static function. Returns the map bounds.
	* @return Vector2f containing map bounds.
	*/
	static Vector2f getMapBounds();
	/**
	* Returns coordinates of Entity object.
	* @return Vector2f containing Entity object coordinates.
	*/
	Vector2f getPosition() const;
	/**
	* Returns destroy status of Entity object.
	* @return bool containing status of Entity object's destroy property.
	*/
	bool checkIfDestroyed() const;
	/**
	* Sets destroy status of Entity object to be true.
	*/
	void destroy();
	/**
	* Returns inflate status of Entity object.
	* @return bool containing status of Entity object's inflate status.
	*/
	bool getInflateStatus();
	/**
	* Sets inflate status of Entity object to required state.
	* @param status is a bool which is what the Entity object's inflate status is set to.
	*/
	void setInflateStatus(bool status);
	/**
	* Returns deflate status of Entity object.
	* @return bool containing status of Entity object's deflate status.
	*/
	bool getDeflateStatus();
	/**
	* Sets deflate status of Entity object to required state.
	* @param status is a bool which is what the Entity object's deflate status is set to.
	*/
	void setDeflateStatus(bool status);
	/**
	* Returns time elapsed since timer was initialised.
	* @return float containing time elapsed since timer was initialised.
	*/
	float getTimeElapsed();
	/**
	* Resets timer to zero.
	*/
	void resetTimeElapsed();
	/*
	* Adds entered time to current time elapsed.
	* @param time is a float containing amount of time to be added to current elapsed time.
	*/
	void addTimeElapsed(float time);
	/**
	* Returns frozen status of Entity object.
	* @return bool containing status of Entity object's frozen status.
	*/
	bool getFrozenStatus();
	/**
	* Sets frozen status of Entity object to required state.
	* @param status is a bool which is what the Entity object's frozen status is set to.
	*/
	void setFrozenStatus(bool status);
	/**
	* Sets moving status of Entity object to required state.
	* @param status is a bool which is what the Entity object's moving status is set to.
	*/
	bool getMovingStatus();
	/**
	* Sets frozen status of Entity object to required state.
	* @param status is a bool which is what the Entity object's frozen status is set to.
	*/
	void setMovingStatus(bool status);
	/**
	* Pure virtual function. To be implemented by derived class.
	* @return list of Vector2f containing hitbox points of Entity object.
	*/
	virtual list<Vector2f> hitboxPoints() = 0;
	/**
	* Pure virtual function. To be implemented by derived class.
	* Allows for Entity object collissions to take place with specific entityKey based effects.
	* @param collider is a shared pointer to Entity object which the Enemy object collides with.
	*/
	virtual void collide(const shared_ptr<Entity>& collider) = 0;
	/**
	* Displaces the Entity object by entered distance.
	* @param x is a float contaning horizontal displacement value.
	* @param y is a float containing vertical displacement value.
	*/
	void setPosition(float x, float y);
	/**
	* Positions Entity object in the centre of the map.
	*/
	void setCentre();
	/**
	* Generates a random float for an Entity object based on the map bounds and the Entity object size.
	* @param positionBounds is a float containing axis limit for position generation.
	* @param entitySize is a float containing the axis size of the Entity object.
	* @return float containing random position on required axis.
	*/
	float positionGeneration(float positionBounds, float entitySize) const;
	
protected:
	/** 
	* Displaces the Entity object by entered distance.
	* @param positionChange is a const reference to a Vector2f containing the required displacement values.
	*/
	void setPosition(const Vector2f& positionChange);
	
private:
	EntityList _entityKey;
	Vector2f _position;
	bool _destroyed = false;
	bool _inflate = false;
	bool _deflate = false;
	bool _frozen = false;
	bool _moving = false;
	float _time_elapsed = 0.f;
	static Vector2f _positionBounds;
};

#endif