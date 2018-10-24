#include "Player.h"

void Player::load(int x, int y, int width, int height,std::string textureID)
{
	//GameObject::load(x, y, width, height, textureID); 부모한테 책임 넘김
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 1;
	m_currentFrame = 1;
}

void Player::draw(SDL_Renderer* pRenderer)
{
	//GameObject::draw(pRenderer);
	// 이 코드가 의미가 있을까? 이코드가 없었다면, 자동으로 부모 호출?? 
	TheTextureManager::Instance()->drawFrame(m_textureID,
		m_x, m_y, m_width, m_height,
		m_currentRow, m_currentFrame, pRenderer);
}

void Player::update()
{
	m_x -= 1;
}