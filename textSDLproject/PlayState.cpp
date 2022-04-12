#include <string>
#include <iostream>
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "Board.h"
#include <cmath>
#include "Game.h"

static int goatdead;
static int indexOfGoat = 4;

const std::string PlayState::s_playID = "PLAY";

//extern int gameTurn;


void PlayState::update()
{
	

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	
	
	dynamiccasting();
	
	int b = gameTurn % 2;

	switch (b) {

	case(0) :
		//std::cout << "Inside case 0" << std::endl;
		turnGoat();
		break;
	case(1) :
		//std::cout << "Inside case 1" << std::endl;

		turnTiger();
		break;
	default:
		std::cout << "wrong input" << std::endl;
		break;
	}
	
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}

	
}



bool PlayState::onEnter()
{   
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat5", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat6", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat7", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat8", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat9", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat10", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat11", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat12", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat13", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat14", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat15", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat16", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat17", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat18", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat19", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat20", TheGame::Instance()->getRenderer()))
	{
		return false;
	}



	if (!TheTextureManager::Instance()->load("assets/board.png", "board", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/pointMain.png", "point", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	
	GameObject* player1 = new Player(new LoaderParams(1050, 950, 128, 128, "goat1"));
	GameObject* player2 = new Player(new LoaderParams(1050, 950, 128, 128, "goat2"));
	GameObject* player3 = new Player(new LoaderParams(1050, 950, 128, 128, "goat2"));
	GameObject* player4 = new Player(new LoaderParams(1050, 950, 128, 128, "goat4"));
	GameObject* player5 = new Player(new LoaderParams(1050, 950, 128, 128, "goat5"));
	GameObject* player6 = new Player(new LoaderParams(1050, 950, 128, 128, "goat6"));
	GameObject* player7 = new Player(new LoaderParams(1050, 950, 128, 128, "goat7"));
	GameObject* player8 = new Player(new LoaderParams(1050, 950, 128, 128, "goat8"));
	GameObject* player9 = new Player(new LoaderParams(1050, 950, 128, 128, "goat9"));
	GameObject* player10 = new Player(new LoaderParams(1050, 950, 128, 128, "goat10"));
	GameObject* player11 = new Player(new LoaderParams(1050, 950, 128, 128, "goat11"));
	GameObject* player12 = new Player(new LoaderParams(1050, 950, 128, 128, "goat12"));
	GameObject* player13 = new Player(new LoaderParams(1050, 950, 128, 128, "goat13"));
	GameObject* player14 = new Player(new LoaderParams(1050, 950, 128, 128, "goat14"));
	GameObject* player15 = new Player(new LoaderParams(1050, 950, 128, 128, "goat15"));
	GameObject* player16 = new Player(new LoaderParams(1050, 950, 128, 128, "goat16"));
	GameObject* player17 = new Player(new LoaderParams(1050, 950, 128, 128, "goat17"));
	GameObject* player18 = new Player(new LoaderParams(1050, 950, 128, 128, "goat18"));
	GameObject* player19 = new Player(new LoaderParams(1050, 950, 128, 128, "goat19"));
	GameObject* player20 = new Player(new LoaderParams(1050, 950, 128, 128, "goat20"));


	GameObject* enemy1 = new Enemy(new LoaderParams(0, 0, 128, 128, "tiger1"));
	GameObject* enemy2 = new Enemy(new LoaderParams(800, 800, 128, 128, "tiger3"));
	GameObject* enemy3 = new Enemy(new LoaderParams(800, 0, 128, 128, "tiger2"));
	GameObject* enemy4 = new Enemy(new LoaderParams(0, 800, 128, 128, "tiger4"));


	//loading enemy(tiger)
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	m_gameObjects.push_back(enemy3);
	m_gameObjects.push_back(enemy4);

	//loading player(goat)
	m_gameObjects.push_back(player1);
	m_gameObjects.push_back(player2);
	m_gameObjects.push_back(player3);
	m_gameObjects.push_back(player4);
	m_gameObjects.push_back(player5);
	m_gameObjects.push_back(player6);
	m_gameObjects.push_back(player7);
	m_gameObjects.push_back(player8);
	m_gameObjects.push_back(player9);
	m_gameObjects.push_back(player10);
	m_gameObjects.push_back(player11);
	m_gameObjects.push_back(player12);
	m_gameObjects.push_back(player13);
	m_gameObjects.push_back(player14);
	m_gameObjects.push_back(player15);
	m_gameObjects.push_back(player16);
	m_gameObjects.push_back(player17);
	m_gameObjects.push_back(player18);
	m_gameObjects.push_back(player19);
	m_gameObjects.push_back(player20);
	
	std::cout << "entering PlayState\n";

	return true;
}

void PlayState::render()
{

	TheBoard::Instance()->render();

	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	

}

bool PlayState::onExit()
{
	//enemy1->clean();
	for (int i = 0;i < m_SDLgameObjects.size();i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_SDLgameObjects[i]->getm_textureID());
	}

	
	std::cout << "exiting PlayState\n";
	return true;
}

void PlayState::handleState(){
	
}


void PlayState::limitmoves(SDLGameObject* tiger)
{


	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();

	int x_pos = (((int)abs(tiger->getPosition().getX())) / 200) % 2;
	int y_pos = (((int)abs(tiger->getPosition().getY())) / 200) % 2;


	
	if ((x_pos == 1 && y_pos == 0) || (x_pos == 0 && y_pos == 1))  //Either of the condition must be satisfied to move diagonally
	{
		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		float c = (float)sqrt(abs(pow(a, 2) + pow(b, 2)));

		if (c == 200)
		{
			std::cout << "adjacent moment" << std::endl;
			if (dontoverlap(x, y))
			{
				tiger->handleInput();
				gameTurn++;
			}
		}
		else if (c == 400)
		{
			std::cout << "straight killer moment" << std::endl;
			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;

			if (dontoverlap(x, y)) {
				if (killer(midx, midy))
				{
					tiger->handleInput();
					goatdead++;

					if (goatdead == 5)
					{
						indexOfGoat = 4;
						TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
					}
					gameTurn++;
				}
			}
			else std::cout << "Invalid move" << std::endl;

		}
	}else {
		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		double e = sqrt(abs(pow(a, 2) + pow(b, 2)));
		double d = 200 * sqrt(2);
		std::cout << "diagonal moment"<<std::endl;


		if (e == 200 || e==(double)200*sqrt(2) )
		{
			
			if (dontoverlap(x,y)) {
				tiger->handleInput();
				gameTurn++;
			}
		}
		else if (e == 400 || e == 400 * sqrt(2))
		{
			std::cout << "diagonal killer moment" << std::endl;
			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;


			if (dontoverlap(x, y))
			{
				if (killer(midx, midy))
				{
					tiger->handleInput();
					goatdead++;
					if (goatdead == 5)
					{
						indexOfGoat = 4;
						TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
					}
					gameTurn++;
				}
			}
		}
			else std::cout << "Invalid move" << std::endl;

	}
}


bool PlayState::killer(int midx,int midy)
{
	
	int a;
	int b;
	
	for (int i = 4;i <= 23; i++) {
		std::cout << "inside killer"<<std::endl;
		a = m_SDLgameObjects[i]->getPosition().getX();
		b = m_SDLgameObjects[i]->getPosition().getY();

		if (a == midx && b == midy)
		{
			std::cout << "inside midpoint" << std::endl;
			TheTextureManager::Instance()->clearFromTextureMap(m_SDLgameObjects[i]->getm_textureID());

			m_SDLgameObjects.erase(m_SDLgameObjects.begin() + i);

			return true;
		}
	}
	return false;
}

void PlayState::dynamiccasting() 
{

	for (int i = 0; i <4; i++)
	{
		m_SDLgameObjectsTiger.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		m_SDLgameObjects.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		
	}
	for (int i = 4; i < m_gameObjects.size(); i++)
	{
		m_SDLgameObjectsGoat.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		m_SDLgameObjects.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		
	}

}


void PlayState::turnTiger()
{
	
	static int palo = 25;
	Vector2D* pMousePos2 = TheInputHandler::Instance()->getMousePosition();

	int  mouspos_X, mouspos_Y;
	//mouse position
	mouspos_X = TheBoard::Instance()->getR_X();
	mouspos_Y = TheBoard::Instance()->getR_Y();

	if (mouspos_X == m_SDLgameObjects[0]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[0]->getPosition().getY()) {
		palo = 1;
	}

	if (mouspos_X == m_SDLgameObjects[1]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[1]->getPosition().getY()) {
		palo = 2;
	}
	if (mouspos_X == m_SDLgameObjects[2]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[2]->getPosition().getY()) {
		palo = 3;
	}
	if (mouspos_X == m_SDLgameObjects[3]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[3]->getPosition().getY()) {
		palo = 4;
	}
	
	switch (palo) {

	case 1:
		
		limitmoves(m_SDLgameObjectsTiger[0]);
		break;
	case 2:
		limitmoves(m_SDLgameObjectsTiger[1]);
		break; 
	case 3:
		limitmoves(m_SDLgameObjectsTiger[2]);
		break;
	case 4:
		limitmoves(m_SDLgameObjectsTiger[3]);
		break;
	

	default:
		break;

	}


}

void PlayState::turnGoat() {

	int p=1050;
	int q=950;

	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

		p = (TheBoard::Instance()->filterX(pMousePos->getX()));
		q = (TheBoard::Instance()->filterY(pMousePos->getY()));

	}
    int correct = 0;
	
	for (int i = 0;i <m_gameObjects.size();i++) {

		if ( (m_SDLgameObjects[i]->getPosition().getX() != p) || (m_SDLgameObjects[i]->getPosition().getY() != q) ) {
			correct++;
			continue;
		}
	}

	if (correct == m_gameObjects.size()) {
		
		m_SDLgameObjects[indexOfGoat]->getPosition().setX(p);
		m_SDLgameObjects[indexOfGoat]->getPosition().setY(q);
		
		indexOfGoat++;
		correct = 0;
		gameTurn++;
	}	
	goatWinWin();
}

bool PlayState :: dontoverlap(int a,int b)
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{

		if ((m_SDLgameObjects[i]->getPosition().getX() == a) && (m_SDLgameObjects[i]->getPosition().getY() == b)) {
			return false;
		}
	}
	return true;
}

bool PlayState :: goatWin(int a)
 { 
	   int  right = 0;
	 std::cout << a << std::endl;
	
	 int x = m_SDLgameObjects[a]->getPosition().getX();
	 int y = m_SDLgameObjects[a]->getPosition().getY();


		 for (int i = 0; i < m_gameObjects.size(); i++)
		 {

			/*if (
				 (((x + 200) == m_SDLgameObjects[i]->getPosition().getX()) && (m_SDLgameObjects[i]->getPosition().getY() == a)) ||
				 (((x + 400) == m_SDLgameObjects[i]->getPosition().getX()) && (m_SDLgameObjects[i]->getPosition().getY() == a)) 



				 ) {

				 right++;
			 }
			 if (
				 (((y + 200) == m_SDLgameObjects[i]->getPosition().getY()) && (m_SDLgameObjects[i]->getPosition().getX() == a)) ||
				 (((y + 400) == m_SDLgameObjects[i]->getPosition().getY()) && (m_SDLgameObjects[i]->getPosition().getX() == a))

				 ) {

				 right++;
			 }
			 if (
				 ((x + 200) == m_SDLgameObjects[i]->getPosition().getX() && (y + 200) == m_SDLgameObjects[i]->getPosition().getY()) ||
				 ((x + 400) == m_SDLgameObjects[i]->getPosition().getX() && (y + 400) == m_SDLgameObjects[i]->getPosition().getY())

				 ) {

				 right++;
			 }*/

			 int x1 = m_SDLgameObjects[i]->getPosition().getX();
			 int y1 = m_SDLgameObjects[i]->getPosition().getY();

			 double xdistance = pow(abs(x1 - x), 2);
			 double ydistance= pow(abs(y1 - y), 2);
			 double distance = pow(xdistance+ydistance, 0.5);
			 //std::cout << "distance of  " << m_SDLgameObjects[i]->getm_textureID()<<"is" << distance<<std::endl;

			 if (distance == 200)
			 {
				 right++;
			 }
			 if (distance ==200*sqrt(2))
			 {
				 right++;
			 }
			 if (distance == 400)
			 {
				 right++;
			 }
			 if (distance == 400*sqrt(2))
			 {
				 right++;
			 }
		 }
		 if (right == 6) {
			 return true;
		 }
		 return false; 
 }
void PlayState::goatWinWin()
{
	if ( goatWin(0)&&goatWin(1)&&goatWin(2)&&goatWin(3))
	{
		gameTurn = 0;

		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
		

	}
}



	




