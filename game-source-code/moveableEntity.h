#ifndef MOVEABLE_ENTITY_H
#define MOVEABLE_ENTITY_H

class MoveableEntity
{
public:
	virtual void move(float changeInTime) = 0;
};

#endif