#include "stdio.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
	fprintf(stderr, "[ERROR] >>> Entering nextLargerNodes(head=%p,returnSize=%p)\n", head, returnSize);
    int *output, count = 0;
    struct ListNode *tmp = head, *tmp2;
    for (; tmp != NULL; tmp = tmp->next, count++)
        ;
    output = (int*)calloc(count, sizeof(int));
	fprintf(stderr, "[ERROR] nextLargerNodes(head=%p,returnSize=%p): output → %p\n", head, returnSize, output);
	fprintf(stderr, "[DEBUG] nextLargerNodes(head=%p,returnSize=%p): output → %p\n", head, returnSize, output);
    *returnSize = count;
    for (tmp = head, count = 0; tmp->next != NULL; tmp = tmp->next, count++)
    {
        for (tmp2 = tmp->next; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (tmp2->val > tmp->val)
            {
                output[count] = tmp2->val;
                break;
            }
        }
    }
	fprintf(stderr, "[WARN] <<< Exiting nextLargerNodes(head=%p,returnSize=%p)\n", head, returnSize);
    return output;
}
