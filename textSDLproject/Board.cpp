#include"Board.h"
#include"TextureManager.h"
#include"Game.h"
#include"GameObject.h"
#include"SDLGameObject.h"
#include"LoaderParams.h"
#include"InputHandler.h"
#include"Vector2D.h"
#include <iostream>

//extern int gameTurn;


Board* TheBoard::s_pInstance = 0;

void Board::createBoard() {

	TextureManager::Instance()->draw("board", 50, 50, 800, 800, TheGame::Instance()->getRenderer());


	for (int x = 0;x <= 800;x += 200) {
		for (int y = 0;y <= 800;y += 200) {
			TextureManager::Instance()->draw("point", x, y, 100, 100, TheGame::Instance()->getRenderer());
		}
	}


	

}
void Board::coordinate() {

	TheBoard::Instance()->filtercoordinate();
}
void Board::filtercoordinate()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		if (TheInputHandler::Instance()->m_mousePosition->getX() >= (0) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(0);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}

		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (2 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (2 * g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (3 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(2 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= 3 * (g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (4 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(3 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}
		else if (TheInputHandler::Instance()->m_mousePosition->getX() >= (4 * g_screenWidthX / 5) &&
			TheInputHandler::Instance()->m_mousePosition->getX() <= (5 * g_screenWidthX / 5))
		{
			if (TheInputHandler::Instance()->m_mousePosition->getY() >= 0 &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(0);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 2 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(g_screenBreadthY / 5);
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 2 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 3 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY((2 * g_screenBreadthY / 5));
			}
			else if (TheInputHandler::Instance()->m_mousePosition->getY() >= 3 * (g_screenBreadthY / 5) &&
				TheInputHandler::Instance()->m_mousePosition->getY() <= 4 * (g_screenBreadthY / 5))
			{
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(3 * g_screenBreadthY / 5);
			}
			else {
				TheBoard::Instance()->setRX(4 * g_screenWidthX / 5);
				TheBoard::Instance()->setRY(4 * g_screenBreadthY / 5);
			}
		}

	}
	

}
void Board::render()
{
	TheBoard::Instance()->createBoard();

	

}