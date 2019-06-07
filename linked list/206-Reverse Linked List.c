//反转一个单链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
         return head;
    }
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    struct ListNode* r = q->next;

    p->next = NULL;
    while(r)
    {
        q->next = p;
        p = q;
        q = r;
        r = q->next;
    }
    q->next = p;

    return q;
}

