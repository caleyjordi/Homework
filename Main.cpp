#include "pch.h"
#include <iostream>

#include "TetrisGame.h"

int main()
{
	TetrisGame::CreateInstance();
	TetrisGame::GetInstance()->ScreenReset();
	while(TetrisGame::GetInstance()->Defeat() == false)
	{
		TetrisGame::GetInstance()->Update();
		TetrisGame::GetInstance()->Render();
	}
	return 0;
}
