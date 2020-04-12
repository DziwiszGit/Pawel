#include "Level1.h"
#include "GameController.h"
#include "Graphics.h"
void Level1::Load()
{
	y=ySpeed=0.0f;
}
void Level1::Unload()
{

}
void Level1::Update()
{
	ySpeed = ySpeed + 1.0f;
	y = y + ySpeed;
	if (y > 600)
	{
		y = 600;
		ySpeed = -30.0f;
	}
}
void Level1::Render(Graphics* gfx)
{

	gfx->ClearScreen(0.0f, 0.5f, 0.5f);

	gfx->DrawCircle(700.0f, y, 50.0f, 1.0f, 0.7f, 0.4f, 1.0f);
	gfx->DrawCircle(100.0f, y, 50.0f, 1.0f, 0.7f, 0.4f, 1.0f);

}
