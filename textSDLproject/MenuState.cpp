#include <string>
#include <iostream>
#include <map>
 #include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"
#include "AnimatedGraphic.h" 

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
} 



void MenuState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/start.png","playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png", "exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/title.png", "titletext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	GameObject* titleText = new AnimatedGraphic(new LoaderParams(100, 100, 458, 174, "titletext"), 1);
	GameObject* button1 = new MenuButton(new LoaderParams(100, 500, 247, 100, "playbutton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 600, 247, 100, "exitbutton"), s_exitFromMenu);
	m_gameObjects.push_back(titleText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}


bool MenuState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]-> clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()->clearFromTextureMap("exitbutton");
	
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{ 
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}