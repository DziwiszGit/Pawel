#pragma once
#include"Graphics.h"
class GameLevel
{
public:

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render(Graphics* gfx) = 0;
	virtual void Update() = 0;
};
