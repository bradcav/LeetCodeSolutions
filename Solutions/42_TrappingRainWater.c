

int trap(int* height, int heightSize){
    
    int leftMax[heightSize];
    int rightMax[heightSize];
    int minLR[heightSize];
    
    int currMax = 0;
    int i;
    
    //set the max height to the left of each height
    for(i = 0; i < heightSize; i++) {
        leftMax[i] = currMax;
        if (currMax < height[i]) {
            currMax = height[i];
        }
    }
    
    currMax = 0;
    //set max height to the right for each height
    for(i = heightSize - 1; i >= 0; i--) {
        rightMax[i] = currMax;
        if (currMax < height[i]) {
            currMax = height[i];
        }
    }
    
    //get the min of the max Left and Rights
    for( i = 0; i < heightSize; i++) {
        if (leftMax[i] < rightMax[i]) {
            minLR[i] = leftMax[i];
        } else {
            minLR[i] = rightMax[i];
        }
    }
    
    int total = 0;  
    //calulate how much water each position can hold
    for (i = 0; i < heightSize; i++) {
        if (minLR[i] - height[i] > 0) {
            total += minLR[i] - height[i];
        }
    }
    return total;    
}