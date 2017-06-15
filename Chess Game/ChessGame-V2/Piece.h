#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<vector>
using namespace std;
using namespace sf;

enum PieceColor { Black, White, None };

class Piece
{
protected:
	pair < int, int> CurrentLocation;
public:
	bool FirstMove;
	Sprite PieceSprite;
	PieceColor MyColor;
	string MyType;
	void SetCurrentLocation(pair < int, int> Location);
	virtual void  CreateSprite(RenderWindow &Window, pair < int, int> Location);
	virtual vector<pair < int, int>> ValidMoves() = 0;
	~Piece();
	Piece();
	bool validation(int i, int j);
	pair<int, int> GetCurrentLocation();
};

class Rook : public Piece
{
public:
	Rook(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	Rook();
};

class Queen : public Piece
{
public:
	Queen(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	Queen();
};

class Knight : public Piece
{
public:
	Knight(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	vector <pair<int, int>> KnightMoves;
	Knight();
};

class Bishop : public Piece
{
public:
	Bishop(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	Bishop();

};

class Pawn : public Piece
{
public:
	Pawn(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	Pawn();
};

class King : public Piece
{
public:
	King(RenderWindow &Window, pair<int, int> Location, PieceColor MyColor);
	void  CreateSprite(RenderWindow &Window, pair<int, int> Location);
	vector<pair<int, int>> ValidMoves();
	King();
};