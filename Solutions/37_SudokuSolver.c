/* will be a backtracking solution */

//helper function to determine if a number n can go in position board[r][c]
bool isPossible(char **board, int r, int c, int n) {
    int i, j;
    
    //check the row and column
    for (i = 0; i < 9; i++) {
        if (board[r][i] - '0' == n) {
            return false;
        }
        if (board[i][c] - '0' == n) {
            return false;
        }
    }   
    //check boxes  
    //start index of the boxes
    int boxX = (r / 3) * 3;
    int boxY = (c / 3) * 3;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[boxX + i][boxY + j] - '0' == n) {
                return false;
            }
        }
    }
    return true;
}

bool solved;

void backtrack(char **board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            //is this square empty?
            if (board[r][c] == '.') {
                //try each num in this position
                for (int i = 1; i < 10; i++) {
                    if (isPossible(board, r, c, i)) {
                        //printf("putting in %c at [%d, %d]\n", i + '0', r, c);
                        board[r][c] = i + '0';
                        //check here if solved too
                        if (r == 8 & c == 8) {
                            solved = true;
                        }
                        backtrack(board);
                        //don't undo all the numbers when it is solved
                        if (!solved) {
                           board[r][c] = '.'; 
                        }  
                    }
                } 
                return; //no possible solution here
            } else if (r == 8 & c == 8 ) {
                //last square and already filled
                solved = true;
            }         
        }
    }
}

void solveSudoku(char** board, int boardSize, int* boardColSize){    
    solved = false;
    backtrack(board);  
}