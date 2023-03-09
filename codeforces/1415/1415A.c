#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    int n[t], m[t], r[t], c[t];
    int res[t];
    for (int i = 0; i < t; i++)
    {
        res[i] = 0;
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d %d", &n[i], &m[i], &r[i], &c[i]);
        int maxr = -1 + r[i];
        if (n[i] - r[i] > 0 && (n[i] - r[i]) > maxr)
            maxr = n[i] - r[i];
        else if (-n[i] + r[i] > 0 && (-n[i] + r[i]) > maxr)
            maxr = -n[i] + r[i];
        printf("maxr = %d\n", maxr);
        res[i] = res[i] + maxr;
        int maxc = -1 + c[i];
        if (m[i] - c[i] > 0 && (m[i] - c[i]) > maxc)
            maxc = m[i] - c[i];
        else if (-m[i] + c[i] > 0 && (-m[i] + c[i]) > maxc)
            maxc = -m[i] + c[i];
        printf("maxc = %d\n", maxc);
        res[i] = res[i] + maxc;
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", res[i]);
    }
    return 0;
}