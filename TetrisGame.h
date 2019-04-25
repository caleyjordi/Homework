#pragma once

class TetrisGame
{
private:
	//enum
	enum {
		ScreenWidth = 10,
		ScreenHeight = 20,
		Block = 1,
		None = 0,
		BoxSize = 4,

		//Box Type
		LType = 1,
		JType,
		OType,
		TType,
		IType,
	};
	//Index
	int m_nScore = 0;
	int Screen[ScreenHeight][ScreenWidth] = { None, };
	int NextBox[BoxSize][BoxSize];
	int CurrentBox[BoxSize][BoxSize];
	int NextBoxType = 0;
	int CurrentBoxType = 0;
	//ÇÔ¼öµé
	void BoxCopy(int Box[BoxSize][BoxSize], int Box2[BoxSize][BoxSize]);
	void DeleteBox();
	void SettingBox(int Box[BoxSize][BoxSize],int Change,int BoxType);
public:
	void Render();
	void Update();
	bool Defeat();
	

	void KeyDown(char KeyOn);
	void ScreenReset();

	//SingleTon
public:
	static TetrisGame * GetInstance();
	static void CreateInstance();
	static void FreeInstance();
private:
	TetrisGame() = default;
	~TetrisGame() = default;
	static TetrisGame * Instance;
};
