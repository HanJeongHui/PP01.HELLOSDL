#include "Missile.h"
#include "InputHandler.h"

Missile::Missile(const LoaderParams* pParams,int dir) :
	SDLGameObject(pParams)
{
	if (dir == 0)
	{
		m_velocity.setX(10);
		m_velocity.setY(0);
	}
	else {
		m_velocity.setX(-10);
		m_velocity.setY(0);
	}
}

void Missile::draw()
{
	SDLGameObject::draw();
}

void Missile::update()
{
	
	SDLGameObject::update();
}

void Missile::clean()
{

}

void Missile::handleInput()
{

}