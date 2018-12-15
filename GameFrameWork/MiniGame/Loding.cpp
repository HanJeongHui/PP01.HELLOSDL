#include "Loding.h"
#include "InputHandler.h"

Loding::Loding(const LoaderParams* pParams) :SDLGameObject(pParams)
{

}

void Loding::draw()
{
	SDLGameObject::draw();
}

void Loding::update()
{

	m_velocity.setX(10);
	m_velocity.setY(0);

}

void Loding::clean()
{

}