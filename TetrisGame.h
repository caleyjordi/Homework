#pragma once
class TetrisGame
{
private:
	enum {
		ScreenWidth = 10,
		ScreenHeight = 20,
		Block = 1,
		None = 0,
	};
	int m_nScore = 0;
	static TetrisGame * Instance;
	

	int Screen[ScreenHeight][ScreenWidth] = { None, };
public:
	static TetrisGame * getInstance();
	static void CreateInstance();
	static void FreeInstance();

public:
	void Render();
	
	void Update();
private:
	TetrisGame() = default;
	~TetrisGame() = default;
};

/*

class Random
{
	Random(int index);
	Random();
	~Random();
	static Random * Instance;
public:

	static Random * getInstance();
	static Random * getInstance(int a);
	static void FreeInstance();
	int Rand();
	int RandomRange(unsigned int a,unsigned int b);

private:
	int Randindex[thousand];
};
*/