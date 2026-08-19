/*
 * CArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 19/03/2018
 *
 * Modified by: Leonardo Vencovsky
 * Last modified: 19/03/2018
 *
 * Array Implementations in C
 *
 * Compiled in Visual Studio 2017
 *
 */

/*
Return Codes

-1 - Array Erased
0 - Success
1 - Invalid Position
2 - Position already initialized (use update function)
3 - Position not initialized (use insert function)
4 - Position already empty
5 - Array is full

*/

#include "carray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(CArray *array, int position1, int position2);

fprintf(stderr, ">>> Entering getCArray(size=%d)\n", size);
fprintf(stderr, "<<< Exiting getCArray(size=%d)\n", size);
CArray *getCArray(int size)
{
    CArray *array = (CArray *)malloc(sizeof(CArray));
    array->array = (int *)malloc(sizeof(int) * size);
    array->size = size;
    int i;
    for (i = 0; i < size; i++)
    {
        array->array[i] = 0;
    }
    return array;
}

int insertValueCArray(CArray *array, int position, int value)
{
	fprintf(stderr, ">>> Entering insertValueCArray(array=%p,position=%d,value=%d)\n", array, position, value);
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] == 0)
        {
            array->array[position] = value;
            return SUCCESS;
        }
        else
	fprintf(stderr, "<<< Exiting insertValueCArray(array=%p,position=%d,value=%d)\n", array, position, value);
            return POSITION_INIT;
    }
    return INVALID_POSITION;
}

int removeValueCArray(CArray *array, int position)
{
	fprintf(stderr, ">>> Entering removeValueCArray(array=%p,position=%d)\n", array, position);
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] != 0)
        {
            array->array[position] = 0;
        }
        else
	fprintf(stderr, "<<< Exiting removeValueCArray(array=%p,position=%d)\n", array, position);
            return POSITION_EMPTY;
    }
    return INVALID_POSITION;
}

int pushValueCArray(CArray *array, int value)
{
	fprintf(stderr, ">>> Entering pushValueCArray(array=%p,value=%d)\n", array, value);
    int i;
    int ok = 0;
	fprintf(stderr, "pushValueCArray(array=%d,value=%d): ok → %d\n", array, value, ok);
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == 0)
        {
            array->array[i] = value;
            ok = 1;
            break;
        }
    }
    if (ok == 1)
        return SUCCESS;
    else
		fprintf(stderr, "<<< Exiting pushValueCArray(array=%p,value=%d)\n", array, value);
        return ARRAY_FULL;
}

int updateValueCArray(CArray *array, int position, int value)
{
	fprintf(stderr, ">>> Entering updateValueCArray(array=%p,position=%d,value=%d)\n", array, position, value);
    if (position >= 0 && position < array->size)
    {
        if (array->array[position] != 0)
        {
            array->array[position] = value;
            return SUCCESS;
        }

        else
	fprintf(stderr, "<<< Exiting updateValueCArray(array=%p,position=%d,value=%d)\n", array, position, value);
            return POSITION_NOT_INIT;
    }
    return INVALID_POSITION;
}

int eraseCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering eraseCArray(array=%p)\n", array);
    int i;
    for (i = 0; i < array->size; i++)
    {
        array->array[i] = 0;
    }
	fprintf(stderr, "<<< Exiting eraseCArray(array=%p)\n", array);
    return 0;
}

int switchValuesCArray(CArray *array, int position1, int position2)
{
	fprintf(stderr, ">>> Entering switchValuesCArray(array=%p,position1=%d,position2=%d)\n", array, position1, position2);
    if (position1 >= 0 && position1 < array->size && position2 >= 0 &&
        position2 < array->size)
    {
        int temp = array->array[position1];
        array->array[position1] = array->array[position2];
        array->array[position2] = temp;
	fprintf(stderr, "<<< Exiting switchValuesCArray(array=%p,position1=%d,position2=%d)\n", array, position1, position2);
        return SUCCESS;
    }
    return INVALID_POSITION;
}

int reverseCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering reverseCArray(array=%p)\n", array);
    int i;
    for (i = 0; i < array->size / 2; i++)
    {
        swap(array, i, array->size - i - 1);
    }
	fprintf(stderr, "<<< Exiting reverseCArray(array=%p)\n", array);
    return SUCCESS;
}

int displayCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering displayCArray(array=%p)\n", array);
    int i;
    printf("\nC ARRAY\n");
    for (i = 0; i < array->size; i++)
    {
        printf("%d ", array->array[i]);
    }
    printf("\n");
	fprintf(stderr, "<<< Exiting displayCArray(array=%p)\n", array);
    return 0;
}

int blenderCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering blenderCArray(array=%p)\n", array);
    srand(time(NULL) * array->size);
    int i;
    int total = array->size * 100;
	fprintf(stderr, "blenderCArray(array=%d): total → %d\n", array, total);
    for (i = 0; i < total; i++)
    {
        swap(array, rand() % array->size, rand() % array->size);
    }
	fprintf(stderr, "<<< Exiting blenderCArray(array=%p)\n", array);
    return 0;
}

fprintf(stderr, ">>> Entering getCopyCArray(arr=%p)\n", arr);
fprintf(stderr, "<<< Exiting getCopyCArray(arr=%p)\n", arr);
CArray *getCopyCArray(CArray *arr)
{
    CArray *array = (CArray *)malloc(sizeof(CArray));
    array->array = (int *)malloc(sizeof(int) * arr->size);
    array->size = arr->size;
    int i;
    for (i = 0; i < arr->size; i++)
    {
        array->array[i] = arr->array[i];
    }
    return array;
}

void swap(CArray *array, int position1, int position2)
{
	fprintf(stderr, ">>> Entering swap(array=%p,position1=%d,position2=%d)\n", array, position1, position2);
    int temp = array->array[position1];
    array->array[position1] = array->array[position2];
    array->array[position2] = temp;
	fprintf(stderr, "<<< Exiting swap(array=%p,position1=%d,position2=%d)\n", array, position1, position2);
}

int bubbleSortCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering bubbleSortCArray(array=%p)\n", array);
    int i, j;
    for (i = 0; i < array->size - 1; i++)
    {
        for (j = 0; j < array->size - i - 1; j++)
        {
            if (array->array[j] > array->array[j + 1])
            {
                swap(array, j, j + 1);
            }
        }
    }
	fprintf(stderr, "<<< Exiting bubbleSortCArray(array=%p)\n", array);
    return 0;
}

int selectionSortCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering selectionSortCArray(array=%p)\n", array);
    int i, j, min;
    for (i = 0; i < array->size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < array->size; j++)
			fprintf(stderr, "selectionSortCArray(array=%d): min → %d\n", array, min);
            if (array->array[j] < array->array[min])
                min = j;
        swap(array, min, i);
    }
	fprintf(stderr, "<<< Exiting selectionSortCArray(array=%p)\n", array);
    return 0;
}

int insertionSortCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering insertionSortCArray(array=%p)\n", array);
    int i, j, num;
    for (i = 1; i < array->size; i++)
    {
        num = array->array[i];
		fprintf(stderr, "insertionSortCArray(array=%d): num → %d\n", array, num);
        j = i - 1;
        while (j >= 0 && array->array[j] > num)
        {
            array->array[j + 1] = array->array[j];
            j--;
        }
        array->array[j + 1] = num;
    }
	fprintf(stderr, "<<< Exiting insertionSortCArray(array=%p)\n", array);
    return 0;
}

int valueOcurranceCArray(CArray *array, int value)
{
	fprintf(stderr, ">>> Entering valueOcurranceCArray(array=%p,value=%d)\n", array, value);
    int i, total = 0;
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == value)
            total++;
    }
	fprintf(stderr, "<<< Exiting valueOcurranceCArray(array=%p,value=%d)\n", array, value);
    return total;
}

fprintf(stderr, ">>> Entering valuePositionsCArray(array=%p,value=%d)\n", array, value);
fprintf(stderr, "<<< Exiting valuePositionsCArray(array=%p,value=%d)\n", array, value);
CArray *valuePositionsCArray(CArray *array, int value)
{
    int i, j = 0;
    int total = valueOcurranceCArray(array, value);
	fprintf(stderr, "valuePositionsCArray(array=%d,value=%d): total → %d\n", array, value, total);
    CArray *resultArray = getCArray(total);
    for (i = 0; i < array->size; i++)
    {
        if (array->array[i] == value)
        {
            // Hopefully this won't overflow
            resultArray->array[j] = i;
            j++;
        }
    }
    return resultArray;
}

int findMinCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering findMinCArray(array=%p)\n", array);
    int i;
    int min = array->array[0];
	fprintf(stderr, "findMinCArray(array=%d): min → %d\n", array, min);
    for (i = 1; i < array->size; i++)
    {
        if (array->array[i] < min)
        {
            min = array->array[i];
        }
    }
	fprintf(stderr, "<<< Exiting findMinCArray(array=%p)\n", array);
    return min;
}

int findMaxCArray(CArray *array)
{
	fprintf(stderr, ">>> Entering findMaxCArray(array=%p)\n", array);
    int i;
    int max = array->array[0];
	fprintf(stderr, "findMaxCArray(array=%d): max → %d\n", array, max);
    for (i = 1; i < array->size; i++)
    {
        if (array->array[i] > max)
        {
            max = array->array[i];
        }
    }
	fprintf(stderr, "<<< Exiting findMaxCArray(array=%p)\n", array);
    return max;
}
