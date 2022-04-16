int binSearch(int *nums, int numsSize, int target, bool goLeft) {
    int l, r, m, i;
    
    l = 0;
    r = numsSize - 1;
    i = -1;
    
    while (l <= r) {
        m = (l + r) / 2;
        
        if (nums[m] < target) {
            l = m + 1;
        } else if (nums[m] > target) {
            r = m - 1;
        } else {
            //target found, update i and keep going either left or right to find furthest target
            i = m;
            if (goLeft) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
    
    return i;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    
    /* O(log n) - probably binary search */ 
    int *res = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    //search twice, once for the right most index of target, once for left most index of target
    
    res[0] = binSearch(nums, numsSize, target, true);
    res[1] = binSearch(nums, numsSize, target, false);
     
    return res;
}