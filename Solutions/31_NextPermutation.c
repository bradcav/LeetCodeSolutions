void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void reverse(int *nums, int size) {
    int left = 0;
    int right = size - 1;
    
    while (left < right) {
        swap(nums, left, right);
        right--;
        left++;
    }
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void nextPermutation(int* nums, int numsSize){
    
    /* special case - only one element, return */
    if (numsSize <= 1) {
        return;
    }
    
    //go along list and find the last index i where nums[i] < nums[i+1].
    //store i in SP and i+1 in next lowest pointer.
    //if i and i+1 not ascending, is i+1 lower than current NLP but greater than SP - this will be the right one to swap
    //remaining values in list after SP need to be in ascending order to get lowest value
    //if no nums[i] < nums[i+1] then list is in descending (highest value) and swapPointer will not be changed
    //in this case, reverse whole list
    
    int SP = numsSize;     //swap pointer index of i to swap i and i+1
    int NLP = numsSize;     //next lowest pointer
    //get position of elements to swap
    for (int i = 0; i < numsSize - 1; i++) {
        //are nums[i] and nums[i+1] ascending?
        if (nums[i] < nums[i+1]) {
            SP = i;
            NLP = i + 1;
            continue;
        }
        
        //otherwise is nums[i+1] greater than nums[SP] but lower than nums[NLP]?
        //only do if SP and NLP have already been set once
        if (SP != numsSize && nums[i+1] < nums[NLP] && nums[i+1] > nums[SP] ) {
            NLP = i + 1;
        }
    }
    
    //if swapPointer is still numsSize then there was no place where nums[i] < nums[i+1]
    if (SP == numsSize) {
        reverse(nums, numsSize);
        return;
    }
    
    //swap elements at SP and NLP
    swap(nums, SP, NLP);
    
    //is there at least 2 values after SP? - sort remaining nums
    if (numsSize - SP > 2) {
        qsort(&nums[SP + 1], numsSize - SP - 1, sizeof(int), cmpfunc);
    }   
}