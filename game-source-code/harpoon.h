#ifndef HARPOON_H
#define HARPOON_H

#include "movingEntity.h"
#include "vector2f.h"
#include <memory>

using std::shared_ptr;

class Harpoon: public MovingEntity
{
public:
	Harpoon(const Vector2f& position, const Vector2f& velocity_unit_direction);
	~Harpoon();
	virtual void move(float changeInTime) override;
	virtual list<Vector2f> hitboxPoints() override;
	virtual void collide(const shared_ptr<Entity>& collider) override;
	static bool getHarpoonStatus() {return _harpoon_launched;};
	
private:
	float _elapsed_time_since_update = 1.0f;
	Vector2f _elapsed_distance = Vector2f(0, 0);
	static int _harpoon_launched;
	static constexpr const auto _harpoon_width = 32.f;
	static constexpr const auto _harpoon_height = 32.f;
	static constexpr const auto _harpoon_speed = 175.f;
	
};

#endif