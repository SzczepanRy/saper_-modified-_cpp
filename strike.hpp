
#include <iostream>
#include <string>
struct Coordinates {
  char x;
  char y;
};
struct IntCoords {
  int x;
  int y;
};

class Strike {
private:
  char *currentBoard;
  char *currentMarkBoard;
  char Letters[20] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o', 'p', 'r', 's', 't', 'u'};

public:
  bool validateCoords(char searchChar) {
    for (int i = 0; i < 20; i++) {
      if (searchChar == Letters[i]) {
        return true;
      }
    }
    std::cout << "not a valid command coordinate : " << searchChar << "\n";
    exit(1);
    return false;
  }

  IntCoords charCoordsToInt(Coordinates coords) {
    IntCoords intCoords;
    for (int i = 0; i < 20; i++) {
      if (Letters[i] == coords.x) {
        intCoords.x = i + 1;
      }
      if (Letters[i] == coords.y) {
        intCoords.y = i + 1;
      }
    }
    return intCoords;
  }

  Coordinates readCoords(std::string coordinatesString) {
    Coordinates coords{.x = coordinatesString[0], .y = coordinatesString[1]};
    validateCoords(coords.x);
    validateCoords(coords.y);
    return coords;
  }

  void openBoard(char board[][21], char markBoard[][21],
                 IntCoords intCoordinates) {
    upTree(board, markBoard, intCoordinates);
    downTree(board, markBoard, intCoordinates);
    leftTree(board, markBoard, intCoordinates);
    rightTree(board, markBoard, intCoordinates);

  }

  // tree rlud
  void upTree(char board[][21], char markBoard[][21],
              IntCoords intCoordinates) {
    int treeLength = 0;
    int bufferInt = 0;

    std::cout << "it coords yx : " << intCoordinates.x << intCoordinates.y
              << "\n";

    for (int i = intCoordinates.y; i > 0; i--) {
      std::cout << board[i][intCoordinates.x] << "\n";
      if (board[i][intCoordinates.x] == '0') {
        treeLength++;
      } else if (bufferInt == 0) {
        treeLength++;
        markBoard[i][intCoordinates.x] = board[i][intCoordinates.x];
        bufferInt++;
      } else {
        break;
      }
    }
    std::cout << "tree height == " << treeLength << "\n";

    // leftbach
    for (int i = intCoordinates.y; i > intCoordinates.y - treeLength; i--) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX = intCoordinates.x;
      int branchLeftY = i;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftX--;
      }
    }
    // right branch
    for (int i = intCoordinates.y; i > intCoordinates.y - treeLength; i--) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX = intCoordinates.x;
      int branchLeftY = i;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftX++;
      }
    }
  }
  void downTree(char board[][21], char markBoard[][21],
              IntCoords intCoordinates) {
    int treeLength = 0;
    int bufferInt = 0;

    std::cout << "it coords yx : " << intCoordinates.x << intCoordinates.y
              << "\n";

    for (int i = intCoordinates.y; i < 21; i++) {
      std::cout << board[i][intCoordinates.x] << "\n";
      if (board[i][intCoordinates.x] == '0') {
        treeLength++;
      } else if (bufferInt == 0) {
        treeLength++;
        markBoard[i][intCoordinates.x] = board[i][intCoordinates.x];
        bufferInt++;
      } else {
        break;
      }
    }
    std::cout << "down tree height == " << treeLength << "\n";

    // leftbach
    for (int i = intCoordinates.y; i < intCoordinates.y + treeLength  ; i++) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX = intCoordinates.x;
      int branchLeftY = i;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftX--;
      }
    }
    // right branch
    for (int i = intCoordinates.y; i < intCoordinates.y + treeLength  ; i++) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX = intCoordinates.x;
      int branchLeftY = i;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftX++;
      }
    }
  }

  void leftTree(char board[][21], char markBoard[][21],
              IntCoords intCoordinates) {
    int treeLength = 0;
    int bufferInt = 0;

    std::cout << "it coords xy : " << intCoordinates.x << intCoordinates.y
              << "\n";

    for (int i = intCoordinates.x; i > 0; i--) {
      std::cout << board[intCoordinates.y][i] << "\n";
      if (board[intCoordinates.y][i] == '0') {
        treeLength++;
      } else if (bufferInt == 0) {
        treeLength++;
        markBoard[intCoordinates.y][i] = board[intCoordinates.y][i];
        bufferInt++;
      } else {
        break;
      }
    }
    std::cout << "left tree height == " << treeLength << "\n";

    // leftbach
    for (int i = intCoordinates.x; i > intCoordinates.x - treeLength  ; i--) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX =i ;
      int branchLeftY = intCoordinates.y;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftY--;
      }
    }
    // right branch
    for (int i = intCoordinates.x; i > intCoordinates.x - treeLength  ; i--) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX =  i;
      int branchLeftY = intCoordinates.y;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftY++;
      }
    }
  }
  void rightTree(char board[][21], char markBoard[][21],
              IntCoords intCoordinates) {
    int treeLength = 0;
    int bufferInt = 0;

    std::cout << "it coords xy : " << intCoordinates.x << intCoordinates.y
              << "\n";

    for (int i = intCoordinates.x; i < 21; i++) {
      std::cout << board[intCoordinates.y][i] << "\n";
      if (board[intCoordinates.y][i] == '0') {
        treeLength++;
      } else if (bufferInt == 0) {
        treeLength++;
        markBoard[intCoordinates.y][i] = board[intCoordinates.y][i];
        bufferInt++;
      } else {
        break;
      }
    }
    std::cout << "left tree height == " << treeLength << "\n";

    // leftbach
    for (int i = intCoordinates.x; i < intCoordinates.x + treeLength  ; i++) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX =i ;
      int branchLeftY = intCoordinates.y;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftY--;
      }
    }
    // right branch
    for (int i = intCoordinates.x; i < intCoordinates.x + treeLength  ; i++) {
      // i == tree height base
      // check left
      int bufferInt = 0;
      int branchLeftX =  i;
      int branchLeftY = intCoordinates.y;
      while (bufferInt <= 0) {
        if (board[branchLeftY][branchLeftX] == '0') {
          markBoard[branchLeftY][branchLeftX] = '_';

        } else {
          bufferInt++;
          markBoard[branchLeftY][branchLeftX] = board[branchLeftY][branchLeftX];
        }
        branchLeftY++;
      }
    }
  }
  Strike(char board[][21], char markBoard[][21],
         std::string coordinatesString) {
    currentBoard = *board;
    currentMarkBoard = *markBoard;
    Coordinates validCoordinates = readCoords(coordinatesString);
    IntCoords intCoordinates = charCoordsToInt(validCoordinates);
    openBoard(board, markBoard, intCoordinates);
  }
};
