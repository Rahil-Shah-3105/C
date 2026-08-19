/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
	fprintf(stderr, ">>> Entering hasCycle(head=%p)\n", head);
    struct ListNode *fast = head, *slow = head;
    while (slow && fast && fast->next)
	fprintf(stderr, "hasCycle(head=%d): fast → %d\n", head, fast);
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
	fprintf(stderr, "<<< Exiting hasCycle(head=%p)\n", head);
            return true;
    }
    return false;
}
