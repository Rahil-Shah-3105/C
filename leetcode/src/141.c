#include "stdio.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
	fprintf(stderr, "[ERROR] >>> Entering hasCycle(head=%p)\n", head);
    struct ListNode *fast = head, *slow = head;
    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
		fprintf(stderr, "[ERROR] hasCycle(head=%p): fast → %p\n", head, fast);
        slow = slow->next;
        if (fast == slow)
            return true;
    }
	fprintf(stderr, "[WARN] <<< Exiting hasCycle(head=%p)\n", head);
    return false;
}
