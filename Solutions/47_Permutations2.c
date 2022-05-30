int fact(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

void recursivePerm(int *nums, int n, int tmpCount, int *tmp, int *resCount, int **res, int *map) {
    
    //breakcase: no more numbers to add to tmp, copy tmp to res
    if (tmpCount == n) {
        for (int i = 0; i < n; i++) {
            res[*resCount][i] = tmp[i];
        }
        (*resCount)++;
        return;
    }
    
    for (int i = 0; i < 21; i++) {
        if (map[i] > 0) {
            //printf("using number \n", i - 10);
            tmp[tmpCount] = i - 10;
            map[i]--;
            
            recursivePerm(nums, n, tmpCount + 1, tmp, resCount, res, map);
            
            map[i]++;            
        }
    }   
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //allocate output array, numsSize! possible permutations of size numsSize 
    int size = fact(numsSize);     
    int **res = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        res[i] = malloc(numsSize * sizeof(int));
    }
    
    int *tmp = malloc(numsSize * sizeof(int));
    int resCount = 0;
    
    //map each number in nums to the amount of times it appears
    //nums -10 to 10 mapped to 0 to 20 in array
    int map[21] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        map[nums[i] + 10]++;
    }   
    
    recursivePerm(nums, numsSize, 0, tmp, &resCount, res, map); 
    
    *returnSize = resCount;    
    *returnColumnSizes = malloc(resCount * sizeof(int));
    for (int i = 0; i < resCount; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    return res;
}