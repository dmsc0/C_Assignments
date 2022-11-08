/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* result = head;

    int transport = 0;
    while(l1 != NULL || l2 != NULL || transport != 0)
    {
        int sum = ( (l1 == NULL? 0 : l1->val) + (l2 == NULL? 0 : l2->val) + transport );
        transport = sum / 10;
        sum = sum % 10;
      
        result->next = malloc(sizeof(struct ListNode));
        result->next->val = sum;
        result->next->next = NULL;

        result = result->next;
        if (l1 != NULL) l1=l1->next;
        if (l2 != NULL) l2=l2->next;
    }
    
    result = head->next;

    return result;
}
