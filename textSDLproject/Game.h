#ifndef __Game__
#define __Game__

#include "SDL.h"
#undef main
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

#define g_screenWidthX 1000
#define g_screenBreadthY 1000

//Global variable
 static int gameTurn = 0;

class Game
{
public:

	//instance function to make this class a singleton
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//function to return SDL_Renderer object
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	//function that allows access to state machine
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	bool init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);

	bool running() { return m_bRunning; }

	void handleEvents();
	void update();
	void render();
	void clean();

	void quit() { m_bRunning = false; }
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//GameObject array
	std::vector<GameObject*> m_gameObjects;

	int m_currentFrame;

	bool m_bRunning;

	//constructor is now private
	Game()  {}
	~Game() {}

	//s_pInstance member variable
	static Game* s_pInstance;

	//add an object of our GameStateMachine
	GameStateMachine* m_pGameStateMachine;



};

typedef Game TheGame;
#endif // __Game__
