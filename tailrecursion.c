#include<stdio.h>
int fact(n,a){
    if (n==0){
        return a;
    }
    else 
        return fact(n-1,a*n);

}
int main(){
    int a=1,number,result;
    printf("Enter a number: \n");
    scanf("%d",&number);
    result=fact(number,a);
    printf("%d",result);

}