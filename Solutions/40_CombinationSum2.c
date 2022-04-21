int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** colSizes, int total, int index, int *tmp, int tmpCount, int **res) {   
    //break: total == target, add to result
    if (total == target) {
        //printf("curr total: %d, curr index: %d, tmpCount: %d, solutions: %d\n", total, index, tmpCount, *returnSize);
        //add solution
        (*returnSize)++;
        res[(*returnSize) - 1] = malloc(tmpCount * sizeof(int));
        //copy vaues in tmp to result
        for (int i = 0; i < tmpCount; i++) {
            res[(*returnSize) - 1][i] = tmp[i];
        }
        //update colSizes
        (*colSizes)[(*returnSize - 1)] = tmpCount;
        return;
    }
    //break: index == candidate size, no more items left
    if (index == candidatesSize) {
        return;
    }    
    //break: total > target, return
    if (total > target) {
        return;
    }
    
    //loop from current index to candidate sizes, each one adding curr item to total and calling the dfs with the next item
    //need a way to skip the index if value already used - first iteration will use repeated value, others wont
    int prev = -1;
    for (int i = index; i < candidatesSize; i++) {
        if (candidates[i] == prev) {
            continue;
        }
        tmp[tmpCount] = candidates[i];
        dfs(candidates, candidatesSize, target, returnSize, colSizes, total + candidates[i], i + 1, tmp, tmpCount + 1,                  res);
        prev = candidates[i];
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

    //sort array first to avoid duplicate solutions
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    
    int **res = malloc(250 * sizeof(int*));    //return array of int arrays
    
    int *tmp = malloc(candidatesSize * sizeof(int));   //solutions will have max len of candidatesSize
    
    *returnSize = 0;
    returnColumnSizes[0] = malloc(300 * sizeof(int)); 
    
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, tmp, 0, res);
    
    free(tmp);
    return res;
    
    
}