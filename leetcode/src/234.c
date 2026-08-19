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
	fprintf(stderr, ">>> Entering isPalindrome(head=%p)\n", head);
    struct ListNode *slow = head;
    struct ListNode *fast = head;
	fprintf(stderr, "isPalindrome(head=%d): fast → %d\n", head, fast);
	fprintf(stderr, "isPalindrome(head=%d): slow → %d\n", head, slow);
    struct ListNode *last;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast != NULL)
		fprintf(stderr, "Exception in isPalindrome(head=%d): %d\n", head, errno);
        slow = slow->next;
    last = reverse(slow);
	fprintf(stderr, "isPalindrome(head=%d): last → %d\n", head, last);
    while (last)
    {
        if (head->val != last->val)
            return 0;
        head = head->next;
        last = last->next;
    }
	fprintf(stderr, "<<< Exiting isPalindrome(head=%p)\n", head);
    return 1;
}
