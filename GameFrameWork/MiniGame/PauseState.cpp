#include "PauseState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "Background.h"

class GameObject;

const std::string PauseState::s_pauseID = "PAUSE";
PauseState* PauseState::s_pInstance = 0;
void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new MenuState());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}
void PauseState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/pause.png",
		"pause", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton(new
		LoaderParams(500, 300, 200, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new
		LoaderParams(500, 500, 200, 80, "resumebutton"), s_resumePlay);
	GameObject* pause = new Background(new
		LoaderParams(490, 0, 225, 225, "pause"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);	
	m_gameObjects.push_back(pause);
	std::cout << "entering PauseState\n";
	return true;
}
bool PauseState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}