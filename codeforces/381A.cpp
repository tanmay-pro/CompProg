#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ff first
#define ss second
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
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl arr;
    fo(i, n)
    {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    ll *p1 = &arr[0];
    ll *p2 = &arr[n - 1];
    ll ser = 0;
    ll dim = 0;
    if (n % 2 == 0)
    {
        fo(i, n / 2)
        {
            if (*p1 > *p2)
            {
                ser += *p1;
                p1 = p1 + 1;
            }
            else
            {
                ser += *p2;
                p2 = p2 - 1;
            }
            if (*p1 > *p2)
            {
                dim += *p1;
                p1 = p1 + 1;
            }
            else
            {
                dim += *p2;
                p2 = p2 - 1;
            }
        }
    }
    else
    {
        fo(i, n / 2 + 1)
        {
            if (*p1 > *p2)
            {
                ser += *p1;
                p1 = p1 + 1;
            }
            else
            {
                ser += *p2;
                p2 = p2 - 1;
            }
            if (i != n / 2)
            {
                if (*p1 > *p2)
                {
                    dim += *p1;
                    p1 = p1 + 1;
                }
                else
                {
                    dim += *p2;
                    p2 = p2 - 1;
                }
            }
        }
    }

    cout << ser << " " << dim;
    br;
    return 0;
}