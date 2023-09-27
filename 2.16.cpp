#include <iostream>
using namespace std;

const int X = 1, O = 2, EMPTY = 0;
int board[3][3] = {0}, choice;
int player1 = 1, player2 = 2, currentplayer;

void start() {
    cout << "Player 1 or Player 2, press 1 or 2" << endl;
    cin >> choice;
    if (choice == 1) {
        currentplayer = player1;
    } else {
        currentplayer = player2;
    }
}

void turn(int curplayer) {
    if (curplayer == player1) {
        currentplayer = player2;
    } else if (curplayer == player2) {
        currentplayer = player1;
    }
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                cout << " |";
            } else if (board[i][j] == X) {
                cout << "X|";
            } else if (board[i][j] == O) {
                cout << "O|";
            }
        }
        cout << "\n";
        if (i < 2) {
            cout << "------\n";
        }
    }
}

bool isWin() {
    return ((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != EMPTY) ||
            (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != EMPTY) ||
            (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != EMPTY) ||
            (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != EMPTY) ||
            (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != EMPTY) ||
            (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != EMPTY) ||
            (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY));
}

void Win() {
    if (currentplayer == player1) {
        cout << "X won\n";
    } else if (currentplayer == player2) {
        cout << "O won\n";
    }
}

int main() {
    int direction;
    start();
    printBoard();
    cout << "Use numpads to choose square\n";
    while (1) {
        cin >> direction;
        if (direction < 1 || direction > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }
        int row = (direction - 1) / 3;
        int col = (direction - 1) % 3;
        
        if (board[row][col] != EMPTY) {
            cout << "Square already occupied. Choose another square.\n";
            continue;
        }
        
        board[row][col] = currentplayer;
        printBoard();
        if (isWin()) {
            Win();
            break;
        }
        turn(currentplayer);
    }
    return 0;
}
