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

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k1, k2, k3;
        cin >> n >> k1 >> k2 >> k3;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        vl arr(n);
        ll sum = 0;
        fo(i, n)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        fo(i, n)
        {
            if (i - 1 >= 0)
            {
                sum -= arr[i - 1];
            }
            ll ans = sum;
            Fo(j, n - 1, -1)
            {
                if (pq.size() <= k3)
                {
                    pq.push(ans);
                }
                else
                {
                    if (pq.top() < ans)
                    {
                        pq.pop();
                        pq.push(ans);
                    }
                }
                ans -= arr[j];
                if (i == j)
                    break;
            }
        }
        vl final;
        while (!pq.empty())
        {
            final.push_back(pq.top());
            pq.pop();
        }
        reverse(final.begin(), final.end());
        cout << final[k1 - 1] << " " << final[k2 - 1] << " " << final[k3 - 1];
        br;
    }
    return 0;
}