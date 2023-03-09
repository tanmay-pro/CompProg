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

ll maxim(ll a, ll b, ll c)
{
    ll max_val = max(a, b);
    return max(max_val, c);
}

ll minim(ll a, ll b, ll c)
{
    ll min_val = min(a, b);
    return min(min_val, c);
}

int main()
{
    amazing;
    ll k, n;
    cin >> k >> n;
    unordered_map<ll, int> mp;
    ll sum[k];
    vl a(k);
    ll answer = 0;
    fo(i, k)
    {
        cin >> a[i];
    }
    sum[0] = a[0];
    Fo(i, 1, k)
    {
        sum[i] = a[i] + sum[i - 1];
    }
    vl b(n);
    fo(i, n)
    {
        cin >> b[i];
    }
    fo(j, k)
    {
        ll val = b[0] - sum[j];
        mp[val] = 1;
    }

    // tr(mp, it)
    // {
    //     cout << it->first << " ";
    // }
    // br;
    tr(mp, it)
    {
        ll initial_val = it->first;
        vl checker;
        fo(i, k)
        {
            initial_val += a[i];
            checker.push_back(initial_val);
        }
        // fo(i, checker.size())
        // {
        //     cout << checker[i] << " ";
        // }
        // br;
        bool set = true;
        fo(i, n)
        {
            auto it = find(checker.begin(), checker.end(), b[i]);
            if (it == checker.end())
            {
                set = false;
                break;
            }
            else
            {
                checker.erase(it);
            }
        }
        if (set == true)
            answer++;
    }
    cout << answer;
    br;
    return 0;
}