/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    
    struct ListNode* itNode;
    //p1 and p2 are the nodes to swap
    struct ListNode* p1;
    struct ListNode* p2;
    struct ListNode* dummy;
    
    //dummy node before head
    dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    //itNode points to node before two to swap
    itNode = dummy;
    p1 = itNode->next;
    if (p1) {
        p2 = p1->next;
    }
    
    while (p1 && p2) {
        //swap the nodes
        p1->next = p2->next;
        p2->next = p1;
        //does head need updating?
        if (p1 == head) {
            head = p2;
        }
        //p1 is now node before next two to swap, update itNode
        itNode = p1;
        
        //update p1 and p2
        p1 = itNode->next;
        if (p1) {
            p2 = p1->next;
        } else {
            p2 = NULL;
        }
        
        //if there are two more, then current node needs to point to the second one, 
        if (p1 && p2) {
            itNode->next = p2;
        }
    }
   
    return head;    
}