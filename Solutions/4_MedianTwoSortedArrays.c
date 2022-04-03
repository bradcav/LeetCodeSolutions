double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalNums = nums1Size + nums2Size;
    // need an array to store the merged arrays
    int merged[totalNums];
    //pointers for which number in the input arrays we are currently on
    int nums1Pointer, nums2Pointer, mergedPointer;
    
    nums1Pointer = nums2Pointer = mergedPointer = 0;
    
    //while there are still some numbers left to be merged
    while (nums1Pointer < nums1Size || nums2Pointer < nums2Size) {  
        //check if either pointer has got to the end of the array
        if (nums1Pointer >= nums1Size) {
            //just add value from nums2
            merged[mergedPointer] = nums2[nums2Pointer];
            mergedPointer++;
            nums2Pointer++;
        } 
        else if (nums2Pointer >= nums2Size) {
            //just add value from nums1
            merged[mergedPointer] = nums1[nums1Pointer];
            mergedPointer++;
            nums1Pointer++;
        } else {    //both arrays have numbers left
            //insert the lowest number of the two arrays into the merged array
            if (nums1[nums1Pointer] < nums2[nums2Pointer]) {
                merged[mergedPointer] = nums1[nums1Pointer];
                mergedPointer++;
                nums1Pointer++;
            }
            else {
                merged[mergedPointer] = nums2[nums2Pointer];
                mergedPointer++;
                nums2Pointer++;
            }
        }        
    }
    
    //get the median
    if (totalNums % 2 == 0) {
        //even number, take number between n/2 and n/2 - 1
        double n1 = (double)merged[totalNums/2];
        double n2 = (double)merged[(totalNums/2) - 1];     
        return (n1 + n2) / 2.0;
    } else {
        return (double)merged[totalNums/2];
    }  
}