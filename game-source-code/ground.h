#ifndef GROUND_H
#define GROUND_H

#include "entityList.h"
#include "movingEntity.h"
#include "vector2f.h"
#include <memory>
#include <ctime>
#include <cmath>

using std::shared_ptr;
using std::make_shared;

class Ground: public MovingEntity
{
public:
	Ground();
	~Ground(){};
	void setPosition(float x, float y);
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
protected:
	float positionGeneration(float positionBounds) const;
	
private:
	static const auto _playerHeight = 32;
	static const auto _playerWidth = 32;
	static constexpr const auto _playerSpeed = 50.0;
};

#endif