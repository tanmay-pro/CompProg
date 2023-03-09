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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a(n);
        fo(i, n) cin >> a[i];
        priority_queue<pll, vpl, greater<pll>> pq;
        map<ll, ll> req;
        fo(i, n - 1)
        {
            if (a[i] < a[i + 1])
                continue;
            else
            {
                pq.push({a[i] - a[i + 1] + 1, i + 1});
            }
        }
        vl searchArray;
        fo(i, n)
        {
            searchArray.push_back(i);
        }
        while(!pq.empty())
        {
            ll elem = pq.top();
            ll diff = elem.ff;
            ll index = elem.ss;
            pq.pop();
            ll ind = lower_bound(searchArray.begin(), searchArray.end(), index) - searchArray.begin();
            if(ind == searchArray.size())
            {
                continue;
            }
            else
            {
                ll val = searchArray[ind];
                req[val] = diff;
                searchArray.erase(searchArray.begin() + ind);
            }
        }
    }
    return 0;
}