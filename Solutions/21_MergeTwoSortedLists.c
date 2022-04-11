/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    //edge cases, both are empty, return null
    //either one is empty, return the other list
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    
    //declare head of output list and currNode
    struct ListNode *head = NULL;
    struct ListNode *currNode;
    
    //while either list has items, take the smallest of the two and add into list
    while (list1 || list2) {
        //either list is empty so just add next node from the other
        if (list1 == NULL) {
            currNode->next = list2;
            currNode = currNode->next;
            list2 = list2->next;
            continue;
        }
        if (list2 == NULL) {
            currNode->next = list1;
            currNode = currNode->next;
            list1 = list1->next;
            continue;
        }
        
        //find the smaller value
        if (list1->val <= list2->val) {
            if (head == NULL) {
                head = list1;
            } else {
                currNode->next = list1;
            }
            currNode = list1;
            list1 = list1->next;
            continue;
        } else {
            if (head == NULL) {
                head = list2;
            } else {
                currNode->next = list2;
            }
            currNode = list2;
            list2 = list2->next;
        }
    }
    return head;
}