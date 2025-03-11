#include<stdio.h>

void toh(int n, char src, char tmp, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dest);
        return;
    }
    toh(n - 1, src, dest, tmp);
    printf("Move disk %d from %c to %c\n", n, src, dest);
    toh(n - 1, tmp, src, dest);
}

int main() {
    int n;
    printf("Enter the number of disks: \n");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    return 0;
}