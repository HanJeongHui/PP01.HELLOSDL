#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include "Monster.h"


class GameObject;
class Monster;

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
		if (!TheTextureManager::Instance()->load("assets/002.png", "mushroom", m_pRenderer))
		{
			return false;
		}
		//m_go.load(100, 100, 128, 82, "animate");
		//m_player.load(300, 300, 128, 82, "animate");
		SDL_SetRenderDrawColor(m_pRenderer, 50, 55, 55, 255);

		/*m_enemy = new Enemy();
		m_go = new GameObject();
		m_player = new Player();

		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(200, 200, 128, 82, "animate");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);*/
		F_monster = new Monster();
		S_monster = new Monster();
		F_monster->load(100, 50, 128, 165, "mushroom");
	    S_monster->load(100, 200, 128, 165, "mushroom");


		((Monster*)F_monster)->velocity(4);
		((Monster*)S_monster)->velocity(2);

		m_gameObjects.push_back(F_monster);
		m_gameObjects.push_back(S_monster);

		

	}
	else {
		return false;
	}
	return true;

}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour

	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update()
{
	//F_currentFrame = int(((SDL_GetTicks() / 100) % 10));
	//m_go.update();
	//m_player.update();
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}
void Game::clean()
{

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