#include "Enemy.h"
#include "InputHandler.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{   
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	HandleInput();
	//m_position.setX(m_position.getX() + 1);
	//m_position.setY(m_position.getY() + 1);

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}
void Enemy::HandleInput()
{
	Vector2D* vec = InputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
	if (InputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity += Vector2D(5.0f, 0.0f);
	}
}