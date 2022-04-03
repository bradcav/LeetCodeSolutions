char * convert(char * s, int numRows){  
    int len = strlen(s);
    //special case where numRows = 1, just return input
    if (numRows == 1 || len == 1) {
        return s;
    }
    
    //declare a matrix with number of rows needed, and columns of size len - init
    //save mem? zigzag row cant have more than half of the chars
    char zigzag[numRows][len/2 + 2];
    memset(zigzag, '\0', numRows*(len/2 + 2));
    int rowPointer[numRows];  //store the current pointer for each output row
    memset(rowPointer, 0, sizeof(int)*numRows);
    
    int currRow = 0;
    int up = 1;
    //iterate through the input string
    for (int i = 0; i < len; i++) {
        //printf("current row: %d, pointer: %d\n", currRow, rowPointer[currRow]);
        zigzag[currRow][rowPointer[currRow]] = s[i];     //set the current row char
        rowPointer[currRow]++;  //update pointer for that row
        //update currRow
        if (up) {
            currRow++;
            if (currRow == numRows - 1) {
                up = 0;
            }
        } else {
            currRow--;
            if (currRow == 0) {
                up = 1;
            }
        }     
    }
     
    char *result = calloc(len+1, sizeof(char));    
    int j;
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        j = 0;
        while (zigzag[i][j]) {
            result[k] = zigzag[i][j];
            k++;
            j++;
        }
    }
    return result;
}