#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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

struct cmp2
{
    bool operator()(pll const &a, pll const &b)
    {
        return a.second < b.second;
    }
};

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {

        ll n, d;
        cin >> n >> d;
        vl num(n);
        vector<vector<pair<ll, ll>>> a(d+1);
        fo(i, n)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            a[x].push_back(make_pair(i, z));
            num[i] = y;
        }
        priority_queue<pll, vector<pll>, cmp2> q;
        Fo(i, 1, d + 1)
        {
            fo(j, a[i].size())
            {
                q.push(a[i][j]);
            }
            num[q.top().first] -= 1;
            // cout << "The Person has give lecture with sadness " << q.top().second << " on the day " << i << endl;
            // br;
            if (num[q.top().first] == 0)
            {
                q.pop();
            }
        }
        ll sum = 0;
        while (!q.empty())
        {
            sum += (q.top().second) * (num[q.top().first]);
            q.pop();
        }
        cout << sum;
        br;
    }
    return 0;
}