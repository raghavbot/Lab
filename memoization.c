#include <stdio.h>

int FIBOM(int n)
{
    int table[100] = {};
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
        return 1;
    else if (table[n] == 0)
        table[n] = (FIBOM(n - 1) + FIBOM(n - 2));
        return table[n];
}
int main()
{
    int n;
    printf("Enter the term=");
    scanf("%d", &n);
    printf("\n%d term of Fibo=%d\n", n, FIBOM(n));
    return 0;
}