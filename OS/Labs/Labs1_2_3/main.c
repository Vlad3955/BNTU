#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

// Lab work ¹2
int arrayResult(int* arr, const int size, int value)
{
    int result = arr[0]*arr[1]*arr[2]*arr[3]+arr[4]+arr[5];
    if (result != value)
    {
        printf("Solution is not correct!\n");
    }
    return result;
}

int main()
{
    // Lab work ¹1
    //int sum = 1*2*3*4+5+6;
    //printf("%d \n", sum);

    // Lab work ¹2
    int A[SIZE] = {1, 2, 3, 4, 5, 6};
    printf("%d \n", arrayResult(A, SIZE, 35));
    return 0;
}
