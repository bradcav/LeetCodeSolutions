/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //two pointers going through the list
    struct ListNode *lead;
    struct ListNode *trail;
    
    //lead goes along list, trail stays n steps behind
    //when lead reaches end, trail is on node to be removed    
    int steps = 0;          //how many nodes have been counted?
    
    lead = head;
    trail = head;
    while (lead) {
        if (steps > n) {
            trail = trail->next;    //advance trail once enough steps have been taken
        }
        lead = lead->next;
        steps++;
    }
    
    //if steps = 1, only 1 node, return null
    if (steps == 1) {
        return NULL;
    }
    //if steps == n then deleting first node
    if (steps == n) {
        head = head->next;
        return head;
    }
    //otherwise, the next node of trail is one to be deleted
    trail->next = trail->next->next;      
    return head;
}