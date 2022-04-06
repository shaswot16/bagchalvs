#include <string>
#include <iostream>
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "Board.h"
#include <cmath>
#include "Game.h"

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
	std::cout << "Game Turn" << b << std::endl;

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
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat15", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat16", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat17", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat18", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat19", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat20", TheGame::Instance()->getRenderer()))
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
	
	
	GameObject* player1 = new Player(new LoaderParams(1050, 00, 128, 128, "goat1"));
	GameObject* player2 = new Player(new LoaderParams(1050, 50, 128, 128, "goat2"));
	GameObject* player3 = new Player(new LoaderParams(1050, 100, 128, 128, "goat2"));
	GameObject* player4 = new Player(new LoaderParams(1050, 150, 128, 128, "goat4"));
	GameObject* player5 = new Player(new LoaderParams(1050, 200, 128, 128, "goat5"));
	GameObject* player6 = new Player(new LoaderParams(1050, 250, 128, 128, "goat6"));
	GameObject* player7 = new Player(new LoaderParams(1050, 300, 128, 128, "goat7"));
	GameObject* player8 = new Player(new LoaderParams(1050, 350, 128, 128, "goat8"));
	GameObject* player9 = new Player(new LoaderParams(1050, 400, 128, 128, "goat9"));
	GameObject* player10 = new Player(new LoaderParams(1050, 450, 128, 128, "goat10"));
	GameObject* player11 = new Player(new LoaderParams(1050, 500, 128, 128, "goat11"));
	GameObject* player12 = new Player(new LoaderParams(1050, 550, 128, 128, "goat12"));
	GameObject* player13 = new Player(new LoaderParams(1050, 600, 128, 128, "goat13"));
	GameObject* player14 = new Player(new LoaderParams(1050, 650, 128, 128, "goat14"));
	GameObject* player15 = new Player(new LoaderParams(1050, 700, 128, 128, "goat15"));
	GameObject* player16 = new Player(new LoaderParams(1050, 750, 128, 128, "goat16"));
	GameObject* player17 = new Player(new LoaderParams(1050, 800, 128, 128, "goat17"));
	GameObject* player18 = new Player(new LoaderParams(1050, 850, 128, 128, "goat18"));
	GameObject* player19 = new Player(new LoaderParams(1050, 900, 128, 128, "goat19"));
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



/*void PlayState::turnTiger(SDLGameObject* p1, SDLGameObject* p2, SDLGameObject* p3, SDLGameObject* p4, SDLGameObject* goat1, SDLGameObject* goat2
	, SDLGameObject* goat3, SDLGameObject* goat4, SDLGameObject* goat5, SDLGameObject* goat6,
	SDLGameObject* goat7, SDLGameObject* goat8, SDLGameObject* goat9, SDLGameObject* goat10, SDLGameObject* goat11, SDLGameObject* goat12, SDLGameObject* goat13, SDLGameObject* goat14, SDLGameObject* goat15, SDLGameObject* goat16,
	SDLGameObject* goat17, SDLGameObject* goat18, SDLGameObject* goat19, SDLGameObject* goat20)
{ 
	static int palo;
	Vector2D* pMousePos2 = TheInputHandler::Instance()->getMousePosition();
	

	/*
	if((pMousePos2->getX() < (goat1->getPosition().getX() + 128)
		&&( pMousePos2->getX() > goat1->getPosition().getX())
		&&( pMousePos2->getY() < (goat1->getPosition().getY() + 50))
			&& (pMousePos2->getY() > goat1->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT) ){
			
			palo=5;
		}


	}

	if ((pMousePos2->getX() < (goat2->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat2->getPosition().getX())
		&& (pMousePos2->getY() < (goat2->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat2->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			
			palo = 6;
		}


	}
	if ((pMousePos2->getX() < (goat3->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat3->getPosition().getX())
		&& (pMousePos2->getY() < (goat3->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat3->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 7;
		}


	}

	if ((pMousePos2->getX() < (goat4->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat4->getPosition().getX())
		&& (pMousePos2->getY() < (goat4->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat4->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 8;
		}


	}if ((pMousePos2->getX() < (goat5->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat5->getPosition().getX())
		&& (pMousePos2->getY() < (goat5->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat5->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 9;
		}


	}

	if ((pMousePos2->getX() < (goat6->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat6->getPosition().getX())
		&& (pMousePos2->getY() < (goat6->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat6->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 10;
		}


	}if ((pMousePos2->getX() < (goat7->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat7->getPosition().getX())
		&& (pMousePos2->getY() < (goat7->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat7->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 11;
		}


	}

	if ((pMousePos2->getX() < (goat8->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat8->getPosition().getX())
		&& (pMousePos2->getY() < (goat8->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat8->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 12;
		}


	}if ((pMousePos2->getX() < (goat9->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat9->getPosition().getX())
		&& (pMousePos2->getY() < (goat9->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat9->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 13;
		}


	}

	if ((pMousePos2->getX() < (goat10->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat10->getPosition().getX())
		&& (pMousePos2->getY() < (goat10->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat10->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 14;
		}


	}if ((pMousePos2->getX() < (goat11->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat11->getPosition().getX())
		&& (pMousePos2->getY() < (goat11->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat11->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 15;
		}


	}

	if ((pMousePos2->getX() < (goat12->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat12->getPosition().getX())
		&& (pMousePos2->getY() < (goat12->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat12->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 16;
		}


	}if ((pMousePos2->getX() < (goat13->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat13->getPosition().getX())
		&& (pMousePos2->getY() < (goat13->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat13->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 17;
		}


	}

	if ((pMousePos2->getX() < (goat14->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat14->getPosition().getX())
		&& (pMousePos2->getY() < (goat14->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat14->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 18;
		}


	}if ((pMousePos2->getX() < (goat15->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat15->getPosition().getX())
		&& (pMousePos2->getY() < (goat15->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat15->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 19;
		}


	}

	if ((pMousePos2->getX() < (goat16->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat16->getPosition().getX())
		&& (pMousePos2->getY() < (goat16->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat16->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 20;
		}


	}if ((pMousePos2->getX() < (goat17->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat17->getPosition().getX())
		&& (pMousePos2->getY() < (goat17->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat17->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 21;
		}


	}

	if ((pMousePos2->getX() < (goat18->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat18->getPosition().getX())
		&& (pMousePos2->getY() < (goat18->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat18->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 22;
		}


	}if ((pMousePos2->getX() < (goat19->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat19->getPosition().getX())
		&& (pMousePos2->getY() < (goat19->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat19->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 23;
		}


	}

	if ((pMousePos2->getX() < (goat20->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat20->getPosition().getX())
		&& (pMousePos2->getY() < (goat20->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat20->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 24;
		}


	}
	






	 int  mouspos_X, mouspos_Y;
	//mouse position
	 mouspos_X = TheBoard::Instance()->getR_X();
	 mouspos_Y = TheBoard::Instance()->getR_Y();
	  
	  
	  //position of p1 object
	int p1_X = p1->getPosition().getX();
	int p1_Y = p1->getPosition().getY();

	//position of p2 object
	int p2_X = p2->getPosition().getX();
	int p2_Y = p2->getPosition().getY();

	//position of p3 object
 	int p3_X = p3->getPosition().getX();
	int p3_Y = p3->getPosition().getY();

	//position of p4 object
	int p4_X = p4->getPosition().getX();
	int p4_Y = p4->getPosition().getY();
	
	
	
	if (mouspos_X == p1_X && mouspos_Y == p1_Y) {
		palo = 1;
	}
	
	if (mouspos_X == p2_X && mouspos_Y == p2_Y) {
		palo = 2;
	}

	if (mouspos_X == p3_X && mouspos_Y == p3_Y) {
		palo = 3;
	}

	if (mouspos_X == p4_X && mouspos_Y == p4_Y) {
		palo = 4;
	}
	
	int  mouspos_X, mouspos_Y;
	//mouse position
	mouspos_X = TheBoard::Instance()->getR_X();
	mouspos_Y = TheBoard::Instance()->getR_Y();

	for (int i = 0;i < m_SDLgameObjects.size();i++)
	{
		/*if (mouspos_X == m_SDLgameObjects[i]->getPosition().getX()
			&& mouspos_Y == m_SDLgameObjects[i]->getPosition().getY())
		{
			std::cout << m_SDLgameObjects[i]->getPosition().getX() << std::endl << m_SDLgameObjects[i]->getPosition().getY() << std::endl;
			palo = (i + 1);
		}
		else std::cout << "some thing is wrong";

		int x = m_SDLgameObjects[i]->getPosition().getX();
		int y = m_SDLgameObjects[i]->getPosition().getY();

		std::cout << x;
		std::cout << y;

		if (mouspos_X == x && mouspos_Y == y)
		{
			m_gameObjects[i]->handleInput();
		}
		else std::cout << "something is wrong";
		palo = (i + 1);
		std::cout << palo << std::endl;
	}
	



	switch (palo) {
	
	case 1:
		
		p1->handleInput();

		break;
	case 2:
		p2->handleInput();
		break;
	case 3:
		p3->handleInput();
		break;
	case 4:
		p4->handleInput();
		break;
	case 5:
		goat1->handleInput();
		break;
	case 6:
		goat2->handleInput();
		break;
	case 7:
		goat3->handleInput();
		break;
	case 8:
		goat4->handleInput();
		break;
	case 9:
		goat5->handleInput();
		break;
	case 10:
		goat6->handleInput();
		break;
	case 11:
		goat7->handleInput();
		break;
	case 12:
		goat8->handleInput();
		break;
	case 13:
		goat9->handleInput();
		break;
	case 14:
		goat10->handleInput();
		break;
	case 15:
		goat11->handleInput();
		break;
	case 16:
		goat12->handleInput();
		break;
	case 17:
		goat13->handleInput();
		break;
	case 18:
		goat14->handleInput();
		break;
	case 19:
		goat15->handleInput();
		break;
	case 20:
		goat16->handleInput();
		break;
	case 21:
		goat17->handleInput();
		break;
	case 22:
		goat18->handleInput();
		break;
	case 23:
		goat19->handleInput();
		break;
	case 24:
		goat20->handleInput();
		break;
	
	default:
		break;

	}


	
	
} */


void PlayState::limitmoves(SDLGameObject* tiger)
{


	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();

	int x_pos = (((int)abs(tiger->getPosition().getX())) / 200) % 2;
	int y_pos = (((int)abs(tiger->getPosition().getY())) / 200) % 2;


	
	if((x_pos==1 && y_pos==0) || (x_pos == 0 && y_pos == 1))
	{
		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		float c = (float)sqrt(abs(pow(a, 2) + pow(b, 2)));

		if (c == 200)
		{
			
			tiger->handleInput();
			gameTurn++;
		}
		else if (c == 400)
		{
			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;


			if (killer(midx, midy))
			{
				tiger->handleInput();
				gameTurn++;
			}
			else std::cout << "Invalid move" << std::endl;
		}
	}
		
	else {
		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		double e = sqrt(abs(pow(a, 2) + pow(b, 2)));
		double d = 200 * sqrt(2);
	   


		if (e == 200 || e==(double)200*sqrt(2) )
		{
			
			tiger->handleInput();
			gameTurn++;
		}
		else if (e == 400 || e==400*sqrt(2))
		{
			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;


			if (killer(midx, midy))
			{
				tiger->handleInput();
				gameTurn++;
			}
			else std::cout << "Invalid move" << std::endl;

	    }
	
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
	
	
	
	/*if ((pMousePos2->getX() < (m_SDLgameObjectsGoat[18]->getPosition().getX() + 128)
		&& (pMousePos2->getX() > m_SDLgameObjectsGoat[18]->getPosition().getX())
		&& (pMousePos2->getY() < (m_SDLgameObjectsGoat[18]->getPosition().getY() + 128))
		&& (pMousePos2->getY() > m_SDLgameObjectsGoat[18]->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {

			palo = 6;
		}
	}*/
	
	/*if ((pMousePos2->getX() < (goat2->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat2->getPosition().getX())
		&& (pMousePos2->getY() < (goat2->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat2->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {

			palo = 6;
		}


	}
	if ((pMousePos2->getX() < (goat3->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat3->getPosition().getX())
		&& (pMousePos2->getY() < (goat3->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat3->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 7;
		}


	}

	if ((pMousePos2->getX() < (goat4->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat4->getPosition().getX())
		&& (pMousePos2->getY() < (goat4->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat4->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 8;
		}


	}if ((pMousePos2->getX() < (goat5->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat5->getPosition().getX())
		&& (pMousePos2->getY() < (goat5->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat5->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 9;
		}


	}

	if ((pMousePos2->getX() < (goat6->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat6->getPosition().getX())
		&& (pMousePos2->getY() < (goat6->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat6->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 10;
		}


	}if ((pMousePos2->getX() < (goat7->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat7->getPosition().getX())
		&& (pMousePos2->getY() < (goat7->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat7->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 11;
		}


	}

	if ((pMousePos2->getX() < (goat8->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat8->getPosition().getX())
		&& (pMousePos2->getY() < (goat8->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat8->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 12;
		}


	}if ((pMousePos2->getX() < (goat9->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat9->getPosition().getX())
		&& (pMousePos2->getY() < (goat9->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat9->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 13;
		}


	}

	if ((pMousePos2->getX() < (goat10->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat10->getPosition().getX())
		&& (pMousePos2->getY() < (goat10->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat10->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 14;
		}


	}if ((pMousePos2->getX() < (goat11->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat11->getPosition().getX())
		&& (pMousePos2->getY() < (goat11->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat11->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 15;
		}


	}

	if ((pMousePos2->getX() < (goat12->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat12->getPosition().getX())
		&& (pMousePos2->getY() < (goat12->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat12->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 16;
		}


	}if ((pMousePos2->getX() < (goat13->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat13->getPosition().getX())
		&& (pMousePos2->getY() < (goat13->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat13->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 17;
		}


	}

	if ((pMousePos2->getX() < (goat14->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat14->getPosition().getX())
		&& (pMousePos2->getY() < (goat14->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat14->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 18;
		}


	}if ((pMousePos2->getX() < (goat15->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat15->getPosition().getX())
		&& (pMousePos2->getY() < (goat15->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat15->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 19;
		}


	}

	if ((pMousePos2->getX() < (goat16->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat16->getPosition().getX())
		&& (pMousePos2->getY() < (goat16->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat16->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 20;
		}


	}if ((pMousePos2->getX() < (goat17->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat17->getPosition().getX())
		&& (pMousePos2->getY() < (goat17->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat17->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 21;
		}


	}

	if ((pMousePos2->getX() < (goat18->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat18->getPosition().getX())
		&& (pMousePos2->getY() < (goat18->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat18->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 22;
		}


	}if ((pMousePos2->getX() < (goat19->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat19->getPosition().getX())
		&& (pMousePos2->getY() < (goat19->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat19->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 23;
		}


	}

	if ((pMousePos2->getX() < (goat20->getPosition().getX() + 128)
		&& (pMousePos2->getX() > goat20->getPosition().getX())
		&& (pMousePos2->getY() < (goat20->getPosition().getY() + 40))
		&& (pMousePos2->getY() > goat20->getPosition().getY()))) {
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			palo = 24;
		}


	}*/

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

	static int indexOfGoat = 4;
	//bool rightPosition;
	/*TheBoard::Instance()->setRX(5000);
	TheBoard::Instance()->setRY(5000);*/

	int mouspos_X = TheBoard::Instance()->getR_X();
	int mouspos_Y = TheBoard::Instance()->getR_Y();

	//std::cout << mouspos_X << std::endl;
	//std::cout << mouspos_Y << std::endl;

    int correct = 0;
	std::cout <<"no of game object"<< m_gameObjects.size() << std::endl;
	for (int i = 0;i <m_gameObjects.size();i++) {
		if ((( m_SDLgameObjects[i]->getPosition().getX()) != mouspos_X) && (( m_SDLgameObjects[i]->getPosition().getY()) != mouspos_Y)) {
			correct++;
			std::cout << correct << std::endl;

			continue;
			
		}
	}
	

	if (correct == 21) {
		
		m_SDLgameObjects[indexOfGoat]->getPosition().setX(mouspos_X);
		m_SDLgameObjects[indexOfGoat]->getPosition().setY(mouspos_Y);
		
		indexOfGoat++;
		correct = 0;
		
		gameTurn++;
		



	}



}




	




