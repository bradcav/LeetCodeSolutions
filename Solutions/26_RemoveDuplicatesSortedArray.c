

int removeDuplicates(int* nums, int numsSize){
    //two pointers, i for writing value at each position, j to advance through the array to find end of duplicates   
    int num;
    int j = 0;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        num = nums[j];  //save the current number for finding duplicates
        //advance j until it is past the duplicates, or goes out of bounds
        while (j < numsSize && num == nums[j]) {
            j++;
        }
        //overwrite the element at pos i
        nums[i] = num;
        
        //is j at the end?
        if (j == numsSize) {
            break;
        }
    }
    return i + 1; 
}