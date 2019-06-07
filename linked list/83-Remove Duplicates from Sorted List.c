//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
        return head

    struct ListNode* pre = NULL;
    struct ListNode* head_tmp = head;
    struct ListNode* cur = head;
    struct ListNode* sec = head->next;

    while(sec)
    {
        if (cur->val == sec->val)
        {
            sec = sec->next;
            while(sec && cur->val == sec->val)
            {
                sec = sec->next;
            }
            while(cur->next != sec)
            {
                struct ListNode* tmp = cur;
                cur = cur->next;
                free(tmp);
                tmp = NULL;
            }
            if(pre == NULL)
            {
                head_tmp = cur;
            }
            else
            {
                pre->next = cur;
            }
        }
        else
        {
            pre = cur;
            cur = cur->next;
            sec = sec->next;
        }
    }
    return head_tmp;
}