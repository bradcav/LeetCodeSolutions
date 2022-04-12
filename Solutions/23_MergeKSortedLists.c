/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *head = NULL;
    struct ListNode *currNode = NULL;
    
    //if one list is empty, just return the other
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    while (l1 || l2) {
        if (l1 == NULL) {
            currNode->next = l2;
            currNode = currNode->next;
            l2 = l2->next;
            continue;
        }
        if (l2 == NULL) {
            currNode->next = l1;
            currNode = currNode->next;
            l1 = l1->next;
            continue;
        }
        
        //find the smaller value
        if (l1->val <= l2->val) {
            if (head == NULL) {
                head = l1;
            } else {
                currNode->next = l1;
            }
            currNode = l1;
            l1 = l1->next;
        } else {
            if (head == NULL) {
                head = l2;
            } else {
                currNode->next = l2;
            }
            currNode = l2;
            l2 = l2->next;
        }
    }  
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    if (listsSize < 1) {
        struct ListNode* empty = NULL;
        return empty;
    }
    
    //how many lists to be merged?
    int count = listsSize;
      
    while (count > 1) {        
        //steps of two merging list i and i+1
        for (int i = 0; i < count; i+=2) {
            //make sure l2 is not out of bounds
            //pass null if it is
            //replace the lists e.g. lists[0] and lists[1] are merged into lists[0]. 
            //lists[2] and lists[3] are merged into lists[1]
            if (i+1 >= count) {
                lists[(i+1)/2] = mergeLists(lists[i], NULL); 
            } else {
                lists[(i+1)/2] = mergeLists(lists[i], lists[i+1]); 
            }                              
        }
        //half the count
        count = (count + 1) / 2;
    }    
    //first item of lists will now hold the whole sorted list
    return lists[0];   
}