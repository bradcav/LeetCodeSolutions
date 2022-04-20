

void dfs(int index, int *candidates, int candidatesSize, int target, int *returnSize, int **colSizes, int total, int *tmp, int tmpCount, int **res) {

    //break case: total == target, add current tmp to result
    if (total == target) {
        //add tmp to result array
        (*returnSize)++;
        //res = realloc(res, (*returnSize) * sizeof(int*));   //increase result array
        res[(*returnSize) - 1] = malloc(tmpCount * sizeof(int));
        //copy vaues in tmp to result
        for (int i = 0; i < tmpCount; i++) {
            res[(*returnSize) - 1][i] = tmp[i];
        }
        //update colSizes
        (*colSizes)[(*returnSize - 1)] = tmpCount;
        return;
    }
    
    //break case: total over taget, nothing to do
    if (total > target) {
        return;
    }
    
    //break case: index == candidatesSize, return
    if (index == candidatesSize) {
        return;
    }
    
    //1st option - allow adding elemnt at index
    tmp[tmpCount] = candidates[index];
    dfs(index, candidates, candidatesSize, target, returnSize, colSizes, total + candidates[index], tmp, tmpCount + 1, res);
    
    //2nd option - don't allow element at index
    dfs(index + 1, candidates, candidatesSize, target, returnSize, colSizes, total, tmp, tmpCount, res);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    
    int **res = malloc(200 * sizeof(int*));    //return array of int arrays
    
    //what is the smallest value in the list?
    int smallest = INT_MAX;
    for (int i = 0; i < candidatesSize; i++) {
        if (candidates[i] < smallest) {
            smallest = candidates[i];
        }
    }    
    //max nums that will go in tmp is target/smallest value + 1
    int *tmp = malloc((target/smallest + 1) * sizeof(int));      //hold current solution    
    *returnSize = 0;
    returnColumnSizes[0] = malloc(sizeof(int)*500); //500 is max     
    
    dfs(0, candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, tmp, 0, res);
    
    free(tmp);    
    return res;   
}