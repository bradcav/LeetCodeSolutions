/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* getKthNode(struct ListNode* curr, int k) {
    while (curr && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    
    //dummy node before the head
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    
    //need a pointer before the group of k pointing to the group
    //and the node after group
    //at first, before is the dummy node
    struct ListNode *nBeforeGroup = dummy;
    struct ListNode *nAfterGroup;
    
    //two pointers for the two nodes we are reversing, and a temp
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode *tmp;
    
    //need a pointer for the node at end of group (kth node)
    struct ListNode *kth;
    
    while (1) {
        //get node at end of k group
        kth = getKthNode(nBeforeGroup, k);        
        //if kth is null, then we are done
        if (kth == NULL) {
            break;
        }
        //the node after the group is node after kth
        nAfterGroup = kth->next;
        
        //reverse the group. start p1 as the first node of the next group
        p1 = nAfterGroup;
        //p2 points to first node in group to be reversed
        p2 = nBeforeGroup->next;
        
        while (p2 != nAfterGroup) {
            tmp = p2->next;     //save node after the curr node
            p2->next = p1;      //point the curr node backwards (to nAfterGroup on first iteration)
            p1 = p2;            //move p1 forward
            p2 = tmp;           //move p2 forward
        }
        
        //done reversing so the node before the group needs updating
        tmp = nBeforeGroup->next;   //nbeforegroup->next is now last node in current group so save it
        nBeforeGroup->next = kth;   //nBeforeGroup needs to point to kth which is now start of group
        nBeforeGroup = tmp;
    }
    
    //node after dummy is the real head of the list
    return dummy->next;
}