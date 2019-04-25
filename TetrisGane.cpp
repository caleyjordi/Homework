#include "pch.h"
#include "TetrisGame.h"
#include "Goto.h"

/*
Random *Random::getInstance()
{
	if (Instance == nullptr)
		Instance = new Random;
	return Instance;
}

Random * Random::getInstance(int a)
{
	if (Instance == nullptr)
		Instance = new Random(a);
	return Instance;
}

void Random::FreeInstance()
{
	if (Instance != nullptr)
		delete Instance;
	Instance = nullptr;
}
*/
TetrisGame *TetrisGame::Instance = nullptr;

TetrisGame * TetrisGame::getInstance()
{
	return Instance;
}
void TetrisGame::CreateInstance()
{
	if (Instance == nullptr)
		Instance = new TetrisGame;
}
void TetrisGame::FreeInstance()
{
	if (Instance != nullptr)
	{
		delete Instance;
	}
	
}
void TetrisGame::Render()
{
	using namespace std;
	for (int i = 0; i < ScreenHeight; i++)
	{
		for (int j = 0; j < ScreenWidth; j++)
		{
			if (Screen[i][j] == Block)
			{
				GotoXY(i, j);
				cout << "бс";
			}
		}
	}
}

void TetrisGame::Update()
{
}


