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

    ll arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n - 1);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }

    // map<ll, ll> mp;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     ll x;
    //     cin >> x;
    //     mp[x] = 1;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (mp.find(i) == mp.end())
    //     {
    //         cout << i << endl;
    //         return 0;
    //     }
    // }

    return 0;
}