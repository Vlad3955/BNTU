#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <math.h>


void swapInt(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}



void fillIntRandom(int* array, int size, int border) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}



// QUICKSORT and QUICKSORT FAST



void qs(int* arr, int first, int last)
{
    int i = first;
    int j = last;

    int x = arr[(first + last) / 2];

    do {
        while (arr[i] < x)
        {
            i++;
        }
        while (arr[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
    {
        qs(arr, i, last);
    }
    if (first < j)
    {
        qs(arr, first, j);
    }
}

// SORT INSERTS
void sortInserts(int* arr, int len)
{
    int temp, pos;
    for (int i = 1; i < len; ++i)
    {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp)
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

// QUICKSORT FAST


int median(int* a, int* b, int* c)
{

    if (*a > *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    if (*b > *c)
    {
        int t = *b;
        *b = *c;
        *c = t;
    }
    if (*a > *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    return *b;
}

void qsf(int* arr, int first, int last)
{
    if (last > 10)
    {
        int i = first;
        int j = last;
        int x = median(&arr[first], &arr[(first + last) / 2], &arr[last]);

        do {
            while (arr[i] < x)
            {
                i++;
            }
            while (arr[j] > x)
            {
                j--;
            }
            if (i <= j)
            {
                swapInt(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last)
        {
            qsf(arr, i, last);
        }
        if (first < j)
        {
            qsf(arr, first, j);
        }
    }
    else
    {
        sortInserts(arr, last + 1);
    }
}


// BUCKETSORT
void bucketSort(int* arr, int len)
{
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        int evenArray[max];
        int evenCounter = 0;

        for (int i = 0; i < max; ++i)
        {
            if (arr[i] % 2 != 0)
            {
                continue;
            }
            evenArray[evenCounter++] = i;
            int d = (arr[i] / digit) % b;

            /*
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
            */

            // òîæå ÷òî è çàêîìåíòèðîâàíûé êîä
            buckets[d][buckets[d][max]++] = arr[i];
        }

        int idx = 0;
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < buckets[i][max]; ++j)
            {
                arr[evenArray[idx++]] = buckets[i][j];
                //idx++;
            }
            buckets[i][max] = 0;
        }
    }
}

// BUCKETSORT2
void bucketSort2(int* arr, int len)
{
    const int max = len;
    const int b = 10;

    int buckets[b][max + 1];
    for (int i = 0; i < b; ++i)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i = 0; i < max; ++i)
        {
            int d = (arr[i] / digit) % b;

            /*
            int counter = buckets[d][max];
            buckets[d][counter] = arr[i];
            counter++;
            buckets[d][max] = counter;
            */


            buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i)
        {
            for (int j = 0; j < buckets[i][max]; ++j)
            {
                arr[idx++] = buckets[i][j];
            }
            //printf("%d ", arr[idx]);
            buckets[i][max] = 0;
        }
        //printf("\n");
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    // QUICKSORT and SORTINSERTS
    const int SZ = 10;
    int arr[SZ];
    fillIntRandom(arr, SZ, 100);
    printIntArray(arr, SZ, 3);
    //sortInserts(arr, SZ);
    //qsf(arr, 0, SZ - 1);
    bucketSort(arr, SZ);
    printIntArray(arr, SZ, 3);

    // QUICKSORT FAST
    return 0;
}
