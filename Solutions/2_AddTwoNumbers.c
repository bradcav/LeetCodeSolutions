/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0;  //for when adding the two numbers carries to 2 digits
    int num1, num2; //ints stored in the two input lists
    int val;        //when the numbers are added, store here
    
    //create head for the return list
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    //make a pointer to head
    struct ListNode* ptr = head;
    
    //while there is still somenumber to add
    while (l1 || l2 || carry) {  
        //get the two numbers for the input lists
        if (l1) {
            num1 = l1->val;
        } else {
            num1 = 0;
        }
        if (l2) {
            num2 = l2->val;
        } else {
            num2 = 0;
        }
        
        val = num1 + num2 + carry;
        
        //set new carry and actual value to set
        carry = val / 10;
        val = val % 10;
        
        //need to make a next node
        struct ListNode* newNode = malloc(sizeof(struct ListNode));
        newNode->val = val;
        newNode->next = NULL;
        ptr->next = newNode;    //set the pointers next to this new node
        
        //update pointers
        ptr = ptr->next;    //move pointer to new node       
        //move input lists to next node
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }   
    }    
    return head->next;
}