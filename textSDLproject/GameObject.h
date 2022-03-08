#ifndef __GameObject__
#define __GameObject__

#include <string>

#include "LoaderParams.h"

class GameObject
{
public:
	
	virtual void draw() =0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void handleInput() = 0;
	//virtual void handle(int, int) = 0;
	//virtual void getTextureIDg();

protected:

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
	
};

#endif // __GameObject__
