#include "pch.h"
#include "TetrisGame.h"
#include "Goto.h"
#include "TetrisDB.h"

TetrisGame *TetrisGame::Instance = nullptr;

TetrisGame * TetrisGame::GetInstance()
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
	Instance = nullptr;
	
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

	SettingBox(CurrentBox, None, CurrentBoxType);
	SettingBox(NextBox, None, NextBoxType);
	DeleteBox();
}

void TetrisGame::DeleteBox()
{
	int DeleteBox = 0;
	for (int i = 0; i < ScreenHeight; i++)
	{
		for (int j = 0; j < ScreenWidth; j++)
		{
			if (Screen[i][j] == None){	break;	}
			if (j == ScreenWidth - 1)
			{
				m_nScore++;
				DeleteBox = i;
			}
		}
		for (int j = 0; j < ScreenWidth; j++)
		{
			Screen[DeleteBox][j] = None;
		}
	}
}

bool TetrisGame::Defeat()
{
	for (int j = 0; j < ScreenWidth; j++)
	{
		if (Screen[0][j] == Block) { return true; }
	}
	return false;
}

void TetrisGame::SettingBox(int Box[BoxSize][BoxSize],int Change, int BoxType)
{
	assert(Change < 4 && Change > 0);
	srand(time(NULL));
	if (BoxType == 0 || Change != 0)
	{
		if (BoxType == 0)	{	BoxType = rand() % 4 + 1;	}
		switch (BoxType)
		{
		case LType:
			BoxCopy(Box, LTypeBox[Change]);
			break;
		case JType:
			BoxCopy(Box, JTypeBox[Change]);
			break;
		case OType:
			BoxCopy(Box, OTypeBox[Change]);
			break;
		case TType:
			BoxCopy(Box, TTypeBox[Change]);
			break;
		case IType:
			BoxCopy(Box, ITypeBox[Change]);
			break;
		}
	}
}

void TetrisGame::BoxCopy(int Box[BoxSize][BoxSize], int Box2[BoxSize][BoxSize])
{
	for (int i = 0; i < BoxSize; i++)
	{
		for (int j = 0; j < BoxSize; j++)
		{
			Box[i][j] = Box2[i][j];
		}
	}
}

void TetrisGame::KeyDown(char KeyOn)
{
	switch (KeyOn)
	{
	case 'W':
	case 'w':
		break;
	case 'D' :
	case 'd' :
		break;
	case 'A':
	case 'a':
		break;
	case 's':
	case 'S':
		break;
	case 'Q':
	case 'q':
		break;
		
	}
}

void TetrisGame::ScreenReset()
{
	for (int i = 0; i < ScreenHeight; i++)
	{
		for (int j = 0; j < ScreenWidth; j++)
		{
			Screen[i][j] = 0;
			if (i < BoxSize && j < BoxSize)
			{
				NextBox[i][j] = 0;
			}
		}
	}
	

}




