#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll n;
    cin >> n;
    vl a(n);
    fo(i, n)
    {
        cin >> a[i];
    }
    ll rest = 0;
    ll si = -1;
    fo(i, n)
    {
        if (a[i] == 3)
            continue;
        else if (a[i] == 0)
            continue;
        else
        {
            si = i;
            break;
        }
    }
    fo(i, si)
    {
        if (a[i] == 0)
            rest++;
        else
            continue;
    }
    ll last = -1;
    if (a[si] == 1)
    {
        last = 1;
    }
    else if (a[si] == 2)
    {
        last = 2;
    }
    Fo(i, si + 1, n)
    {
        if (a[i] == 0)
        {
            rest++;
            last = 0;
        }
        else if (a[i] == 1)
        {
            if (last == 1)
            {
                // cout << "At index " << i << ": " << rest << endl;
                rest++;
                last = 0;
            }
            else if (last == 0 || last == 2)
            {
                last = 1;
            }
        }
        else if (a[i] == 2)
        {
            if (last == 2)
            {
                // cout << "At index " << i << ": " << rest << endl;
                rest++;
                last = 0;
            }
            else if (last == 0 || last == 1)
            {
                last = 2;
            }
        }
        else
        {
            if (last == 1)
            {
                last = 2;
            }
            else if (last == 2)
            {
                last = 1;
            }
            else
            {
                last = 0;
            }
        }
    }
    cout << rest << endl;
    return 0;
}