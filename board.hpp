#include <algorithm>
#include <iostream>
#include <string>
class Board {
private:
  char Letters[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u'};

  void makeBoard(char board[][21]) {
    for (int i = 0; i < 21; i++) {
      for (int j = 0; j < 21; j++) {
        if (i == 0 || j == 0) {
          if (i == 0 && j == 0) {
            board[i][j] = '=';
          } else {

            if (i == 0) {
              board[i][j] = Letters[j - 1];
            }

            if (j == 0) {
              board[i][j] = Letters[i - 1];
            }
          }
        } else {
          board[i][j] = '0';
        }
      }
    }
  }

  void checkSqare(char board[][21], int i, int j) {
    int number = 0;
    for (int x = -1; x <= 1; x++) {
      for (int y = -1; y <= 1; y++) {
        if (i + y >= 0 && j + x >= 0) {
          if (board[i + y][j + x] == 'X') {
            number++;
          }
        }
      }
    }
    if (board[i][j] != 'X') {
      char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
      char ch = digits[number];
     // std::cout << ch << ": \n ";
      board[i][j] = char(ch);
    }
  }

  void addNumbers(char board[][21]) {
    for (int i = 1; i < 21; i++) {
      for (int j = 1; j < 21; j++) {
        checkSqare(board, i, j);
      }
    }
  }

  void placeBombs(char board[][21]) {
    // 60 bombs
    int placedBombs = 0;
    while (placedBombs < 61) {
      if (board[randomNumber(20)+1][randomNumber(20)+1] != 'X') {
        board[randomNumber(20)+1][randomNumber(20)+1] = 'X';
        placedBombs++;
      }
    }
  }

public:
  static int randomNumber(int max) { return rand() % max; }
  static void readBoard(char board[][21]) {
    for (int i = 0; i < 21; i++) {
      for (int j = 0; j < 21; j++) {
        std::cout << board[i][j] << ",";
      }
      std::cout << "\n";
    }
  }

  Board(char board[][21], std::string boardType) {
    if (boardType == "board") {
      makeBoard(board);
      placeBombs(board);
      addNumbers(board);
      readBoard(board);
    } else if (boardType == "markBoard") {

      makeBoard(board);
    }
  }
};
