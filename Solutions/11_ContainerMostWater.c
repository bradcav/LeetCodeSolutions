

int maxArea(int* height, int heightSize){
    //start at the edges and work inwards shifting the smallest out of left and right height
    
    int result = 0;
    int left = 0;
    int right = heightSize -1;
    int area;
    
    while (left != right) {
        //if left is smallest
        if (height[left] < height[right]) {
            area = (right - left) * height[left];
            if (area > result) {
                result = area;
            }
            //move left pointer by 1
            left++;
        } else {
            //right is smaller or they are equal
            area = (right - left) * height[right];
            if (area > result) {
                result = area;
            }
            //move left pointer by 1
            right--;
        }
    }
    
    return result;
}