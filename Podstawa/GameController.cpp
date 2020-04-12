#include "GameController.h"

GameLevel* GameController::currentLevel;
bool GameController::Loading;

void GameController::Init()
{
	Loading = true;
	currentLevel = 0;

}

void GameController::LoadInitialLevel(GameLevel* lev)
{
	Loading = true;
	currentLevel = lev;
	currentLevel->Load();
	Loading = false;
}
void GameController::SwitchLevel(GameLevel* lev)
{
	Loading = true;
	currentLevel->Unload();
	lev->Load();
	delete currentLevel;
	currentLevel = lev;
	Loading = false;

}
void GameController::Render(Graphics* gfx)
{
	if (Loading)return;
	currentLevel->Render(gfx);
}
void GameController::Update()
{
	if (Loading)return;
	currentLevel->Update();
}