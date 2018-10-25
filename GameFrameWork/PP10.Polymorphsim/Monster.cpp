#include "Monster.h"
#include "TextureManager.h"

void Monster::drawFrame(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void Monster::Update()
{
	if (m_x> 640 || m_x< 0)
	{
		dire *= -1;
	}
	m_x += dire;
	

	m_currentFrame = int((SDL_GetTicks() / 100) % 4);
}

void Monster::velocity(int velocity)
{
	this->dire = velocity;
}
