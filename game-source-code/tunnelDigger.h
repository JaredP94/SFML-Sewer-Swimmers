#ifndef TUNNELDIGGER_H
#define TUNNELDIGGER_H

#include "movingEntity.h"
#include "vector2f.h"
#include <list>
#include <memory>

using std::list;
using std::shared_ptr;

class TunnelDigger: public MovingEntity
{
public:
	TunnelDigger(float x, float y);
	TunnelDigger(const Vector2f& position);
	~TunnelDigger();
	Vector2f positionChange();
	static int getDiggerQuantity() {return _digger_quantity;};
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	
private:
	static int _digger_quantity;
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static const auto _diggerHeight = 30;
	static const auto _diggerWidth = 30;
	static constexpr const auto _diggerSpeed = 50.0;
	Vector2f _speed;
};

#endif