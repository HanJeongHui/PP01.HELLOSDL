#pragma once
//#include <iostream>
#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "Hpbar.h"
#include "Missile.h"
#include "WinState.h"
const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;
void PlayState::update()
{



	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_SPACE))
	{
		if (SDL_GetTicks() > Nextfire)
		{
			if (dynamic_cast<SDLGameObject*>(m_gameObjects[1])->getvelocity().getX() > 0)
			{
				GameObject* missile = new Missile(
					new LoaderParams(
						dynamic_cast<Player*>(m_gameObjects[1])->Firepos.getX(),
						dynamic_cast<Player*>(m_gameObjects[1])->Firepos.getY(),
						59, 31, "Missile"), 0);
				m_gameObjects.push_back(missile);
				Nextfire = SDL_GetTicks() + Firerate;
			}
			else {
				GameObject* missile = new Missile(new LoaderParams(dynamic_cast<Player*>(m_gameObjects[1])->Firepos.getX(), dynamic_cast<Player*>(m_gameObjects[1])->Firepos.getY(), 59, 31, "Missile"), 1);
				m_gameObjects.push_back(missile);
				Nextfire = SDL_GetTicks() + Firerate;
			}
		}

	}
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new GameOverState());
	}
	
	for (int i = 3; i < m_gameObjects.size(); i++)
	{
		if (checkCollision(//미사일 아군
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(
				new GameOverState());
		}
	
	}
	for (int i = 3; i < m_gameObjects.size(); i++)
	{
		if (checkCollision(//미사일 적
			dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{

			hp -= 3;
			dynamic_cast<Hpbar*>(m_gameObjects[3])->Setwidth(hp);
			std::cout << hp << std::endl;
		}
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	
	
	
    if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(new	PauseState());
	}
	if (hp <= 0)
	{
		TheGame::Instance()->getStateMachine()->changeState(
			new WinState());
	}
	if(SDL_GetTicks() > Nextfire2)
	{
		GameObject* missile = new Missile(
			new LoaderParams(
				dynamic_cast<Enemy*>(m_gameObjects[2])->Firepos.getX()-80,
				dynamic_cast<Enemy*>(m_gameObjects[2])->Firepos.getY(),
				59, 31, "Missile"), 1);
		m_gameObjects.push_back(missile);
		Nextfire2 = SDL_GetTicks() + Firerate2;
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
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter",TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/russia.png", "russia", TheGame::Instance()->getRenderer()))
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
	if (!TheTextureManager::Instance()->load("assets/hpbar.png",
		"hpbar", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	GameObject* russia = new Background(new LoaderParams(0, 0, 640, 480, "russia"));
	m_gameObjects.push_back(russia);
	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	GameObject* enemy = new Enemy(new LoaderParams(500, 100, 128, 55, "helicopter2"));
	m_gameObjects.push_back(enemy);
	GameObject* hpbar = new Hpbar(new LoaderParams(80, 30, 500, 35, "hpbar"));
	m_gameObjects.push_back(hpbar);
	std::cout << "entering PlayState\n";
	hp = 500;
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
