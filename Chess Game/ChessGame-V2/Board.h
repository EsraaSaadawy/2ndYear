#pragma once
#include<iostream>
#include<SFML\Graphics.hpp>
#include<vector>
#include <map>
#include "Piece.h"


using namespace std;
using namespace sf;

class Board
{

	static Texture txt1;
	static Sprite board;
	vector <pair<int, int >> Moves;
	static bool MoveRequest;
	static Piece* ToMove;
	bool PlayerTurn;
public:
	void Highlight(RenderWindow &Window, vector< pair<int, int >> ValidMoves);
	static Piece* ChessBoard[8][8];
	Board(RenderWindow &window);
	void Update(RenderWindow &Window, Piece* P);
	~Board();
	void Move(RenderWindow &Window, Event &TheEvent);
	void DrawB(RenderWindow &w);
	void GamePlay(RenderWindow &window);
	bool CheckMate();
	bool menu(RenderWindow &window);
};