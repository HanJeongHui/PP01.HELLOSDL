#pragma once
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "Missile.h"
const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new GameOverState());
	}
	for (int i = 2; i < m_gameObjects.size(); i++)
	{
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			SDL_RenderDrawLine(TheGame::Instance()->getRenderer(), 0, 0, 100, 100);
		}
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			//마사일하고 적 충돌시 코드
			SDL_RenderDrawLine(TheGame::Instance()->getRenderer(), 0, 0, 100, 100);
		}
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_SPACE))
	{
		if (SDL_GetTicks() > Nextfire)
		{
			GameObject* missile = new Missile(new LoaderParams(
				dynamic_cast<Player*>(m_gameObjects[0])->Firepos.getX(),
				dynamic_cast<Player*>(m_gameObjects[0])->Firepos.getY(),
				59, 31, "Missile"));
			m_gameObjects.push_back(missile);
			Nextfire = SDL_GetTicks() + Firerate;
		}

    }
	
    if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(new	PauseState());
	}
	
}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/cmissile54.png", "Missile", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	GameObject* enemy = new Enemy(new LoaderParams(500, 100, 128, 55, "helicopter2"));
	m_gameObjects.push_back(enemy);
	std::cout << "entering PlayState\n";
	return true;

}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}
bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}
