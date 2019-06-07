//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next==NULL)
        return head;
    struct ListNode* pre = NULL;
    struct ListNode* head_tmp = head;
    struct ListNode* cur = head;
    struct ListNode* sec = head->next;
    while(sec)
    {
        if(cur->val == sec->val)
        {
            sec = sec->next;
            while(sec && cur->val==sec->val)
            {
                sec = sec->next;
            }
            while(cur != sec)
            {
                struct ListNode* tmp = cur;
                cur = cur->next;
                free(tmp);
            }
            if(pre == NULL)
                head_tmp = cur;
            else
                pre->next=cur;
            if(sec)
                sec = sec->next;
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