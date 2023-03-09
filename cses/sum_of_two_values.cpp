#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
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
ll MOD = 1e9 + 7;
int p = 31;

// ll maxim(ll a, ll b, ll c)
// {
//     ll max_val = max(a, b);
//     return max(max_val, c);
// }

// ll minim(ll a, ll b, ll c)
// {
//     ll min_val = min(a, b);
//     return min(min_val, c);
// }
// ll binarySearch(vpl &arr, ll l, ll r, ll x)
// {
//     while (l <= r)
//     {
//         int m = l + (r - l) / 2;
//         if (arr[m].first == x)
//         {
//             return m;
//         }
//         if (arr[m].first < x)
//         {
//             l = m + 1;
//         }
//         else
//         {
//             r = m - 1;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     amazing;
//     ll n, x;
//     cin >> n >> x;
//     vpl a(n);
//     fo(i, n)
//     {
//         cin >> a[i].first;
//         a[i].second = i + 1;
//     }
//     bool set = false;
//     sort(a.begin(), a.end());
//     fo(i, n)
//     {
//         ll t = x - a[i].first;
//         ll r = binarySearch(a, 0, (n - 1), t);
//         if (r != -1 && a[i].second != a[r].second)
//         {
//             cout << a[i].second << " " << a[r].second;
//             br;
//             set = true;
//             break;
//         }
//     }
//     if (set == false)
//     {
//         cout << "IMPOSSIBLE";
//         br;
//     }
//     return 0;
// }

int main()
{
    ll n, s;
    cin >> n >> s;
    vpl a(n);
    fo(i, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    if (n == 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    ll sp = 0, ep = n - 1;
    while (sp < ep)
    {
        ll sum = a[sp].first + a[ep].first;
        if (sum > s)
        {
            ep--;
        }
        else if (sum < s)
        {
            sp++;
        }
        else
        {
            cout << a[sp].second << " " << a[ep].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}