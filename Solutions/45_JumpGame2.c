
void bruteForce(int *nums, int n, int curr, int jumps, int *res) {     
    //break case, gone out of bound
    if (curr >= n) {
        return;
    }
    
    //break case, on landed on a zero before end of array
    if (curr < n - 1 && nums[curr] == 0) {
        return;
    }
    
    //break case, landed on or past last element, so it is possible
    if (curr >= n - 1) {
        if (jumps < *res) {
            *res = jumps;
        }
        return;
    }
    
    int maxJump = nums[curr];    
    for (int i = maxJump; i > 0; i--) {
        bruteForce(nums, n, curr + i, jumps + 1, res);
    }  
}

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int jump(int* nums, int numsSize){
    //recursive brute force too slow
    /*
    int res = INT_MAX;      
    bruteForce(nums, numsSize, 0, 0, &res); 
    return res;
    */
    
    //greedy BFS solution - O(n)
    
    int res = 0;
    int l, r;   //pointers for current window
    l = r = 0;
    
    int farthest;   //to store the farthest we can jump from current window
    
    //while the window hasnt reached the last index yet
    while (r < numsSize - 1) {
        farthest = 0;
        //try each item in current window - how far can we reach from this window
        for (int i = l; i <= r; i++) {
            farthest = MAX(farthest, i + nums[i]);
        }
        
        //update pointers to next window and res
        l = r + 1;
        r = farthest;
        res++;
    }  
    return res;
}