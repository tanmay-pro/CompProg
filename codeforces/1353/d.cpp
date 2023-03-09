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

struct myComp
{
    constexpr bool operator()(pair<ll, ll> const &a, pair<ll, ll> const &b) const noexcept
    {
        if (a.first < b.first)
            return true;
        else if (a.first == b.first)
        {
            if (a.second > b.second)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        priority_queue<pair<ll, ll>, vector<pll>, myComp> pq;
        pq.push({n, 0});
        ll val = 1;
        vl ans(n, 0);
        while (!pq.empty())
        {
            pll elem = pq.top();
            pq.pop();
            ll length = elem.first;
            ll startInd = elem.second;
            if (length % 2 == 0)
            {
                ll mid = startInd + length / 2 - 1;
                ans[mid] = val;
                val++;
                if (length == 2)
                {
                    pq.push({length / 2, mid + 1});
                    continue;
                }
                pq.push({length / 2 - 1, startInd});
                pq.push({length / 2, mid + 1});
            }
            else
            {
                ll mid = startInd + length / 2;
                ans[mid] = val;
                val++;
                if (length == 1)
                    continue;
                pq.push({length / 2, startInd});
                pq.push({length / 2, mid + 1});
            }

        }
        fo(i, n)
        {
            cout << ans[i] << " ";
        }
        br;
    }
    return 0;
}