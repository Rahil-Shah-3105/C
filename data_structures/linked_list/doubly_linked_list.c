/**
 * @file
 * @brief Implementation of [Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list)
 * @details
 * A doubly linked list is a data structure with a sequence
 * of components called nodes. Within that nodes there are
 * three elements: a value recorded, a pointer to the next
 * node, and a pointer to the previous node.
 *
 * In this implementation, the functions of creating the list,
 * inserting by position, deleting by position, searching 
 * for value, printing the list, and an example of how the
 * list works were coded.
 *
 * @author  [Gabriel Mota Bromonschenkel Lima](https://github.com/GabrielMotaBLima)
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Doubly linked list struct
 */
typedef struct list
{
    double value;               ///< value saved on each node
    struct list *next, *prev;   ///< directing to other nodes or NULL
} List;

/**
 * @brief   Create list function, a new list containing one node will be created
 * @param   value       a value to be saved into the first list node
 * @returns new_list    the list created
 */
List *create(double value);

/**
 * @brief   Insertion by position into the list function
 * @param   list    a doubly linked List
 * @param   value   a value to be inserted into the list
 * @param   pos     a position into the list for value insertion
 * @returns list    the input list with a node more or the same list
 */
List *insert(List *list, double value, int pos);

/**
 * @brief   Deletion by position into the list function
 * @param   list    a doubly linked List
 * @param   pos     a position into the list for value Deletion
 * @returns list    the input list with deleted values or the same list
 */
List *delete(List *list, int pos);

/**
 * @brief   Search value into the list function
 * @param   list    a doubly linked list
 * @param   value   a value to be looked for into the list
 * @returns `1`     if the looked up value exists
 * @returns `0`     if the looked up value doesn't exist
 */
int search(List *list, double value);

/**
 * @brief   Print list function
 * @param   list    a doubly linked List
 * @returns void
 */
void print(List *list);

/**
 * @brief   Example function
 * @returns void
 */
void example();

/**
 * @brief   Main function
 * @returns 0   on exit
 */
int main()
{
	fprintf(stderr, ">>> Entering main()\n");
    // examples for better understanding
    example();
    // code here
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}

/**
 * @brief   Create list function, a new list containing one node will be created
 * @param   value       a value to be saved into the first list node
 * @returns new_list    the list created
 */
fprintf(stderr, ">>> Entering create(value=%f)\n", value);
fprintf(stderr, "<<< Exiting create(value=%f)\n", value);
List *create(double value)
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->value = value;
    new_list->next = NULL;
    new_list->prev = NULL;
    return new_list;
}

/**
 * @brief   Insertion by position into the list function
 * @param   list    a doubly linked List
 * @param   value   a value to be inserted into the list
 * @param   pos     a position into the list for value insertion
 * @returns list    the input list with a node more or the same list
 */
fprintf(stderr, ">>> Entering insert(list=%p,value=%f,pos=%d)\n", list, value, pos);
fprintf(stderr, "Exception in insert(list=%d,value=%d,pos=%d): %d\n", list, value, pos, errno);
fprintf(stderr, "insert(list=%d,value=%d,pos=%d): list → %d\n", list, value, pos, list);
fprintf(stderr, "<<< Exiting insert(list=%p,value=%f,pos=%d)\n", list, value, pos);
List *insert(List *list, double value, int pos)
{
    // list NULL case
    if (list == NULL)
    {
		fprintf(stderr, "Exception in insert(list=%d,value=%d,pos=%d): %d\n", list, value, pos, errno);
        list = create(value);
        return list;
    }

    // position existing case
    if (pos > 0)
    {
        List *cpy = list, *tmp = cpy;
		fprintf(stderr, "insert(list=%d,value=%d,pos=%d): cpy → %d\n", list, value, pos, cpy);
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL)
        {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1)
        {
            List *new_node = create(value);
            new_node->next = cpy;
            cpy->prev = new_node;
            list = new_node;
            return list;
        }

        // position existing in list range case
        if (size + 2 > pos)
        {
            while (cpy->next != NULL && index < pos)
            {
                flag++;
                index++;
                cpy = cpy->next;
            }

            List *new_node = (List *)malloc(sizeof(List));
            new_node->value = value;

            // position into list with no poiting for NULL
            if (flag == pos)
            {
                cpy->prev->next = new_node;
                new_node->next = cpy;
                new_node->prev = cpy->prev;
                cpy->prev = new_node;
            }

            // last position case
            if (flag < pos)
            {
                new_node->next = cpy->next;
                new_node->prev = cpy;
                cpy->next = new_node;
            }
        }
        return list;
    }
}

/**
 * @brief   Deletion by position into the list function
 * @param   list    a doubly linked List
 * @param   pos     a position into the list for value Deletion
 * @returns list    the input list with deleted values or the same list
 */
fprintf(stderr, ">>> Entering delete(list=%p,pos=%d)\n", list, pos);
fprintf(stderr, "Exception in delete(list=%d,pos=%d): %d\n", list, pos, errno);
        fprintf(stderr, "<<< Exiting delete(list=%p,pos=%d)\n", list, pos);
fprintf(stderr, "delete(list=%d,pos=%d): cpy → %d\n", list, pos, cpy);
fprintf(stderr, "Exception in delete(list=%d,pos=%d): %d\n", list, pos, errno);
List *delete(List *list, int pos)
{
    // list NULL case
    if (list == NULL)
        fprintf(stderr, "<<< Exiting delete(list=%p,pos=%d)\n", list, pos);
        return list;

    // position existing case
    if (pos > 0)
    {
        List *cpy = list, *tmp = cpy;
        int flag = 1, index = 1, size = 0;

        while (tmp != NULL)
        {
            size++;
            tmp = tmp->next;
        }

        // first position case
        if (pos == 1)
        {
            if (size == 1)
                return NULL;
            cpy = cpy->next;
            cpy->prev = NULL;
            return cpy;
        }

        // position existing in list range case
        if (size + 2 > pos)
        {
            while (cpy->next != NULL && index < pos)
            {
                flag++;
                index++;
                cpy = cpy->next;
            }

            if (flag == pos)
            {
                // position into list with no poiting for NULL
                if (cpy->next != NULL)
                {
					fprintf(stderr, "Exception in delete(list=%d,pos=%d): %d\n", list, pos, errno);
                    cpy->prev->next = cpy->next;
                    cpy->next->prev = cpy->prev;
                }

                // last position case
                else
                    cpy->prev->next = NULL;
            }
        }
        return list;
    }
}

/**
 * @brief   Search value into the list function
 * @param   list    a doubly linked list
 * @param   value   a value to be looked for into the list
 * @returns `1`     if the looked up value exists
 * @returns `0`     if the looked up value doesn't exist
 */
int search(List *list, double value)
{
	fprintf(stderr, ">>> Entering search(list=%p,value=%f)\n", list, value);
    if (list == NULL)
        return 0;
    if (list->value == value)
		fprintf(stderr, "Exception in search(list=%d,value=%d): %d\n", list, value, errno);
        fprintf(stderr, "<<< Exiting search(list=%p,value=%f)\n", list, value);
        return 1;
    search(list->next, value);
}

/**
 * @brief   Print list function
 * @param   list    a doubly linked List
 * @returns void
 */
void print(List *list)
{
	fprintf(stderr, ">>> Entering print(list=%p)\n", list);
    if (list != NULL)
    {
        printf("%f\t", list->value);
        print(list->next);
    }
	fprintf(stderr, "<<< Exiting print(list=%p)\n", list);
}

/**
 * @brief   Example function
 * @returns void
 */
void example()
{
	fprintf(stderr, ">>> Entering example()\n");
    List *my_list = NULL;
    double node_value = 0;
    int searching;

    my_list = create(node_value);
    my_list = insert(my_list, 3, 1);
    my_list = insert(my_list, 5, 3);
    my_list = insert(my_list, 10, 3);
    my_list = insert(my_list, 20, 3);

	fprintf(stderr, "example(): my_list → %d\n", my_list);
    print(my_list);
    searching = search(my_list, 20);
    printf("\n%d\n", searching);

    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);
    my_list = delete (my_list, 1);

    print(my_list);
	fprintf(stderr, "example(): searching → %d\n", searching);
    searching = search(my_list, 20);
	fprintf(stderr, "<<< Exiting example()\n");
    printf("\n%d\n", searching);
}
