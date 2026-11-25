#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i;
    int *ptr;

    n =5;
    ptr = (int*)malloc(n*sizeof(int));

    for ( i = 0; i < n; i++)
    {
        ptr[i] = i+1 ;
    }
    
    for ( i = 0; i < n; i++)
    {
        printf(" %d", *(ptr +i));
    }

    printf("\n");

    n=10;

    ptr = realloc(ptr, n*sizeof(int));

    for ( i = 0; i < n; i++)
    {
        ptr[i] = i+1 ;
    }
    
    for ( i = 0; i < n; i++)
    {
        printf(" %d", *(ptr+i));
    }


    
}