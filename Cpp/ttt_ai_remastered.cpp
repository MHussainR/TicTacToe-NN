#include <iostream>

using namespace std;

void print_board (char board[][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void update (char board[][3], char move, char turn){
    for (int i= 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == move){
                board[i][j] = turn;
            }
        }
    }
}


char check_win (char board[][3]){
    char X_pos[][2] = {{}, {}, {}, {}, {}};
    char O_pos[][2] = {{}, {}, {}, {}, {}};
    int cx = 0;
    int co = 0;

      for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == 'X'){
                X_pos[cx][0] = i;
                X_pos[cx][1] = j;
                cx++;
            } else if (board[i][j] == 'O'){
                O_pos[cx][0] = i;
                O_pos[cx][1] = j;
                co++;
            }
        }
    }

    cout << X_pos;

    return '0';
}

void game (char board[][3]){

    char move;
    char turn = 'X';
    int i = 0;

    while (i < 9){
        cout << "It's " << turn << "'s turn" << endl;
        print_board(board);
        cout << endl << "Enter your move" << endl;

        cin >> move;

        update (board, move , turn);

        check_win(board);



        if (turn == 'X'){
            turn = 'O';
        } else {
            turn = 'X';
        }

        i++;

    }
}


int main () {
    char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    game(board); 

    return 0;
}