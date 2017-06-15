#include <SFML\Graphics.hpp>
#include "Board.h"
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(sf::VideoMode(1200, 1200), "CHESS", Style::Titlebar | Style::Close);
	Board board(window);
	board.GamePlay(window);
	return 0;
}