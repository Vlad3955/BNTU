#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6


// Task 2
void expression(int* a, int S, int result)
{
   char o[S - 1];

    int r;
    for (int i = 0; i < pow(4, S - 1); ++i) {
        r = a[0];
        int p = 1;//4^(j - 1)
        for (int j = 1; j < S; ++j) {
            switch ((i / p) % 4) {
            case 0:
                r += a[j];
                o[j - 1] = '+';
                break;
            case 1:
                r -= a[j];
                o[j - 1] = '-';
                break;
            case 2:
                r *= a[j];
                o[j - 1] = '*';
                break;
            case 3:
                r /= a[j];
                o[j - 1] = '/';
                break;
            }
            p *= 4;
        }
        if (r == result) {
            printf("((((%d ", a[0]);
            for (int k = 1; k < S; ++k)
                printf("%c %d ) ", o[k - 1], a[k]);
            printf("= %d\n", result);
        }
    }
}


// Task 3
#define M 5
#define N 5

// Функция выделения динамической памяти для двумерного массива
int** malloc2DArray( int m,  int n)
{
    int** arr = (int**) malloc(m*sizeof(int*));
    for (int i = 0; i < m; ++i)
        arr[i] = (int*) malloc(n*sizeof(int));
    return arr;
}

// Функция освобождения памяти
void free2DArray(int** arr, const int m)
{
    for (int i = 0; i < m; ++i)
        free(arr[i]);
    free(arr);
}

// Печать двумерного массива
void print2DArray(int** arr,  int m ,  int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}

// Функция суммирования строк
int sumRow(int **arr, int row, int cols)
{
    int sum = 0;
    for (int j = 0; j < cols; ++j)
        sum += arr[row][j];
    return sum;
}

// Функция суммирования столбцов
int sumCol(int **arr, int col, int rows)
{
    int sum = 0;
    for (int i = 0; i < rows; ++i)
        sum += arr[i][col];
    return sum;
}


// Task 4
typedef struct Stack
{
    char * data;//указатель на данные
    struct Stack * prev;//указатель на предыдущий элемент
}Stack;


void Push(Stack** stack, char* data) // поместить данные в стек;
{
    Stack *tmp = (Stack*)malloc(sizeof(Stack));
    tmp->data = data;
    tmp->prev = (*stack) ? *stack : NULL;
    *stack = tmp;
}

void Pop(Stack** stack)
{
    if (!(*stack))//если нечего удалять
        return;
    Stack *tmp = *stack;//создаем указатель на вершину
    *stack = (*stack)->prev;//вершину сдвигаем вниз
    free(tmp);//очищаем память (удаляем старую вершину)
}

void PrintStack(Stack *stack) /* Печать списка */
{
    Stack *tmp = stack;
    while (tmp)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->prev;
    }
}


// Task 5
void WriteStack(char * fname, Stack * pstk)
{
    FILE *f;
    if((f = fopen(fname, "w+")) == NULL)
    {
        perror("Error occured while opening file");
        return;
    }
    char *n = "\n";
    Stack *tmp = pstk;
    while (tmp)
    {
        //fwrite(tmp->data, sizeof(tmp), 1, f);
        fputs(tmp->data, f);
        fputs(n, f);
        tmp = tmp->prev;
    }
    fclose(f);
}

Stack * ReadStack(char * fname)
{
    Stack *top = NULL;
    Stack *tmp = (Stack*)malloc(sizeof(Stack));
    char *data;
    FILE *f;
    int i = 0;

    if((f = fopen(fname, "r")) == NULL)
    {
        perror("Error occured while opening file");
        return;
    }

    while(fscanf(f, "%s", data[i].data) != EOF)
    {
        i++;
    }
}

int main()
{
    //Task 1
//   int a[N] = { 1, 2, 3, 4, 5, 6, };
//    int result = 35;
//
//    char o[N - 1];
//
//    int r;
//    for (int i = 0; i < pow(4, N - 1); ++i) {
//        r = a[0];
//        int p = 1;//4^(j - 1)
//        for (int j = 1; j < N; ++j) {
//            switch ((i / p) % 4) {
//            case 0:
//                r += a[j];
//                o[j - 1] = '+';
//                break;
//            case 1:
//                r -= a[j];
//                o[j - 1] = '-';
//                break;
//            case 2:
//                r *= a[j];
//                o[j - 1] = '*';
//                break;
//            case 3:
//                r /= a[j];
//                o[j - 1] = '/';
//                break;
//            }
//            p *= 4;
//        }
//        if (r == result) {
//            printf("((((%d ", a[0]);
//            for (int k = 1; k < N; ++k)
//                printf("%c %d ) ", o[k - 1], a[k]);
//            printf("= %d\n", result);
//        }
//    }


// Task 2
//   int a[N] = { 1, 2, 3, 4, 5, 6, };
//   expression(a, N, 35);


// Task 3
//    // создаём новую матрицу MxN
//    int** mtrx = malloc2DArray(M+1, N+1);
//
//    // заполняем
//    for (int i = 0; i < M; ++i)
//    for (int j = 0; j < N; ++j)
//        mtrx[i][j] = j;
//
//    // выводим
//    printf("Matrix\n");
//    print2DArray(mtrx, M, N);
//
//    int rowsSum = 0;
//    for (int i = 0; i < M; ++i)
//    {
//        mtrx[i][N] = sumRow(mtrx, i, N);
//        rowsSum += mtrx[i][N];
//    }
//
//    int colsSum = 0;
//    for (int j = 0; j < N; ++j)
//    {
//        mtrx[M][j] = sumCol(mtrx, j, M);
//        colsSum += mtrx[M][j];
//    }
//
//    mtrx[M][N] = rowsSum + colsSum;
//     // выводим
//    printf("Matrix\n");
//    print2DArray(mtrx, M+1, N+1);
//
//    // освобождаем выделенную память
//    free2DArray(mtrx, M);


// Task 4
Stack *top = NULL;
    Push(&top, "abc");
    Push(&top, "efg");
    Push(&top, "mmm");
    //Pop(&top);
    //PrintStack(top);
// Task 5
    WriteStack("test.txt", top);

   return 0;
}
