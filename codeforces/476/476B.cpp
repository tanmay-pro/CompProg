#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;

int MOD = 1e9 + 7;
// To calculate a raised to b

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1 == true) // Equivalent to b%2
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1; // Equivalent to b/=2
    }
    return res;
}
ll fac(ll n)
{
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

int main()
{
    amazing;
    ll t = 1;
    //   cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1;
        cin >> str2;
        ll cpos = 0, cunk = 0;
        fo(i, str1.length())
        {
            if (str1[i] == '+')
            {
                cpos++;
            }
            else
            {
                cpos--;
            }
        }
        fo(i, str2.length())
        {
            if (str2[i] == '+')
            {
                cpos--;
            }
            else if (str2[i] == '-')
            {
                cpos++;
            }
            else
            {
                cunk++;
            }
        }
        double ans = 1;
        if (cunk == 0 && cpos == 0)
        {
            ans = 1;
        }
        else if (abs(cpos) > cunk)
        {
            ans = 0;
        }
        else if (abs(cpos) == cunk)
        {
            ans = 1 / (double)binpow(2, cunk);
        }
        else
        {
            if (abs(cpos) % 2 == 0 and cunk % 2 == 1)
            {
                ans = 0;
            }
            else if (abs(cpos) % 2 == 1 and cunk % 2 == 0)
            {
                ans = 0;
            }
            else
            {
                if (cpos != 0)
                {
                    ll count = cpos;
                    count = count + (cunk - cpos) / 2;
                    ll ncount = cunk - count;
                    ans = (double)(fac(cunk)) / (double)(fac(count) * fac(ncount) * binpow(2, cunk));
                }
                else
                {
                    ll count = cunk / 2;
                    ll ncount = cunk / 2;
                    ans = (double)fac(cunk) / (double)(fac(count) * fac(ncount) * binpow(2, cunk));
                }
            }
        }
        printf("%.12lf ", ans);
        br;
    }
    return 0;
}