#pragma once
#include <iostream>
#include "SDL.h"
#include "string.h"
#include "TextureManager.h"

class GameObject
{
public:
	virtual void load(int x, int y, int width, int height,	std::string textureID); //virtual 자식한테 책임을 넘김
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	//virtual void clean();
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};
