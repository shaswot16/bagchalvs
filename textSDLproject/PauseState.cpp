#include "PauseState.h"
#include "iostream"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
	TheGame::Instance()->getStateMachine()->changeState(new
		MenuState());
}
void PauseState::s_resumePlay()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/BUTTONCLICK.mp3");
	Mix_PlayMusic(gmusic, 0);
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
		"resumebutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/menu.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
	music = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/INTROSOUND.mp3");

	chunk = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/INTROSOUND.mp3");
	Mix_PlayMusic(music, -1);
	GameObject* button1 = new MenuButton(new LoaderParams(200, 100, 228, 80, "mainbutton"), s_pauseToMain);
	GameObject* button2 = new MenuButton(new LoaderParams(200, 300, 228, 80, "resumebutton"), s_resumePlay);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
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
	Mix_FreeMusic(music);
	Mix_FreeChunk(chunk);
	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}

