// Author: "Vipul Vaishanv"
// Date: 26-march-2022
// Insert an element at the given index

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int size_of_array;
    printf("Enter the size of the array\n");
    scanf("%d", &size_of_array);
    printf("You have entered: %d\n", size_of_array);
    int *arr = (int *)malloc(size_of_array * sizeof(int));
    printf("Initalizing the array\nEnter array elements\n");
    for (int i = 0; i < size_of_array; i++)
    {
        // scanf("%d", &arr[i]);
        scanf("%d", arr + i);
    }
    printf("Your Array: \n");
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

    printf("\n");

    // int size_of_array = 6;
    // int *arr = (int *)malloc(size_of_array * sizeof(int));
    // // int arr[size_of_array];

    // // arr[0] = 12;
    // // arr[1] = 24;
    // // arr[2] = 36;
    // // arr[3] = 48;
    // // arr[4] = 60;
    // // arr[5] = 72;
    // *(arr + 0) = 12;
    // *(arr + 1) = 24;
    // *(arr + 2) = 36;
    // *(arr + 3) = 48;
    // *(arr + 4) = 60;
    // *(arr + 5) = 72;

    int index;
    printf("Enter the index where you want to insert the element\n");
    scanf("%d", &index);
    while (index < 0 || index >= size_of_array)
    {
        printf("ERR: INVALID_INDEX\nEnter a valid Index\n");
        scanf("%d", &index);
    }

    int element;
    printf("Enter the element you want to insert in the array\n");
    scanf("%d", &element);

    // arr[index] = element; //(direct change)
    // printf("Your New Array: \n");
    // for (int i = 0; i < size_of_array; i++)
    // {
    //     if (i != (size_of_array - 1))
    //     {
    //         printf("%d, ", arr[i]);
    //     }
    //     else
    //     {
    //         printf("%d", arr[i]);
    //     }
    // }

    size_of_array += 1;
    arr = (int *)realloc(arr, size_of_array);
    for (int i = size_of_array - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = element;
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

    return 0;
}