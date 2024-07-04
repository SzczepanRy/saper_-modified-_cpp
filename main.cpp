#include "board.hpp"
#include "strike.hpp"
#include <iostream>
#include <string>
class Game {
private:
  char board[21][21];
  char markBoard[21][21];
public:
  void gameLoop() {
    // intake strike
    while (true) {
      std::string coordinatesString;
      std::cout << "input Commands: ";
      std::cin >> coordinatesString;
      Strike(board, markBoard, coordinatesString);
      Board::readBoard(markBoard);
    }
    // markBoard
  }
  Game() {
    Board NewBoard(board, "board");
    Board NewMarkBoard(markBoard, "markBoard");
    gameLoop();

  }
};

int main() {

  Game game;

  return 0;
}
