#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <fstream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

void print_board (char board[][3]) {
	int i;
	int j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}


void update_board (char board[][3], char move, char turn) {
	int i;
	int j;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == move){
				board[i][j] = turn;
			}
		}
	}
}


char check_win (char board[][3], char turn, int count) {
	char X_pos[][2] = {{},{},{},{},{}};
	char O_pos[][2] = {{},{},{},{},{}};
	int i;
	int j;
	int cx = 0;
	int co = 0;
	int turnloop;
	int otherloop;
	int countx;
	int county;
	int countd1;
	int countd2;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == 'X') {
				X_pos[cx][0] = i;
				X_pos[cx][1] = j;
				cx++;
			} else if (board[i][j] == 'O') {
				O_pos[co][0] = i;
				O_pos[co][1] = j;
				co++;
			}
		}
	}
	if (count % 2 == 1) {
		turnloop = ((count/2) + 1);
		otherloop = count - turnloop;
		if (turn == 'X') {
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < turnloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < turnloop; j++) {
					if (X_pos[i][0] == X_pos[j][0]){
						countx++;
					}
					if (X_pos[i][1] == X_pos[j][1]){
						county++;
					} 
				}
				if (X_pos[i][0] == X_pos[i][1]){
					countd1 ++;
				}
				if (X_pos[i][0]+X_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'X';
				}
			}
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < otherloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < otherloop; j++) {
					if (O_pos[i][0] == O_pos[j][0]){
						countx++;
					}
					if (O_pos[i][1] == O_pos[j][1]){
						county++;
					} 
				}
				if (O_pos[i][0] == O_pos[i][1]){
					countd1 ++;
				}
				if (O_pos[i][0]+O_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'O';
				}
			}
		} else {
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < otherloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < otherloop; j++) {
					if (X_pos[i][0] == X_pos[j][0]){
						countx++;
					}
					if (X_pos[i][1] == X_pos[j][1]){
						county++;
					} 
				}
				if (X_pos[i][0] == X_pos[i][1]){
					countd1 ++;
				}
				if (X_pos[i][0]+X_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'X';
				}
			}
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < turnloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < turnloop; j++) {
					if (O_pos[i][0] == O_pos[j][0]){
						countx++;
					}
					if (O_pos[i][1] == O_pos[j][1]){
						county++;
					} 
				}
				if (O_pos[i][0] == O_pos[i][1]){
					countd1 ++;
				}
				if (O_pos[i][0]+O_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'O';
				}
			}
		}
	}
	if (count % 2 == 0) {
		turnloop = count/2;
		otherloop = count - turnloop;
		if (turn == 'X') {
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < turnloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < turnloop; j++) {
					if (X_pos[i][0] == X_pos[j][0]){
						countx++;
					}
					if (X_pos[i][1] == X_pos[j][1]){
						county++;
					} 
				}
				if (X_pos[i][0] == X_pos[i][1]){
					countd1 ++;
				}
				if (X_pos[i][0]+X_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'X';
				}
			}
			countd1 = 0;
			countd2 = 0;
			for (i = 0; i < turnloop; i++) {
				countx = 0;
				county = 0;
				for (j = 0; j < turnloop; j++) {
					if (O_pos[i][0] == O_pos[j][0]){
						countx++;
					}
					if (O_pos[i][1] == O_pos[j][1]){
						county++;
					} 
				}
				if (O_pos[i][0] == O_pos[i][1]){
					countd1 ++;
				}
				if (O_pos[i][0]+O_pos[i][1] == 2){
					countd2 ++;
				}
				if (countx == 3 || county == 3 || countd1 == 3 || countd2 == 3){
					return 'O';
				}
			}
		} 
	}
	return 'A';
}


char * moves_list (char board[][3], int count) {
	static char lst[45] = {};
	int i;
	int j;
	int num = 0;
	
	for (i = 0; i < 3; i ++) {
		for (j = 0; j < 3; j ++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				lst[num] = board[i][j];
				lst[num+1] = board[i][j];
				lst[num+2] = board[i][j];
				lst[num+3] = board[i][j];
				lst[num+4] = board[i][j];
				num += 5;
			}
		}
	}
	return lst;
}


int lenw (char board[][3]) {
	int i;
	int j;
	int c = 0;
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (board[i][j] != 'X' && board[i][j] != 'O'){
				c ++;
			}
		}
	}
	
	return c*5;
}


string convert (char board[][3]) {
	int i;
	int j;
	string s = "";
	
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			s = s + board[i][j];
		}
	}
	
	return s;
}


string convert2 (char moves[], int size) {
	int i;
	string s = "";
	
	for (i = 0; i < size; i++){
		s = s + moves[i];
	}
	
	return s;
}


int compare (string str1, string str2) {
	int i;
	
	for (i = 0; i < 9; i++){
		if (str1[i] != str2[i]) {
			return 0;
		}
	}
	
	return 1;
}


int game (){
	
	srand ( time(NULL) );
	
	char board[][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	char turns[] = {'X', 'O'};
	int turn_index = rand() % 2;
	char turn = turns[turn_index];
	int count = 0;
	char move;
	int i;
	int j;
	char ye;
	char *moves;
	int len = 0;
	int lan;
	int move_index;
	fstream board_file;
	string boardstr;
	fstream move_file;
	int check = 0;
	string checkstr;
	char* check2str;
	int check_count;
	int index_no = 0;
	static int index_lst[] = {};
	char move_process[] = {};
	int index_lst_count = 0;
	int size_index;
	int var;
	int another_var;
	string temp_lst[350] = {};
	string temp_var = "";
	string temp_var2 = "";
	
	print_board(board);
	
	move_file.open("move.txt", ios::in);
	another_var = 0;
	while (getline(move_file, checkstr)) {
//		cout << checkstr << endl;
		temp_lst[another_var] = checkstr;
		another_var++;
	}
	move_file.close();
	
	cout << "Yahan bhi aagya mai hahahah" << endl;
	while (true){
		
		len = 0;
		check = 0;
		check_count = 0;
		
		cout << endl;
		
		if (turn == 'X') {
			cout << "It's Computer's turn" << endl;
			
			lan = lenw(board);
			moves = moves_list(board, lan);
			move_index = rand() % lan;
//			Sleep(1000);
			move = moves[move_index];
			
			if (index_no != 0) {
				index_lst[index_lst_count] = index_no;
				move_process[index_lst_count] = move;
				index_lst_count++;
				var = 1;
				cout << "Board found" << endl;
				cout << index_lst[0] << '\t' << move_process[0] << endl;
			}

			
		} else {
			cout << "It's your turn" << endl;
			// cout << endl;
			// cout << "Pick a position: ";
			// cin >> move;
			lan = lenw(board);
			moves = moves_list(board, lan);
			move_index = rand() % lan;
//			Sleep(1000);
			move = moves[move_index];
		}
		
		cout << move << endl;
		cout << endl;
		
		update_board (board, move, turn);
		
		print_board(board);
		
		count ++;
		index_no = 0;
		
		if (count >= 4){
			ye = check_win(board, turn, count);
			if (ye != 'A'){
				break;
			}
		}
		cout << "Bhand aasakta hai yahan" << endl;
		if (turn == 'O'){
			if (count == 1) {
					
				board_file.open("boards_1.txt", ios::in);
				while (getline(board_file, checkstr)) {
					if (checkstr == convert(board)) {
						check = 1;
						index_no = check_count;
					} else {
						check_count++;
					}
					
				}
				board_file.close();
				
				
				if (check == 0 ) {
				
					board_file.open("boards_1.txt", ios::app);
					board_file << convert(board);
					board_file << '\n';
					board_file.close();
					
					move_file.open("move.txt", ios::app);
					lan = lenw(board);
					moves = moves_list(board, lan);
					move_file << convert2(moves, lan);
					move_file << '\n';
					move_file.close();
				}
			}
		}
		
		if (turn == 'X'){
			turn = 'O';
		} else {
			turn = 'X';
		}
		
		if (count == 9){
			break;
		}
		
	}
	lan = 0;
	if (var == 1) {
		size_index = index_lst_count;
		for (i = 0; i < size_index; i++) {
			if (ye == 'O'){
				temp_var = temp_lst[index_lst[i]];
				len = temp_var.length();
				for (j = 0; j < len; j++){
					if (lan == 0) {
						if (temp_var[j] == move_process[i]) {
							temp_var2 = temp_var2 + "";
							lan = 1;
						} else {
							temp_var2 = temp_var2 + temp_var[j];
						}
					} else {
						temp_var2 = temp_var2 + temp_var[j];
					}
					
					temp_lst[index_lst[i]] = temp_var2;
				}
			} else if (ye == 'X') {
				temp_var = temp_lst[index_lst[i]];
				temp_var = temp_var + move_process[i];
				temp_var = temp_var + move_process[i];
				temp_var = temp_var + move_process[i];
				temp_lst[index_lst[i]] = temp_var;	
			}
		}
	}
	if (size_index != 0){
	
		move_file.open("move.txt", ios::out);
		for (i = 0; i < another_var; i++) {
			move_file << temp_lst[i] << '\n';
		}
		move_file.close();
	}
	cout << endl;
	if (ye == 'A') {
		cout << "It's a Draw" << endl;
		return 0;
	} else if (ye == 'X') {
		cout << "Winner == Computer" << endl;
		return 1;
	} else if (ye == 'O'){
		cout << "Winner == You" << endl;
		return 2;
	}
}


int main () {
	int i;
	int comp = 0;
	int u = 0;
	int draw = 0;
	int y;
	
	
	for (i = 1; i <= 100; i++) {
		cout << "Starting game number " << i << endl;
		cout << endl;
		
		y = game();
		
		// cout << "yahan aagya bhai ye" << endl;
		if (y == 1) {
			comp++;
		}else if (y == 0) {
			draw++;
		}else if (y == 2) {
			u++;
		}
	}
	
	cout << "Computer: " << comp << endl;
	cout << "You: " << u << endl;
	cout << "Draw: " << draw << endl;
	
	return 0;
}
