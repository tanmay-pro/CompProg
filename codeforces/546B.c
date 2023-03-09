#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[2*n], t;
    for (int i = 0; i < 2*n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        a[t - 1]++;
    }
    // for (int i = 0; i < 2*n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    int price = 0;
    int c = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if (a[i] > 1)
        {
            c = a[i] - 1;
            price += a[i] - 1;
            a[i] = a[i] - c;
            a[i + 1] += c;
        }
    }
    // for (int i = 0; i < 2*n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
    printf("%d\n", price);
    return 0;
}
