int removeElement(int* nums, int numsSize, int val){
    int i;
    int j = 0;
    for (i = 0; i < numsSize; i++) {
        //skip index where the element == val
        while (j < numsSize && nums[j] == val) {
            j++;
        }
        //no more elements to add
        if (j >= numsSize) {
            break;
        }
        
        nums[i] = nums[j];
        j++;
    }  
    return i;
}