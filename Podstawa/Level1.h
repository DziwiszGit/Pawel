#pragma once
#include "GameLevel.h"
#include "Graphics.h"
class Level1 : public GameLevel
{
	float y ;
	float ySpeed;
	public:
		void Load() override;
		void Unload() override;
		void Render(Graphics* gfx) override;
		void Update() override;

};