#include<stdio.h>

void main()
{
    int a[15], i = 0, n, sum = 0;

    printf("Enter the limit:");
    scanf("%d", &n);

    printf("Enter the element:");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }

    printf("SUM=%d", sum);
}
