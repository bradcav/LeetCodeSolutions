

int firstMissingPositive(int* nums, int numsSize){
    int i;
    int j;
    //set negative values to 0, since they are not needed and the sapce can be used
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            nums[i] = 0;
        }
    }
    
    //loop list, set the corresponding index (num[i] - 1) to -ve when we see it.
    //the the value there is 0, use -(numsSize+1) since that number is not in solution set
    for (i = 0; i < numsSize; i++) {
        j = abs(nums[i]) - 1;
        if (j >= 0 && j < numsSize) {
            if (nums[j] == 0) {
                nums[j] = (numsSize + 1) * -1; 
            }
            else if (nums[j] > 0) {
                nums[j] *= -1;
            }
            
            //leave negative if negative already
        }
    }
       
    //check each number in solution set [1..len+1]
    for (i = 1; i < numsSize + 1; i++) {
        if (nums[i-1] >= 0) {
            return i;
        }
    }
    return numsSize + 1;    //all numbers 1 to len were found, so return len + 1
}