int search(int* nums, int numsSize, int target){
    /* O(log n) so most likely a binary search solution */   
    
    //consider list with 2 sorted portions, left and right, split where the pivot is    
    //init left, right and mid pointers
    int l = 0;
    int r = numsSize - 1;    
    
    while (l <= r) {
        //get middle value
        int m = (r + l) / 2;
        // did we find target?
        if (nums[m] == target) {
            return m;
        }
        //is m in the left or right side of the pivot point?
        if (nums[m] >= nums[l]) {
            //left portion
            //if target is greater than mid, then it must be to the right, since the left portion is sorted
            //if target less than left most value, must be to the right
            if ((target > nums[m]) | (target < nums[l])) {
                l = m + 1;
            } else {
                //must be in the left section
                r = m - 1;
            }           
        } else {
            //right portion
            if ((target > nums[r]) | (target < nums[m])) {
                //must be to the left
                r = m - 1;
            } else {
                //to the right
                l = m + 1;
            }
        }
    }
    
    //num not in list
    return -1;
}