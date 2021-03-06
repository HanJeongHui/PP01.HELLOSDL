#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include <SDL_keycode.h>



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height,
			SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;
		// load 부분 대치   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

	
	}
	else {
		return false;
	}
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	// draw 부분 대치 
	TheTextureManager::Instance()->draw("animate", 100, 100, 128, 82,
		m_pRenderer);

	TheTextureManager::Instance()->drawFrame("animate", 100, 100,
		128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);

}
void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	//m_sourceRectangle.x = 128 * int((SDL_GetTicks() / 100 % 6));
	//SDL_Event event;
	//if (SDL_PollEvent(&event))
	//{
	//	switch (event.type)
	//	{
	//	case SDLK_LEFT:
	//		m_sourceRectangle.w -= 10;
	//		break;
	//	case SDLK_RIGHT:
	//		m_sourceRectangle.w += 10;
	//		break;
	//	case SDLK_UP:
	//		m_sourceRectangle.h += 10;
	//		break;
	//	case SDLK_DOWN:
	//		m_sourceRectangle.h -= 10;
	//		break;
	//	
	//	}
	//}
}
void Game::clean()
{
	SDL_Delay(4000);
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
