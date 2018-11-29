#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"

Enemy::Enemy(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	SDLGameObject::update();

	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}

void Enemy::clean()
{

}

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}