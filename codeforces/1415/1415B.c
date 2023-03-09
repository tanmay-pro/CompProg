#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int n[t], k[t];
    int res[t];
    for (int i = 0; i < t; i++)
    {
        res[i] = 0;
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &n[i], &k[i]);
        int c[n[i]], days = 0;
        for (int j = 0; j < n[i]; j++)
        {
            scanf("%d", &c[j]);
        }
        int count[100] = {0};
        for (int j = 0; j < n[i]; j++)
        {
            count[c[j]]++;
        }
        int max = 0, l;
        for (l = 0; l < 100; l++)
        {
            if (count[l] >= count[max])
                max = l;
        }
        //printf("max = %d\n", max);
        for (int j = 0; j < n[i];)
        {
            if (max != c[j])
            {
                days++;
                j = j + k[i];
                //printf("j = %d\n", j);
                //printf("days = %d \n", days);
            }
            else
                j++;
        }
        res[i] = days;
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", res[i]);
    }
    return 0;
}