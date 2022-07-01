

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    //start with the outer rows and cols, rotating in a square, then move inwards    
    //keep track of left, right, top and bottom pointers
    int left = 0;
    int right = matrixSize - 1;
    int top, bottom;
    int temp;   //temp value while moving items
    
    //as long as l < r, there is still a square to rotate
    while (left < right) {
        //each square will have r - l - 1 sets of elements to rotate
        for (int i = 0; i < right - left; ++i) {
            //set the top and bottom pointers
            top = left;
            bottom = right;
            
            //save top left 
            temp = matrix[top][left + i];
            
            //bottom left into top left
            matrix[top][left + i] = matrix[bottom - i][left];
            
            //bottom right into bottom left
            matrix[bottom - i][left] = matrix[bottom][right - i];
            
            //top right into bottom right
            matrix[bottom][right - i] = matrix[top + i][right];
            
            //temp into top right
            matrix[top + i][right] = temp;

        }    
        //update pointers to next inner square
        ++left;
        --right;
    }  
}