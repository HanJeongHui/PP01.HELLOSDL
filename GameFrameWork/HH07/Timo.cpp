#include "Timo.h"
#include "InputHandler.h"

Timo::Timo(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Timo::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Timo::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	//m_acceleration.setX(1);
	SDLGameObject::update();
}
void Timo::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		m_velocity.setX(20);
	}
}
void Timo::clean()
{
}