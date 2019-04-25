#include "pch.h"
#include "TetrisGame.h"
#include "Goto.h"
#include "TetrisDB.h"

#pragma warning(disable:4996)

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

	SettingBox(CurrentBox, Transform, CurrentBoxType);
	SettingBox(NextBox, None, NextBoxType);
	if(CheckBox())
	{
		DeleteBox();
	}
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
			BoxCopy(Box, BoxDB[BoxType-1][Change]);
			break;
		case JType:
			BoxCopy(Box, BoxDB[BoxType - 1][Change]);
			break;
		case OType:
			BoxCopy(Box, BoxDB[BoxType - 1][Change]);
			break;
		case TType:
			BoxCopy(Box, BoxDB[BoxType - 1][Change]);
			break;
		case IType:
			BoxCopy(Box, BoxDB[BoxType - 1][Change]);
			break;
		}
	}
}

bool TetrisGame::CheckBox()
{
	for (int i = 0; i < BoxSize; i++)
	{
		for (int j = 0; j < BoxSize; j++)
		{
			if (CurrentBox[i][j] == Screen[CurrentX + i + MoveX][CurrentY + j + 1] && 1 == CurrentBox[i][j])
			{
				//CURRENT
				return false;
			}
		}
	}
	for (int i = 0; i < BoxSize; i++)
	{
		for (int j = 0; j < BoxSize; j++)
		{
			CurrentBox[i][j] = Screen[CurrentX + i][CurrentY + j];
			CurrentBox[i][j] = Screen[CurrentX + i + MoveX][CurrentY + j + 1];
		}
	}
	return true;
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

void TetrisGame::KeyDown()
{
	char KeyOn;
	KeyOn = getch();
	switch (KeyOn)
	{
	case 'W':
	case 'w':
		Transform = (Transform++)%BoxSize;
		break;
	case 'D' :
	case 'd' :
		MoveX = 1;
		break;
	case 'A':
	case 'a':
		MoveX = -1;
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




