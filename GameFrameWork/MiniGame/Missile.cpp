#include "Missile.h"
#include "InputHandler.h"

Missile::Missile(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{

}

void Missile::draw()
{
	SDLGameObject::draw();
}

void Missile::update()
{
	m_velocity.setX(10);
	m_velocity.setY(0);
	SDLGameObject::update();
}

void Missile::clean()
{

}

void Missile::handleInput()
{

}