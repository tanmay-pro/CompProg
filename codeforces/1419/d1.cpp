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
    deque<ll> dq;
    fo(i, n)
    {
        ll x;
        cin >> x;
        dq.push_back(x);
    }
    sort(dq.begin(), dq.end());
    vl b;
    b.push_back(dq.back());
    dq.pop_back();
    if (n == 1)
    {
        cout << 0;
        br;
        cout << b[0];
        br;
        return 0;
    }
    ll save = dq.back();
    dq.pop_back();
    while (!dq.empty())
    {
        ll x = dq.front();
        dq.pop_front();
        b.push_back(x);
        if (dq.empty())
            break;
        x = dq.back();
        dq.pop_back();
        b.push_back(x);
    }
    if (n % 2 == 0)
    {
        cout << n / 2 - 1;
    }
    else
    {
        cout << n / 2;
    }
    br;
    b.push_back(save);
    fo(i, b.size())
    {
        cout << b[i] << " ";
    }
    br;
    return 0;
}