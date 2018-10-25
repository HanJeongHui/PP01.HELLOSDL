#include "Monster.h"
#include "TextureManager.h"

void Monster::drawFrame(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
}

void Monster::update()
{
	if (m_x> 200 || m_x < 0)
	{
		dire *= -1;
	}
	m_x += dire;
	

	m_currentFrame = int((SDL_GetTicks() / 100) % 4);
}

void Monster::velocity(int vel)
{
	dire = vel;
}

