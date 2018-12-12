#include "WinState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "Background.h"
#include "InputHandler.h"

class GameObject;

const std::string WinState::s_winID = "WIN";
WinState* WinState::s_pInstance = 0;
void WinState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new MenuState());
}

void WinState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}
void WinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void WinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
bool WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/win.png",
		"win", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* button1 = new MenuButton(new
		LoaderParams(250, 250, 200, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new
		LoaderParams(250, 350, 200, 80, "resumebutton"), s_resumePlay);
	GameObject* win = new Background(new
		LoaderParams(210, 0, 275, 183, "win"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2); 
	m_gameObjects.push_back(win);
	std::cout << "entering WinState\n";
	return true;
}
bool WinState::onExit()
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
	std::cout << "exiting WinState\n";
	return true;
}