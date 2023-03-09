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
int MOD = 1e9 + 7;

int main()
{
    ll t = 1;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll b[n + 2];
        ll sum = 0;
        ll max_el = 0;
        ll max_index = 0;
        fo(i, n + 2)
        {
            ll x;
            scanf("%lld", &x);
            b[i] = x;
            sum += x;
            if (x > max_el)
            {
                max_el = x;
                max_index = i;
            }
        }
        ll temp = sum;
        ll max_2el = -MOD;
        ll max_2index = 0;
        fo(i, n + 2)
        {
            if (b[i] > max_2el && b[i] != max_el)
            {
                max_2el = b[i];
                max_2index = i;
            }
        }
        if (max_2el == -MOD)
        {
            max_2el = max_el;
        }
        fo(i, n + 2)
        {
            if (i != max_index && b[i] == max_2el)
            {
                max_2index = i;
            }
        }

        bool set = false;
        fo(i, n + 2)
        {
            sum -= b[i];
            if (b[i] == max_el && i == max_index)
            {

                if (sum == 2 * max_2el)
                {
                    //printf("Sum = %lld\n", sum);
                    fo(j, n + 2)
                    {
                        if (j == i || j == max_2index)
                        {
                            continue;
                        }
                        else
                        {
                            printf("%lld ", b[j]);
                            set = true;
                        }
                    }
                    break;
                }
            }
            else
            {
                if (sum == 2 * max_el)
                {
                    //printf("Sum = %lld", sum);
                    fo(j, n + 2)
                    {
                        if (j == i || j == max_index)
                        {
                            ;
                        }
                        else
                        {
                            printf("%lld ", b[j]);
                            set = true;
                        }
                    }
                    break;
                }
            }
            sum = temp;
        }
        if (set == false)
        {
            printf("-1");
        }
        br;
    }
    return 0;
}