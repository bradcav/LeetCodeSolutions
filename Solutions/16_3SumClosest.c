int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target){
    //first, sort the array
    qsort(nums, numsSize, sizeof(int), compare);    
    
    int closest = INT_MAX, sum, result;
    int left, right;
    
    //iterate each i, at each i, move left and right pointers to get closer to target
    for (int i = 0; i < numsSize - 2; i++) {
        //make sure we haven't already used this value at i
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        left = i + 1;
        right = numsSize - 1;
        
        while(left < right) {
            sum = nums[i] + nums[left] + nums[right];
            
            //is sum correct? then return the target
            if (sum == target) {
                return target;
            }
            
            //is the current difference smaller than the current closest?
            if (abs(sum-target) < closest) {
                closest = abs(sum-target);  //update the new closest distance
                result = sum;               //save the sum with the smallest distance
            }
                       
            //sum was too small
            if (sum < target) {         
                left++;
            }
            
            //sum was too big
            if (sum > target) {
                right--;
            }     
        } 
    }    
    return result;    
}