#include "Missile.h"
#include "InputHandler.h"

Missile::Missile(const LoaderParams* pParams,int dir) :
	SDLGameObject(pParams)
{
	if (dir == 0)
	{
		Vector2D dire = *TheInputHandler::Instance()->getMousePosition() - m_position;
		dire.normalize();
		dire *= 5;
		m_velocity.setX(dire.getX());
		m_velocity.setY(dire.getY());
	}
	else if(dir ==1)
	{
		m_velocity.setX(-10);
		m_velocity.setY(1);
	}
	else if(dir ==2){
		m_velocity.setX(-10);
		m_velocity.setY(-1);
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