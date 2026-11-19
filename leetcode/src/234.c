#include "stdio.h"
#include "errno.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *res = NULL;
    while (head)
    {
        struct ListNode *pre_node = head;
        head = head->next;
        pre_node->next = res;
        res = pre_node;
    }
    return res;
}
bool isPalindrome(struct ListNode *head)
{
	fprintf(stderr, "[ERROR] >>> Entering isPalindrome(head=%p)\n", head);
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *last;
    while (fast && fast->next)
    {
        slow = slow->next;
		fprintf(stderr, "[ERROR] isPalindrome(head=%p): slow → %p\n", head, slow);
        fast = fast->next->next;
		fprintf(stderr, "[ERROR] isPalindrome(head=%p): fast → %p\n", head, fast);
    }
    if (fast != NULL)
        slow = slow->next;
    last = reverse(slow);
	fprintf(stderr, "[ERROR] isPalindrome(head=%p): last → %p\n", head, last);
    while (last)
    {
        if (head->val != last->val)
            return 0;
        head = head->next;
        last = last->next;
    }
	fprintf(stderr, "[WARN] <<< Exiting isPalindrome(head=%p)\n", head);
    return 1;
}
