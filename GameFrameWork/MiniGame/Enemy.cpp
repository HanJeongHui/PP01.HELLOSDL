#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"

Enemy::Enemy(const LoaderParams* pParams) :SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{

	Firepos = m_position;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	if (m_position.getY() < 100) {
		m_velocity.setY(m_currentFrame);
	}
	else if (m_position.getY() > 430) {
		m_velocity.setY(-m_currentFrame);
	}
	/*if (m_position.getX() > 500) {
		m_velocity.setX(-m_currentFrame);
	}
	else if (m_position.getX() < 640) {
		m_velocity.setX(m_currentFrame);
	}*/
	SDLGameObject::update();


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