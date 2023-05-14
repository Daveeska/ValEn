#include "Actor.hpp"

valen::Vec2 valen::Actor::getPos()
{
	return position;
}

valen::Vec2 valen::Actor::getSize()
{
	return size;
}

valen::Color valen::Actor::getColor()
{
	return color;
}

void valen::Actor::setPos(valen::Vec2 pos)
{
	this->position = pos;
}

void valen::Actor::setSize(valen::Vec2 size)
{
	this->size = size;
}

void valen::Actor::setColor(valen::Color color)
{
	this->color = color;
}

void valen::Actor::Init()
{
}

void valen::Actor::Update(float dt)
{
}

valen::Actor::Actor()
{
}

valen::Actor::~Actor()
{
}
