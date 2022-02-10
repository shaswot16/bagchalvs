#pragma once
#include "Game.h"
#include "Vector2D.h"
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string
		textureID) : m_x(x), m_y(y), m_width(width), m_height(height),
		m_textureID(textureID)
	{
	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }

private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_textureID;
};

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};



class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	//virtual void clean();
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
protected:
	
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;
};





