struct m_ListNode
{
    char* str;
    struct m_ListNode *next;
};
struct m_ListNode* head = NULL;
struct m_ListNode* currNode;

void backtrack(int n, int nOpen, int nClosed, char *tmp, int tmpIdx, int *count) {
    //break case, number of open and num closed = n
    if (nOpen == n && nClosed == n) {
        //create new node and add to list
        (*count)++;             //incr solutions count
        tmp[tmpIdx] = '\0';     //add null termination
        
        //create a new node
        struct m_ListNode* newNode = (struct m_ListNode *)malloc(sizeof(struct m_ListNode)); 
        //allocate mem for string solution of new node
        newNode->str = malloc(strlen(tmp) + 1);
        strcpy(newNode->str, tmp);      //copy the temp into new node    
        newNode->next = NULL;
        //add new node to list
        if (head == NULL) {
            head = newNode;
        } else {
            currNode->next = newNode;
        }
        currNode = newNode;
        return;      
    }
    
    //can add open if nOpen < n
    if (nOpen < n) {
        tmp[tmpIdx] = '(';
        backtrack(n, nOpen+1, nClosed, tmp, tmpIdx+1, count);
    }
    
    //can only add closed if closed < open
    if (nClosed < nOpen) {
        tmp[tmpIdx] = ')';
        backtrack(n, nOpen, nClosed+1, tmp, tmpIdx+1, count);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    
    //tmp for building the string for solutions
    //each solution has n*2 chars, allow space for null termination
    char *tmp = (char*)malloc(2*n*sizeof(char) + 1);
    
    //keep track of num of solutions
    int count = 0;
        
    backtrack(n, 0, 0, tmp, 0, &count);
    
    //declare mem for output arr
    char **result = (char**)malloc(count * sizeof(char*));    
    //convert list to array
    int i = 0;
    struct m_ListNode* itNode = head;
    while (itNode) {
        result[i] = (char*)malloc(2*n*sizeof(char));
        result[i] = itNode->str;
        i++;
        itNode = itNode->next;
    }
    
    //clean up globals
    head = NULL;
    currNode = NULL;
    free(itNode);
    
    *returnSize = count;
    return result;   
}