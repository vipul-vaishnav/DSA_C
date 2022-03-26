#include <stdio.h>
#include <stdlib.h>

void insertion(int size_of_array, int *arr, int idx, int el)
{
    size_of_array += 1;
    arr = (int *)realloc(arr, size_of_array);
    for (int i = size_of_array - 1; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = el;

    printf("\nNEW ARRAY:\n");
    for (int i = 0; i < size_of_array; i++)
    {
        if (i != size_of_array - 1)
            printf("%d, ", *(arr + i));
        else
            printf("%d", *(arr + i));
    }
}

void deletion(int size_of_array, int *arr, int index)
{
    size_of_array -= 1;
    arr = (int *)realloc(arr, size_of_array);
    for (int i = index; i < size_of_array; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("Your New Array: \n");
    for (int i = 0; i < size_of_array; i++)
    {
        if (i != (size_of_array - 1))
        {
            printf("%d, ", arr[i]);
        }
        else
        {
            printf("%d", arr[i]);
        }
    }
}

int linearSearch(int size_of_array, int *arr, int el)
{
    for (int i = 0; i < size_of_array; i++)
    {
        if (*arr + i == el)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int binarySearch(int size_of_array, int *arr, int el)
{
    int start = 0;
    int end = size_of_array - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (el < arr[mid])
        {
            end = mid - 1;
        }
        else if (el > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return -1;
}

int main(void)
{
    int size_of_array;
    int *ptr = &size_of_array;
    printf("Enter the size of array\n");
    scanf("%d", ptr);
    printf("You have entered: %d\n", *ptr);

    int *arr = (int *)malloc(size_of_array * sizeof(int));
    printf("Enter array elements\n");
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d", arr + i);
    }
    printf("-->Your array elements<--\n");
    for (int i = 0; i < size_of_array; i++)
    {
        if (i != size_of_array - 1)
            printf("%d, ", *(arr + i));
        else
            printf("%d", *(arr + i));
    }

    int operation;
    printf("\nChoose the operation you want to perform on the array\n");
    printf("Enter-->\n1. For Insertion\n2. For Deletion\n3. For Printing\n4. For Searching\n");
    scanf("%d", &operation);
    printf("You have entered: %d\n", operation);

    switch (operation)
    {
    case 1:
        printf("Insertion\n");

        int idx;
        printf("Enter the index: \n");
        scanf("%d", &idx);
        while (idx < 0 || idx >= size_of_array)
        {
            printf("ERR: NOT_A_VALID_VALUE\n");
            scanf("%d", &idx);
        }
        printf("Index: %d\n", idx);

        int el;
        printf("Enter the element: \n");
        scanf("%d", &el);
        printf("Element: %d\n", el);
        insertion(size_of_array, arr, idx, el);
        break;
    case 2:
        printf("Deletion\n");

        int index;
        printf("Enter the index\n");
        scanf("%d", &index);
        while (index < 0 || index >= size_of_array)
        {
            printf("ERR: INVALID_INDEX\nEnter a valid Index\n");
            scanf("%d", &index);
        }

        printf("Index: %d\n", index);
        deletion(size_of_array, arr, index);
        break;
    case 3:
        printf("Printing\n");
        printf("-->Your array elements<--\n");
        for (int i = 0; i < size_of_array; i++)
        {
            if (i != size_of_array - 1)
                printf("%d, ", *(arr + i));
            else
                printf("%d", *(arr + i));
        }
        break;
    case 4:
        printf("Searching\n");

        int element;
        printf("Enter the element you want to search: \n");
        scanf("%d", &element);
        printf("You have entered: %d\n");

        int search_op;
        printf("Enter: --> \n 1. For Linear\n2. For Binary\n");
        printf("PRECAUTION: \"USE BINARY SEARCH ONLY IF ARRAY IS SORTED\n");
        scanf("%d", &search_op);

        switch (search_op)
        {
        case 1:
            if (linearSearch(size_of_array, arr, element) == 1)
            {
                printf("Element Present");
            }
            else
            {
                printf("Element Not Present");
            }
            break;
        case 2:
            if (binarySearch(size_of_array, arr, element) == 1)
            {
                printf("Element Present");
            }
            else
            {
                printf("Element Not Present");
            }
            break;
        default:
            printf("ERR: NO_VALID_OPTION_CHOSEN");
            break;
        }
        break;
    default:
        printf("ERR: NO_VALID_OPTION_CHOSEN");
        break;
    }

    return 0;
}
