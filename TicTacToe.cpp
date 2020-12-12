// Basic C++ Tic-Tac-Toe game. Osama Abdullah
#include <iostream>
#include <string>

using namespace std;

void displayGame(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j != 2) {
                cout << board[i][j] << " | ";
            }
            else {
                cout << board[i][j] << endl;
                if (i != 2) {
                    cout << "----------" << endl;
                }
            }
        }
    }
}

void initializeGame(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    displayGame(board);
}

char checkWin(char board[3][3], char player) {
    char playerSelect = player;
    if (board[0][0] == playerSelect && board[0][1] == playerSelect && board[0][2] == playerSelect) {
        return playerSelect;
    }
    else if (board[1][0] == playerSelect && board[1][1] == playerSelect && board[1][2] == playerSelect) {
        return playerSelect;
    }
    else if (board[2][0] == playerSelect && board[2][1] == playerSelect && board[2][2] == playerSelect) {
        return playerSelect;
    }
    else if (board[0][0] == playerSelect && board[1][0] == playerSelect && board[2][0] == playerSelect) {
        return playerSelect;
    }
    else if (board[0][1] == playerSelect && board[1][1] == playerSelect && board[2][1] == playerSelect) {
        return playerSelect;
    }
    else if (board[0][2] == playerSelect && board[1][2] == playerSelect && board[2][2] == playerSelect) {
        return playerSelect;
    }
    else if (board[0][0] == playerSelect && board[1][1] == playerSelect && board[2][2] == playerSelect) {
        return playerSelect;
    }
    else if (board[0][2] == playerSelect && board[1][1] == playerSelect && board[2][0] == playerSelect) {
        return playerSelect;
    }
    else {
        return 'N';
    }
}

void makeMove(int move, char board[3][3]) {
    int x, y = 0;
    cout << "Enter ROW and COLUMN of move selection (1-3) (X Y)" << endl;
    cin >> x >> y;
    if (board[x - 1][y - 1] == '-') {
        if (move % 2 == 0) {
            board[x - 1][y - 1] = 'X';
            displayGame(board);
        }
        else {
            board[x - 1][y - 1] = 'O';
            displayGame(board);
        }
    }
    else {
        cout << "INVALID SELECTION" << endl;
        displayGame(board);
        makeMove(move, board);
    }
}

int main() {
    string input;
    int move = 0;
    bool win = false;
    int x, y = 0;
    char board[3][3];

    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "Type START to begin" << endl;
    cin >> input;


    if (input == "START") {
        cout << string(50, '\n');
        initializeGame(board);
    }
    while (1) {
        makeMove(move, board);

        if (move % 2 == 0) {
            if (checkWin(board, 'X') == 'X') {
                cout << endl << "X wins" << endl;
                break;
            }
        }
        else if (move % 2 == 1) {
            if (checkWin(board, 'O') == 'O') {
                cout << endl << "O wins" << endl;
                break;
            }
        }
        move++;
    }
}
