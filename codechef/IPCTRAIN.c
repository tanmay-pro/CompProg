#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define PI 3.14159265
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
int m = 1e9 + 7;

int main()
{
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        ll n, d;
        scanf("%lld %lld", &n, &d);
        ll d[n], t[n], s[n];
        ll sadness = 0;
        fo(i, n)
        {
            scanf("%lld %lld %lld", &d[i], &t[i], &s[i]);
        }
        
    }
    return 0;
}