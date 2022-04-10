int numSolutions = 0;

struct m_ListNode
{
    int a,b,c,d;
    struct m_ListNode *next;
};
struct m_ListNode* head = NULL;
struct m_ListNode* currNode;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void finder(int k, int start, int target, int* nums, int numsSize, int* quad, int quadIdx) {
    //if k > 2, need to call again
    if (k > 2) {
        //call the finder for each index except the last k-1 nums, with new target
        for (int i = start; i < numsSize - k + 1; i++) {
            //make sure this i hasnt already been used in the current position
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            quad[quadIdx] = nums[i];
            finder(k-1, i+1, target - nums[i], nums, numsSize, quad, quadIdx+1);        
        }
        return;
    }
    //BASE CASE
    //else k==2 then use 2sum method with l and r
    int l = start;
    int r = numsSize-1;
    
    while (l < r) {
        if (nums[l] + nums[r] > target) {
            r--;
        }
        else if (nums[l] + nums[r] < target) {
            l++;
        }
        else {
            //matches target 
            numSolutions++;
            
            quad[2] = nums[l];
            quad[3] = nums[r];
            //add a new node with the solution
            struct m_ListNode* newNode = malloc(sizeof(struct m_ListNode));
            newNode->a = quad[0];
            newNode->b = quad[1];
            newNode->c = quad[2];
            newNode->d = quad[3];
            newNode->next = NULL;
            
            //add new node to list
            if (head == NULL) {
                head = newNode;
            } else {
                currNode->next = newNode;
            }
            currNode = newNode;
            
            //while keeping the current first two pointers, either l or r
            l++;
            while (l < r && nums[l] == nums[l-1]) {
                //make sure the same l isnt reused
                l++;
            }
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    //sort input array
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int quad[4];
    
    finder(4, 0, target, nums, numsSize, quad, 0);
    
    *returnSize = numSolutions;
    
    *returnColumnSizes = malloc(numSolutions * sizeof(int));    
    for (int i = 0; i < numSolutions; ++i)
        (*returnColumnSizes)[i] = 4;
    
    //turn node list into array
    int** result = malloc(numSolutions * sizeof(int*));
    int i = 0;
    struct m_ListNode* itNode = head;
    while (itNode) {
        result[i] = malloc(sizeof(int) * 4);
        result[i][0] = itNode->a;
        result[i][1] = itNode->b;
        result[i][2] = itNode->c;
        result[i][3] = itNode->d;
        i++;
        itNode = itNode->next;
    }
    
    //clean up globals
    head = NULL;
    currNode = NULL;
    numSolutions = 0;
    
    return result;
}