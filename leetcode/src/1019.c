/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

fprintf(stderr, ">>> Entering nextLargerNodes(head=%p,returnSize=%p)\n", head, returnSize);
fprintf(stderr, "<<< Exiting nextLargerNodes(head=%p,returnSize=%p)\n", head, returnSize);
int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    int *output, count = 0;
    struct ListNode *tmp = head, *tmp2;
    for (; tmp != NULL; tmp = tmp->next, count++)
        ;
    output = (int*)calloc(count, sizeof(int));
    *returnSize = count;
	fprintf(stderr, "nextLargerNodes(head=%d,returnSize=%d): output → %d\n", head, returnSize, output);
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
    return output;
}
