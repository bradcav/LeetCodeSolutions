int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

struct m_ListNode
{
    int i;
    int left;
    int right;
    struct m_ListNode *next;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
        
    //sort the input array
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int numSolutions = 0;   
    
    struct m_ListNode* head = NULL;
    struct m_ListNode* currNode, *itNode;
    
    //3 pointers, i which goes from left to right (ascending),
    // left which starts at i+1, right which starts at the end of array.
    //if i + left + right is 0, then add that 
    //if sum is < 0, incr left pointer, if sum > 0, decr right pointer
    int left, right, sum;
    for (int i = 0; i < numsSize - 2; i++) {
        
        //if we have already used the current i (duplicate), then skip this iteration
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        left = i + 1;
        right = numsSize - 1;
        
        //left needs to always be lower than right
        while (left < right) {
            
            //calculate current sum
            sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                //add this solution, keep shifting l and r until they are different nums
                numSolutions++;
                
                //create a new node and add it to list
                struct m_ListNode* newNode = (struct m_ListNode *)malloc(sizeof(struct m_ListNode));
                newNode->i = nums[i];
                newNode->left = nums[left];
                newNode->right = nums[right];
                newNode->next = NULL;
                
                //add new node to list
                if (head == NULL) {
                    head = newNode;
                } else {
                    currNode->next = newNode;
                }
                currNode = newNode;                
                
                //is the next left pointer the same?
                while (left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                //is next right pointer the same?
                while (left < right && nums[right] == nums[right-1]) {
                    right--;
                }
                
                //shift the left and right pointers, knowing they will be different to before
                left++;
                right--;
            } 
            else if (sum < 0) {
                //need to increase sum by moving up left pointer
                left++;
            } else {
                right--;
            }
            
        }     
    }
    
    *returnSize = numSolutions;
    
    *returnColumnSizes = (int*)malloc(numSolutions * sizeof(int));    
    for (int i = 0; i < numSolutions; ++i)
        (*returnColumnSizes)[i] = 3;    
    
    //create the array from the node list
    int** result = (int**)malloc(numSolutions * sizeof(int*));
    int i = 0;
    itNode = head;
    while (itNode) {
        result[i] = (int*)malloc(sizeof(int) * 3);
        result[i][0] = itNode->i;
        result[i][1] = itNode->left;
        result[i][2] = itNode->right;
        i++;
        itNode = itNode->next;
    }    
    return result;    
}