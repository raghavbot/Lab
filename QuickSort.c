#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int A[], int l, int r)
{
    int x, y, Pivot, temp;
    x = l;
    y = r;
    Pivot = A[l];

    while (x < y)
    {
        while (A[x] <= Pivot && x <= r)
            x++;
        while (A[y] > Pivot && y >= 1)
        {
            y--;
        }
        if (x < y)
        {
            temp = A[x];
            A[x] = A[y]; 
            A[y] = temp;
        }
    }
    temp = A[l];
    A[l] = A[y];
    A[y] = temp;
    return y;
}

void Quicksort(int A[], int l, int r)
{
    int p;
    if (l < r)
    {
        p = partition(A, l, r);
        Quicksort(A, l, p - 1);
        Quicksort(A, p + 1, r);
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}
int main()
{
    int A[100000], n, i;
    clock_t start, end, diff;
    printf("Enter n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        A[i] = rand();
    display(A, n);
    start = clock();
    Quicksort(A, 0, n - 1);
    end = clock();
    display(A, n);
    diff = end - start;
    printf("The time taken is %f seconds \n", (float)diff / CLOCKS_PER_SEC);
    return 0;
}