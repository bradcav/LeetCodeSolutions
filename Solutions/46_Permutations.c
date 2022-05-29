int fact(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

void recursivePerm(int *nums, int n, int tmpCount, int *tmp, bool *used, int *resCount, int **res) {
    
    //breakcase: no more numbers to add to tmp, copy tmp to res
    if (tmpCount == n) {
        for (int i = 0; i < n; i++) {
            res[*resCount][i] = tmp[i];
        }
        (*resCount)++;
        return;
    }
        
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            used[i] = true;
            tmp[tmpCount] = nums[i];
            recursivePerm(nums, n, tmpCount + 1, tmp, used, resCount, res);
            used[i] = false;
        }
    }   
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
        
    //allocate output array, numsSize! possible permutations of size numsSize 
    int size = fact(numsSize);     
    int **res = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        res[i] = malloc(numsSize * sizeof(int));
    }
    
    *returnSize = size;    
    *returnColumnSizes = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    int *tmp = malloc(numsSize * sizeof(int));
    int resCount = 0;
    
    //which nums have been used in current build
    bool used[numsSize];
    for (int i = 0; i < numsSize; i ++) {
        used[i] = false;
    }
        
    recursivePerm(nums, numsSize, 0, tmp, used, &resCount, res);       
    return res;
}