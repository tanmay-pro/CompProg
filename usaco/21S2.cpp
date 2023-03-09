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
    freopen("wormsort.in", "r", stdin); \
    freopen("wormsort.out", "w", stdout);
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
    // file_read;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vvl adjList(n + 1);
        fo(i, m)
        {
            ll u, v;
            cin >> u >> v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        vector<bool> visited(n + 1, false);
        vvl components;
        vl minComp;
        vl maxComp;
        ll source = 0, end = -1;
        stack<ll> st;
        Fo(i, 1, n + 1)
        {
            if (visited[i])
                continue;
            st.push(i);
            vl compo;
            ll minim = i, maxim = i;
            compo.push_back(i);
            visited[i] = true;
            if (i == n)
                end = components.size();
            while (!st.empty())
            {
                ll curr = st.top();
                st.pop();
                for (auto elem : adjList[curr])
                {
                    if (visited[elem])
                        continue;
                    st.push(elem);
                    visited[elem] = true;
                    compo.push_back(elem);
                    minim = min(minim, elem);
                    maxim = max(maxim, elem);
                    if (elem == n)
                        end = components.size();
                }
            }
            minComp.push_back(minim);
            maxComp.push_back(maxim);
            components.pb(compo);
        }
        ll minCost = LONG_LONG_MAX;
        fo(i, components.size())
        {
            pair<ll, ll> p1;
            pair<ll, ll> p2;
            pair<ll, ll> p3;
            p1.ff = minComp[source];
            p1.ss = maxComp[source];
            p2.ff = minComp[i];
            p2.ss = maxComp[i];
            p3.ff = minComp[end];
            p3.ss = maxComp[end];
            ll c1 = min((p1.ff - p2.ff) * (p1.ff - p2.ff), min((p1.ss - p2.ss) * (p1.ss - p2.ss), (p1.ss - p2.ff) * (p1.ss - p2.ff)));
            ll c2 = min((p2.ss - p3.ss) * (p2.ss - p3.ss), min((p2.ss - p3.ff) * (p2.ss - p3.ff), (p2.ff - p3.ff) * (p2.ff - p3.ff)));
            minCost = min(minCost, c1 + c2);
        }
        cout << minCost << endl;
    }
    return 0;
}