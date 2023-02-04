import random
import time

def print_board(board):
    for i in range(len(board)):
        for j in board[i]:
            print (j, end=' ')
        print()

def update (board, move, turn):
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == move:
                board[i][j] = turn
                return 1
    return 0

def check_win (board):
    #for X
    X_pos = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 'X':
                X_pos.append((i,j))
    
    countd = 0
    for k in X_pos:
        countx = 0
        county = 0
        for l in X_pos:
            if k[0] == l[0]:
                countx += 1
            if k[1] == l[1]:
                county += 1
        if k[0] == k[1]:
            countd += 1
        if (0, 2) in X_pos and (1, 1) in X_pos and (2, 0) in X_pos:
            countd = 3
        if countx == 3 or county == 3 or countd == 3:
            return 1, 'X'

    #for O
    O_pos = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 'O':
                O_pos.append((i,j))

    countd = 0
    for k in O_pos:
        countx = 0
        county = 0
        for l in O_pos:
            if k[0] == l[0]:
                countx += 1
            if k[1] == l[1]:
                county += 1
        if k[0] == k[1]:
            countd += 1
        if (0, 2) in O_pos and (1, 1) in O_pos and (2, 0) in O_pos:
            countd = 3
        if countx == 3 or county == 3 or countd == 3:
            return 1, 'O'

    return 0, '1'

def moves_list (board):
    moves = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if type(board[i][j]) != str:
                moves += [board[i][j] for k in range (2)]
    return moves


def main ():

    boards = []
    data = open(r"D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\boards2.txt", "r")
    for i in data:
        boards.append(eval(i))
    data.close()

    board = [[j+(i*3) for j in range (1,4)] for i in range (3)]
    print_board (board)
    moves = [1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9]

    turns = ['X', 'O']
    turn = random.choice(turns)

    count = 0
    run = True

    learn = []

    while run:

        print()
        if turn == 'X':
            if board in boards:
                print ('Its computer\'s turn')
                time.sleep(1.5)
                l = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\learn2.txt', 'r')
                for line in l:
                    if str(board) in line:
                        print ('board found')
                        time.sleep(1)
                        lst = eval(line)
                        move = random.choice(lst[1])
                        # if count > 3:
                        learn.append((boards.index(board),move))
            else:
                print ('Its computer\'s turn')
                # time.sleep(2)
                print ('board not found in the existing file')
                # time.sleep(1)
                move = random.choice(moves_list(board))
        else:
            print ('It\'s your turn')
            print ()
            try:
                move = int(input ('Pick a position: '))
            except:
                print ('Please select a valid integer move.')
                continue
            # move = random.choice(moves_list(board))

        print (move)

        if update(board, move, turn) == 0:
            print('Invalid move, please select a valid move')
            continue

        count += 1

        print()
        print_board(board)

        if count >= 5:
            run1, winner = check_win(board)
            if run1 == 1:
                break
        
        # if not board in boards:
        #     if turn == 'O':
        #         if count == 9:
        #             print ('adding new board')
        #             data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\learn2.txt', 'a')
        #             data.write(str([board, moves_list(board)]))
        #             data.write('\n')
        #             data.close()
        #             data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\boards2.txt', 'a')
        #             data.write(str(board))
        #             data.write('\n')
        #             data.close()

        if turn == 'X':
            turn = 'O'
        else:
            turn = 'X'

        if count == 9:
            break

    print ()
    if count == 9 and not run1 == 1:
        match = 'draw'
        print ('Match Drawn')
    else:
        match = 'won'
        if winner == 'X':
            print ('Winner == Computer')
        else:
            print ('Winner == You')

    learn2 = []
    data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\learn2.txt', 'r')
    for i in data:
        learn2.append(eval(i))
    data.close()

    for i in learn:
        if match == 'draw':
            for j in range(len(learn2[i[0]][1])):
                if max(learn2[i[0]][1]) == i[1]:
                    learn2[i[0]][1].append(i[1])
                    break
                elif learn2[i[0]][1][j] > i[1]:
                    learn2[i[0]][1].insert(j, i[1])
                    break
        elif match == 'won':
            if winner == 'X':
                for j in range(len(learn2[i[0]][1])):
                    if max(learn2[i[0]][1]) == i[1]:
                        learn2[i[0]][1].append(i[1])
                        learn2[i[0]][1].append(i[1])
                        learn2[i[0]][1].append(i[1])
                        break
                    if learn2[i[0]][1][j] > i[1]:
                        learn2[i[0]][1].insert(j, i[1])
                        learn2[i[0]][1].insert(j, i[1])
                        learn2[i[0]][1].insert(j, i[1])
                        break
            else:
                learn2[i[0]][1].remove(i[1])

    open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\learn2.txt', 'w').close()

    data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\learn2.txt', 'a')
    for k in learn2:
        data.write(str(k))
        data.write('\n')
    data.close()

    if match == 'draw':
        return match
    else:
        return winner

comp = 0
u = 0
draw = 0
for i in range(1):
    print ('starting game number', i+1)
    time.sleep(1)
    a = main ()
    if a == 'draw':
        draw += 1
    elif a == 'X':
        comp += 1
    else:
        u += 1
    cnt = []


    data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\count2.txt', 'r')
    for i in data:
        cnt.append(int(i))
    data.close()
    data = open (r'D:\UNI\OneDrive - Habib University\it is wot is\ttt neural network\count2.txt', 'w')
    data.write(str(cnt[0]+1))
    data.close()


print ('Computer:', comp)
print ('You:', u)
print ('Draw:', draw)