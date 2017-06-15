#include "Piece.h"
#include "Board.h"

Piece::Piece()
{
}

pair<int, int>Piece::GetCurrentLocation()
{
	return CurrentLocation;
}

void Piece::SetCurrentLocation(pair < int, int> Location)
{
	CurrentLocation = Location;
}

void Piece::CreateSprite(RenderWindow & Window, pair<int, int> Location)
{
}

bool Piece::validation(int i, int j)
{
	return i >= 0 && i < 8 && j >= 0 && j < 8;
}

Piece::~Piece()
{
}

Rook::Rook(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "Rook";
}

void  Rook::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("rook.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("rook-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);

}

vector<pair < int, int>> Rook::ValidMoves()
{
	vector<pair < int, int> > Moves;
	for (int i = CurrentLocation.first + 1; i < 8; i++)
	{
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[i][CurrentLocation.second]->MyColor)
			break;
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[i][CurrentLocation.second]->MyColor)
		{
			Moves.push_back({ i, CurrentLocation.second });
			break;
		}
		else if (Board::ChessBoard[i][CurrentLocation.second] == NULL)
			Moves.push_back({ i, CurrentLocation.second });
	}

	for (int i = CurrentLocation.second + 1; i < 8; i++)
	{
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[CurrentLocation.first][i]->MyColor)
			break;
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[CurrentLocation.first][i]->MyColor)
		{
			Moves.push_back({ CurrentLocation.first, i });
			break;
		}
		else if (Board::ChessBoard[CurrentLocation.first][i] == NULL)
			Moves.push_back({ CurrentLocation.first, i });
	}

	for (int i = CurrentLocation.first - 1; i >= 0; i--)
	{
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[i][CurrentLocation.second]->MyColor)
			break;
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[i][CurrentLocation.second]->MyColor)
		{
			Moves.push_back({ i, CurrentLocation.second });
			break;
		}
		else if (Board::ChessBoard[i][CurrentLocation.second] == NULL)
			Moves.push_back({ i, CurrentLocation.second });
	}

	for (int i = CurrentLocation.second - 1; i >= 0; i--)
	{
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[CurrentLocation.first][i]->MyColor)
			break;
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[CurrentLocation.first][i]->MyColor)
		{
			Moves.push_back({ CurrentLocation.first, i });
			break;
		}
		else if (Board::ChessBoard[CurrentLocation.first][i] == NULL)
			Moves.push_back({ CurrentLocation.first, i });
	}
	return Moves;
}

Rook::Rook()
{}

Queen::Queen(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "Queen";
}

void  Queen::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("queen.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("queen-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);
}

Queen::Queen()
{}

vector<pair < int, int>> Queen::ValidMoves()
{
	vector<pair < int, int> > Moves;

	for (int i = CurrentLocation.first + 1; i < 8; i++)
	{
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[i][CurrentLocation.second]->MyColor)
			break;
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[i][CurrentLocation.second]->MyColor)
		{
			Moves.push_back({ i, CurrentLocation.second });
			break;
		}
		else if (Board::ChessBoard[i][CurrentLocation.second] == NULL)
			Moves.push_back({ i, CurrentLocation.second });
	}

	for (int i = CurrentLocation.second + 1; i < 8; i++)
	{
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[CurrentLocation.first][i]->MyColor)
			break;
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[CurrentLocation.first][i]->MyColor)
		{
			Moves.push_back({ CurrentLocation.first, i });
			break;
		}
		else if (Board::ChessBoard[CurrentLocation.first][i] == NULL)
			Moves.push_back({ CurrentLocation.first, i });
	}

	for (int i = CurrentLocation.first - 1; i >= 0; i--)
	{
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[i][CurrentLocation.second]->MyColor)
			break;
		if (Board::ChessBoard[i][CurrentLocation.second] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[i][CurrentLocation.second]->MyColor)
		{
			Moves.push_back({ i, CurrentLocation.second });
			break;
		}
		else if (Board::ChessBoard[i][CurrentLocation.second] == NULL)
			Moves.push_back({ i, CurrentLocation.second });
	}

	for (int i = CurrentLocation.second - 1; i >= 0; i--)
	{
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Board::ChessBoard[CurrentLocation.first][i]->MyColor)
			break;
		if (Board::ChessBoard[CurrentLocation.first][i] != NULL && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[CurrentLocation.first][i]->MyColor)
		{
			Moves.push_back({ CurrentLocation.first, i });
			break;
		}
		else if (Board::ChessBoard[CurrentLocation.first][i] == NULL)
			Moves.push_back({ CurrentLocation.first, i });
	}

	for (int i = CurrentLocation.first + 1, j = CurrentLocation.second + 1; i < 8 && j < 8; i++, j++) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first - 1, j = CurrentLocation.second + 1; i >= 0 && j < 8; i--, j++) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first + 1, j = CurrentLocation.second - 1; i < 8 && j >= 0; i++, j--) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first - 1, j = CurrentLocation.second - 1; i >= 0 && j >= 0; i--, j--) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	return Moves;
}

Knight::Knight(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	KnightMoves.push_back({ 2, 1 });
	KnightMoves.push_back({ 1, 2 });
	KnightMoves.push_back({ -2, 1 });
	KnightMoves.push_back({ 1, -2 });
	KnightMoves.push_back({ -2, -1 });
	KnightMoves.push_back({ -1, -2 });
	KnightMoves.push_back({ 2, -1 });
	KnightMoves.push_back({ -1, 2 });
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "Knight";
}

void Knight::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("knight.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("knight-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);
}

Knight::Knight()
{}

vector<pair < int, int>> Knight::ValidMoves()
{
	vector <pair < int, int> > Moves;
	for (int i = 0; i < 8; i++)
	{
		if ((CurrentLocation.first + KnightMoves[i].first)<8 && (CurrentLocation.second + KnightMoves[i].second) <8 && (CurrentLocation.first + KnightMoves[i].first) >= 0 && (CurrentLocation.second + KnightMoves[i].second) >= 0)
		{
			if ((Board::ChessBoard[CurrentLocation.first + KnightMoves[i].first][CurrentLocation.second + KnightMoves[i].second] == NULL || Board::ChessBoard[CurrentLocation.first + KnightMoves[i].first][CurrentLocation.second + KnightMoves[i].second]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor))
				Moves.push_back({ CurrentLocation.first + KnightMoves[i].first,CurrentLocation.second + KnightMoves[i].second });
		}
	}
	return Moves;
}

Bishop::Bishop(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "Bishop";
}

void Bishop::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("bishop.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("bishop-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);
}

Bishop::Bishop()
{}

vector<pair < int, int>> Bishop::ValidMoves()
{
	vector <pair < int, int> > Moves;

	for (int i = CurrentLocation.first + 1, j = CurrentLocation.second + 1; i < 8 && j < 8; i++, j++) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first - 1, j = CurrentLocation.second + 1; i >= 0 && j < 8; i--, j++) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first + 1, j = CurrentLocation.second - 1; i < 8 && j >= 0; i++, j--) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	for (int i = CurrentLocation.first - 1, j = CurrentLocation.second - 1; i >= 0 && j >= 0; i--, j--) {
		if (Board::ChessBoard[i][j] != NULL) {
			if (Board::ChessBoard[i][j]->MyColor != Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor) {
				Moves.push_back(pair < int, int>(i, j));
				break;
			}
			else { break; }
		}
		else {
			Moves.push_back(pair < int, int>(i, j));
		}
	}

	return Moves;
}

Pawn::Pawn(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "Pawn";
	this->FirstMove = false;
}

void Pawn::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("pawn.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("pawn-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);
}

vector<pair < int, int>> Pawn::ValidMoves()
{
	vector<pair < int, int> > Moves;
	if (Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor == Black)
	{
		if (FirstMove == false)
		{
			if (validation(CurrentLocation.first, CurrentLocation.second + 2) && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second + 2] == NULL)
			{
				Moves.push_back({ CurrentLocation.first,CurrentLocation.second + 2 });
			}
		}

		if (validation(CurrentLocation.first, CurrentLocation.second + 1) && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second + 1] == NULL)
		{
			Moves.push_back({ CurrentLocation.first,CurrentLocation.second + 1 });
		}

		if (validation(CurrentLocation.first + 1, CurrentLocation.second + 1) && Board::ChessBoard[CurrentLocation.first + 1][CurrentLocation.second + 1] != NULL && Board::ChessBoard[CurrentLocation.first + 1][CurrentLocation.second + 1]->MyColor == White)
		{
			Moves.push_back({ CurrentLocation.first + 1,CurrentLocation.second + 1 });
		}

		if (validation(CurrentLocation.first - 1, CurrentLocation.second + 1) && Board::ChessBoard[CurrentLocation.first - 1][CurrentLocation.second + 1] != NULL && Board::ChessBoard[CurrentLocation.first - 1][CurrentLocation.second + 1]->MyColor == White)
		{
			Moves.push_back({ CurrentLocation.first - 1,CurrentLocation.second + 1 });
		}
	}
	else
	{
		if (FirstMove == false)
		{
			if (validation(CurrentLocation.first, CurrentLocation.second - 2) && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second - 2] == NULL)
			{
				Moves.push_back({ CurrentLocation.first,CurrentLocation.second - 2 });
			}
		}

		if (validation(CurrentLocation.first, CurrentLocation.second - 1) && Board::ChessBoard[CurrentLocation.first][CurrentLocation.second - 1] == NULL)
		{
			Moves.push_back({ CurrentLocation.first,CurrentLocation.second - 1 });
		}

		if (validation(CurrentLocation.first + 1, CurrentLocation.second - 1) && Board::ChessBoard[CurrentLocation.first + 1][CurrentLocation.second - 1] != NULL && Board::ChessBoard[CurrentLocation.first + 1][CurrentLocation.second - 1]->MyColor == Black)
		{
			Moves.push_back({ CurrentLocation.first + 1,CurrentLocation.second - 1 });
		}

		if (validation(CurrentLocation.first - 1, CurrentLocation.second - 1) && Board::ChessBoard[CurrentLocation.first - 1][CurrentLocation.second - 1] != NULL && Board::ChessBoard[CurrentLocation.first - 1][CurrentLocation.second - 1]->MyColor == Black)
		{
			Moves.push_back({ CurrentLocation.first - 1,CurrentLocation.second - 1 });
		}
	}

	return Moves;
}

Pawn::Pawn()
{}

King::King(RenderWindow &Window, pair < int, int> Location, PieceColor MyColor)
{
	this->MyColor = MyColor;
	this->CurrentLocation = Location;
	this->CreateSprite(Window, Location);
	this->MyType = "King";
}

void King::CreateSprite(RenderWindow &Window, pair < int, int> Location)
{
	Texture txt;
	if (this->MyColor == White)
	{
		txt.loadFromFile("king.png");
	}
	else if (this->MyColor == Black)
	{
		txt.loadFromFile("king-.png");
	}
	PieceSprite.setTexture(txt);
	PieceSprite.setPosition(Vector2f((CurrentLocation.first) * 150, (CurrentLocation.second) * 150));
	Window.draw(PieceSprite);
}

vector<pair < int, int>> King::ValidMoves() {
	vector<pair < int, int> >Moves;

	int dx[] = { 0 , 0 , 1 , -1 , 1 , 1 , -1 , -1 };
	int dy[] = { 1 , -1 , 0 , 0 , 1 , -1 , 1 , -1 };

	for (int i = 0; i < 8; i++)
	{
		if (validation(CurrentLocation.first + dx[i], CurrentLocation.second + dy[i]) && (Board::ChessBoard[CurrentLocation.first + dx[i]][CurrentLocation.second + dy[i]] == NULL || Board::ChessBoard[CurrentLocation.first][CurrentLocation.second]->MyColor != Board::ChessBoard[CurrentLocation.first + dx[i]][CurrentLocation.second + dy[i]]->MyColor))
			Moves.push_back({ CurrentLocation.first + dx[i], CurrentLocation.second + dy[i] });
	}

	return Moves;
}

King::King()
{}
