#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams)
{

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	Firepos = m_position;
	m_velocity.setX(0.00001);
	m_velocity.setY(0);
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	SDLGameObject::update();
}

void Player::clean()
{

}

void Player::handleInput()
{
//	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	//m_velocity = *target - m_position;
	//m_velocity /= 50;
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_velocity.setY(2);
	}
}