#include <stdio.h>

int fibonacci(int n) {
    if (n == 1 || n == 0) {
        return n;
    }
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the term number: ");
    scanf("%d", &n);
    printf("Fibonacci term %d is %d\n", n, fibonacci(n));
    return 0;
}