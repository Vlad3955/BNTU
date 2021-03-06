#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include <math.h>

using namespace std;

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
#pragma warning(suppress : 4996)  
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


//// BUCKETSORT
//void bucketSort(int* arr, int len)
//{
//    const int max = len;
//    const int b = 10;
//
//    int buckets[b][max + 1];
//    for (int i = 0; i < b; ++i)
//    {
//        buckets[i][max] = 0;
//    }
//
//    for (int digit = 1; digit < 1000000000; digit *= 10)
//    {
//        int evenArray[max];
//        int evenCounter = 0;
//
//        for (int i = 0; i < max; ++i)
//        {
//            if (arr[i] % 2 != 0)
//            {
//                continue;
//            }
//            evenArray[evenCounter++] = i;
//            int d = (arr[i] / digit) % b;
//
//            /*
//            int counter = buckets[d][max];
//            buckets[d][counter] = arr[i];
//            counter++;
//            buckets[d][max] = counter;
//            */
//
//            // òîæå ÷òî è çàêîìåíòèðîâàíûé êîä
//            buckets[d][buckets[d][max]++] = arr[i];
//        }
//
//        int idx = 0;
//        for (int i = 0; i < b; ++i)
//        {
//            for (int j = 0; j < buckets[i][max]; ++j)
//            {
//                arr[evenArray[idx++]] = buckets[i][j];
//                //idx++;
//            }
//            buckets[i][max] = 0;
//        }
//    }
//}
//
// BUCKETSORT2
//void bucketSort2(int* arr, int len)
//{
//    const int max = len;
//    const int b = 10;
//
//    int buckets[b][max + 1];
//    for (int i = 0; i < b; ++i)
//    {
//        buckets[i][max] = 0;
//    }
//
//    for (int digit = 1; digit < 1000000000; digit *= 10)
//    {
//        for (int i = 0; i < max; ++i)
//        {
//            int d = (arr[i] / digit) % b;
//
//            /*
//            int counter = buckets[d][max];
//            buckets[d][counter] = arr[i];
//            counter++;
//            buckets[d][max] = counter;
//            */
//
//            
//            buckets[d][buckets[d][max]++] = arr[i];
//        }
//        int idx = 0;
//        for (int i = 0; i < b; ++i)
//        {
//            for (int j = 0; j < buckets[i][max]; ++j)
//            {
//                arr[idx++] = buckets[i][j];
//            }
//            //printf("%d ", arr[idx]);
//            buckets[i][max] = 0;
//        }
//        //printf("\n");
//    }
//}

int main()
{
    setlocale(LC_ALL, "rus");
    const int SZ = 5;
    float arrFloat[SZ];
    /*for (int i = 0; i < SZ; ++i)
    {
        cout << arrFloat[i] << endl;
    }
    for (int i = 0; i < SZ; ++i)
    {
        cin >> arrFloat[i];
    }
    cout << endl;*/
    /*for (int i = 0; i < SZ; ++i)
    {
        cout << arrFloat[i] << endl;
    }*/

    float* pArrFloat = arrFloat;
    /* cout << arrFloat << endl;
     cout << &pArrFloat << endl;*/
     /*for (int i = 0; i < SZ; ++i)
     {
         cout << pArrFloat[i] << endl;
     }*/
    char arrChar[SZ];
    char* pArrChar = arrChar;
    /*for (int i = 0; i < SZ; ++i)
    {
        cout << arrChar[i] << endl;
    }
    for (int i = 0; i < SZ; ++i)
    {
        cin >> arrChar[i];
    }
    cout << endl;
    for (int i = 0; i < SZ; ++i)
    {
        cout << arrChar[i] << endl;
    }*/
    pArrFloat = new float[SZ];
    /*for (int i = 0; i < SZ; ++i)
    {
        cout << pArrFloat[i] << endl;
    }
    for (int i = 0; i < SZ; ++i)
    {
        cin >> pArrFloat[i];
    }
    cout << endl;
    for (int i = 0; i < SZ; i++)
    {
        cout << pArrFloat[i] << endl;
    }*/
    delete[] pArrFloat;
    pArrChar = new char[SZ];
    /*for (int i = 0; i < SZ; ++i)
    {
        cin >> pArrChar[i];
    }
    cout << endl;
    for (int i = 0; i < SZ; i++)
    {
        cout << pArrChar[i] << endl;
    }*/
    delete[] pArrChar;
    int arr3d[2][2][1] = {
        {{1}, {2}},
        {{3}, {4}}
    };
    //cout << arr3d[0][1][1] << endl;
    //cout << *arr3d[0] << endl;
    int arr2d[SZ][SZ];
    /*for(int i = 0;i < 2; ++i)
    {
        for(int j = 0;j < 2; ++j)
        {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }*/
    int*** pArr2d = &arr3d[0][1][1];
    //pArr2d = &arr3d[0][1][1];
    cout << **pArr2d << endl;


    //const int SZ = 12;
    //int arr[SZ] = {5, 4, 3, 2, 1};
    //int arr[SZ];
    //fillIntRandom(arr, SZ, 100);
    //printIntArray(arr, SZ, 3);
    //sortInserts(arr, SZ);
    //qsf(arr, 0, SZ - 1);
   // bucketSort(arr, SZ);
    //printIntArray(arr, SZ, 3);

    return 0;
}