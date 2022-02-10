#include "Game.h"
#include"TextureManager.h"
#include "Player.h"
#include "Enemy.h"

#include <vector>

Game* Game::s_pInstance = 0;//instace for singleton class Game

std::vector<GameObject*> m_gameObjects;



//GameObject* m_go;
//GameObject* m_player;
//GameObject* m_enemy;


bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer,
					255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	std::cout << "init success\n";

	// to load
	if (!TextureManager::Instance()->load("assets/spritepng.png", "animate", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/point.png", "point", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/bagchalBoard.png", "board", m_pRenderer))
	{
		return false;
	}


	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,
		"animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,
		"animate")));




	m_bRunning = true; // everything inited successfully, start the main loop
	return true;


}
void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

	// loop through our objects and draw them
	/*for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/
	/*for (int x = 200;x <= 600;x+=200) {
		for (int y = 200;y <= 600;y += 200) {
			int SDL_RenderDrawPoint(TheGame::Instance()->getRenderer(), 100, 200);

		}
	}*/
	//TextureManager::Instance()->draw("board",150 , 150, 750, 750, m_pRenderer); //for board
	for (int x = 150;x <= 750;x += 150) {
		for (int y = 150;y <= 750;y += 150) {
			TextureManager::Instance()->draw("point", x, y, 100, 100, m_pRenderer);
		}
	}
	

	SDL_RenderPresent(m_pRenderer); // draw to the screen
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
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				std::cout<<event.motion.x<<std::endl ;
				std::cout << event.motion.y << std::endl;
				
				break;
			}
		default:
			break;
		}
	}
}
void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::draw() {
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}