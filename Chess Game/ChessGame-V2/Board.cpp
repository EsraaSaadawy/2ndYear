#include "Board.h"
#include "SFML/Graphics.hpp"
#include <iostream>

Texture Board::txt1;

Sprite Board::board;

Piece* Board::ChessBoard[8][8] = { NULL };

bool Board::MoveRequest = false;

Piece* Board::ToMove = NULL;

bool Board::menu(RenderWindow &window)
{
	Event TheEvent;
	Texture menu , choice;
	choice.loadFromFile("choice.png");
	menu.loadFromFile("menu.jpg");
	Sprite men,choi;
	choi.setTexture(choice);
	men.setTexture(menu);
	choi.setPosition(Vector2f(275, 400));
	bool x = true;
	window.clear();
	window.draw(men);
	window.draw(choi);
	window.display();
	while (2)
	{ 
		while (window.pollEvent(TheEvent))
		{
			switch (TheEvent.type)
			{
			case Event::KeyReleased:
				switch (TheEvent.key.code)
				{
				case Keyboard::Up:
					if (x)
					{
						choi.setPosition(Vector2f(275, 800));
						x = false;
					}
					else
					{
						choi.setPosition(Vector2f(275, 400));
						x = true;
					}
					break;
				case Keyboard::Down:
					if (x)
					{
						choi.setPosition(Vector2f(275, 800));
						x = false;
					}
					else
					{
						choi.setPosition(Vector2f(275, 400));
						x = true;
					}
					break;
				case Keyboard::Return:
					return x;
					window.clear();
					break;
				
				}
				if (Event::Closed)
				{
					window.close();
				}
			}
			window.clear();
			window.draw(men);
			window.draw(choi);
			window.display();
		}
	}
	
	//true one player 
	//false two players

}

void Board::GamePlay(RenderWindow &window)
{
	while (window.isOpen())
	{
		
		sf::Event TheEvent;

		while (window.pollEvent(TheEvent))
		{
			switch (TheEvent.type)
			{
			case Event::MouseButtonPressed:
				Move(window, TheEvent);
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
}

void Board:: Highlight(RenderWindow &Window, vector< pair<int, int >> ValidMoves)
{
	Texture txt;
	txt.loadFromFile("Highlight.png");
	vector<pair<int, int>> ::iterator it = ValidMoves.begin();
	for (; it != ValidMoves.end(); it++)
	{
		Sprite HSprite;
		HSprite.setTexture(txt);
		HSprite.setPosition(Vector2f(((*it).first) * 150, ((*it).second) * 150));
		DrawB(Window);
		Window.draw(HSprite);
	}
	Window.display();
}

Board::Board(RenderWindow &window)
{
	menu(window);
	txt1.loadFromFile("board.jpg");
	board.setTexture(txt1);
	window.clear();
	window.draw(board);
	PlayerTurn = false;

	for (int i = 0; i < 8; i++)
	{
		ChessBoard[i][1] = new Pawn(window, { i, 1 }, Black);
	}
	for (int j = 2; j <= 5; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			ChessBoard[i][j] = NULL;
		}
	}
	ChessBoard[0][7] = new Rook(window, { 0, 7 }, White);
	ChessBoard[1][7] = new Knight(window, { 1, 7 }, White);
	ChessBoard[2][7] = new Bishop(window, { 2, 7 }, White);
	ChessBoard[3][7] = new Queen(window, { 3, 7 }, White);
	ChessBoard[4][7] = new King(window, { 4, 7 }, White);
	ChessBoard[5][7] = new Bishop(window, { 5, 7 }, White);
	ChessBoard[6][7] = new Knight(window, { 6, 7 }, White);
	ChessBoard[7][7] = new Rook(window, { 7, 7 }, White);
	ChessBoard[0][0] = new Rook(window, { 0, 0 }, Black);
	ChessBoard[1][0] = new Knight(window, { 1, 0 }, Black);
	ChessBoard[2][0] = new Bishop(window, { 2, 0 }, Black);
	ChessBoard[3][0] = new King(window, { 3, 0 }, Black);
	ChessBoard[4][0] = new Queen(window, { 4, 0 }, Black);
	ChessBoard[5][0] = new Bishop(window, { 5, 0 }, Black);
	ChessBoard[6][0] = new Knight(window, { 6, 0 }, Black);
	ChessBoard[7][0] = new Rook(window, { 7, 0 }, Black);
	for (int i = 0; i < 8; i++)
	{
		ChessBoard[i][6] = new Pawn(window, { i, 6 }, White);
	}

	window.display();

}

void Board::Move(RenderWindow &Window, Event &TheEvent)
{
	if (TheEvent.mouseButton.button == Mouse::Left)
		if (MoveRequest == false)
		{
			MoveRequest = true;
			pair<int, int> CurrentPoint = { (TheEvent.mouseButton.x) / 150, (TheEvent.mouseButton.y) / 150 };
			if (ChessBoard[CurrentPoint.first][CurrentPoint.second] != NULL && ChessBoard[CurrentPoint.first][CurrentPoint.second]->MyColor == White && PlayerTurn == false)
			{
				Moves = ChessBoard[CurrentPoint.first][CurrentPoint.second]->ValidMoves();
				ToMove = ChessBoard[CurrentPoint.first][CurrentPoint.second];
				//Highlight(Window, Moves);
			}
			else if (ChessBoard[CurrentPoint.first][CurrentPoint.second] != NULL && ChessBoard[CurrentPoint.first][CurrentPoint.second]->MyColor == Black && PlayerTurn == true)
			{
				Moves = ChessBoard[CurrentPoint.first][CurrentPoint.second]->ValidMoves();
				ToMove = ChessBoard[CurrentPoint.first][CurrentPoint.second];
			}
			else
				MoveRequest = false;
		}
		else
		{
			MoveRequest = false;
			pair<int, int>  NewPoint = { (TheEvent.mouseButton.x) / 150, (TheEvent.mouseButton.y) / 150 };
			vector <pair<int, int> > ::iterator  it = find(Moves.begin(), Moves.end(), NewPoint);
			if (it != Moves.end())
			{
				Piece* temp = ChessBoard[NewPoint.first][NewPoint.second];
				if (ChessBoard[NewPoint.first][NewPoint.second] != NULL) { ChessBoard[NewPoint.first][NewPoint.second] = NULL; }
				swap(ChessBoard[ToMove->GetCurrentLocation().first][ToMove->GetCurrentLocation().second], ChessBoard[NewPoint.first][NewPoint.second]);
				if (!CheckMate()) {
					if (ChessBoard[NewPoint.first][NewPoint.second]->MyType == "Pawn") { ChessBoard[NewPoint.first][NewPoint.second]->FirstMove = true; }
					ToMove = ChessBoard[NewPoint.first][NewPoint.second];
					ToMove->SetCurrentLocation(NewPoint);
					Update(Window, ToMove);
					PlayerTurn = !PlayerTurn;
				}
				else {
					swap(ChessBoard[ToMove->GetCurrentLocation().first][ToMove->GetCurrentLocation().second], ChessBoard[NewPoint.first][NewPoint.second]);
					ChessBoard[NewPoint.first][NewPoint.second] = temp;
					ToMove = NULL;
				}
			}
			else
			{
				ToMove = NULL;
				//InValid Move
			}
		}
}

void Board::Update(RenderWindow &Window, Piece* P)
{
	Window.clear();
	DrawB(Window);
	Window.display();
}

void Board::DrawB(RenderWindow &w)
{
	w.draw(board);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Board::ChessBoard[i][j] != NULL)
			{
				Board::ChessBoard[i][j]->CreateSprite(w, { i,j });
			}
		}
	}
}

bool Board::CheckMate() {
	if (PlayerTurn) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (ChessBoard[i][j] != NULL && ChessBoard[i][j]->MyColor==White) {
					vector <pair <int, int> > AvailableMoves = ChessBoard[i][j]->ValidMoves();
					for (int f = 0; f < AvailableMoves.size(); f++) {
						if (ChessBoard[AvailableMoves[f].first][AvailableMoves[f].second] != NULL) {
							if (ChessBoard[AvailableMoves[f].first][AvailableMoves[f].second]->MyType == "King") {
								return true;
							}
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (ChessBoard[i][j] != NULL && ChessBoard[i][j]->MyColor == Black) {
					vector <pair <int, int> > AvailableMoves = ChessBoard[i][j]->ValidMoves();
					for (int f = 0; f < AvailableMoves.size(); f++) {
						if (ChessBoard[AvailableMoves[f].first][AvailableMoves[f].second] != NULL) {
							if (ChessBoard[AvailableMoves[f].first][AvailableMoves[f].second]->MyType == "King") {
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}

Board::~Board()
{
}
