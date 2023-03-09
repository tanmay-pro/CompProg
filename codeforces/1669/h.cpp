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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        vector<bitset<31>> bits(n, 0);
        fo(i, n)
        {
            bitset<31> b(a[i]);
            bits[i] = b;
        }
        ll freq[31] = {0};
        fo(i, n)
        {
            fo(j, 31)
            {
                if (bits[i][j])
                {
                    freq[j]++;
                }
            }
        }
        // fo(i, 31)
        // {
        //     cout << n - freq[i] << " ";
        // }
        stack<ll> st;
        ll ans = 0;
        fo(i, 31)
        {
            st.push(n - freq[i]);
        }
        // cout << ans << endl;
        ll r = 30;

        while (!st.empty())
        {
            ll x = st.top();
            st.pop();
            // cout << "For i =  " << i << " x = " << x << endl;
            if (k >= x)
            {
                k -= x;
                ans += pow(2, r);
                // cout << "ans = " << ans <<  " for i = " << i << endl;
            }
            r--;
        }
        cout << ans << endl;
    }
    return 0;
}