#include "stdio.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int pairSum(struct ListNode* head)
{
	fprintf(stderr, "[ERROR] >>> Entering pairSum(head=%p)\n", head);
    struct ListNode* dup = head;
    int count = 0, i = 0, max = 0;
	fprintf(stderr, "[ERROR] pairSum(head=%p): count → %d\n", head, count);
    fprintf(stderr, "[ERROR] pairSum(head=%p): dup → %p\n", head, dup);
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    int* arr = malloc(count * sizeof(int));
    while (dup != NULL)
    {
        arr[i++] = dup->val;
        dup = dup->next;
		fprintf(stderr, "[ERROR] pairSum(head=%p): dup → %p\n", head, dup);
    }
    for (i = 0; i < count / 2; ++i)
    {
        if (arr[i] + arr[count - i - 1] > max)
            max = arr[i] + arr[count - i - 1];
			fprintf(stderr, "[INFO] pairSum(head=%p): max → %d\n", head, max);
    }
	fprintf(stderr, "[WARN] <<< Exiting pairSum(head=%p)\n", head);
    return max;
}
