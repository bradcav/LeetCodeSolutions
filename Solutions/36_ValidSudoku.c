

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    
    //store whether the num has been seen in that row, column or box  
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[3][3][9] = {0};
    
    int digit;
    
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                continue;
            }
            
            digit = board[r][c] - '0' - 1;
            
            //is this digit in row col or box?
            if (row[r][digit] == 1 |
                col[c][digit] == 1 |
                box[r/3][c/3][digit] == 1) {
                return false;
            }
            
            //otherwise, set that digit to 1 for row col and box
            row[r][digit] = 1;
            col[c][digit] = 1;
            box[r/3][c/3][digit] = 1;
        }
    }
    return true;    
}