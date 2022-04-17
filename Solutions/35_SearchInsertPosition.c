/* O(log n) - bin search */

int searchInsert(int* nums, int numsSize, int target){
       
    int l, r, m;
    
    l = 0;
    r = numsSize - 1;
    
    while (l <= r) {
        m = (l + r) / 2;
        
        if (nums[m] == target) {
            return m;
        }
        
        //case where one number remains
        if (l == r) {
            if (target > nums[l]) {
                return l + 1;
            } else {
                return l;
            }
        }
        
        //case where whole current list is greater than target
        if (nums[l] > target && nums[r] > target) {
            return l;
        }
        
        //case where whole current list less than target
        if (nums[l] < target && nums[r] < target) {
            return r + 1;
        }
        
        //update l or r to cut list in half
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }        
    }      
    return 0;
}