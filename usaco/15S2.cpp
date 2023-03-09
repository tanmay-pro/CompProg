#include <bits/stdc++.h>
using namespace std;
// code for implementing binary search
/*lli l = -1, r = size;while (r > l + 1){ lli mid = l + (r - l) / 2; if (array[mid] <= val)l = mid;elser = mid;}*/
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
#define file_read                       \
    freopen("highcard.in", "r", stdin); \
    freopen("highcard.out", "w", stdout);
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
    file_read;
    ll n;
    cin >> n;
    vl second;
    fo(i, n)
    {
        ll x;
        cin >> x;
        second.push_back(x);
    }
    sort(second.begin(), second.end());
    vl first;
    ll start = 0;
    for (ll i = 1; i <= 2 * n; i++)
    {
        if (i != second[start])
            first.push_back(i);
        else
            start++;
    }
    start = 0;
    ll ans = 0;
    // fo(i, first.size())
    // {
    //     cout << first [i] << " ";
    // }
    // br;
    fo(i, second.size())
    {
        ll currVal = second[i];
        while (first[start] < currVal && start <= n - 1)
            start++;
        if (start == n)
            break;
        ans++;
        start++;
    }
    cout << ans;
    br;
    return 0;
}