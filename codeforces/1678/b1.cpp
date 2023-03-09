#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        vl lengths;
        int val = 1;
        Fo(i, 1, n)
        {
            if (str[i] == str[i - 1])
            {
                val++;
            }
            else
            {
                lengths.pb(val);
                val = 1;
            }
        }
        lengths.pb(val);
        // fo(i, lengths.size())
        // {
        //     cout << lengths[i];
        //     br;
        // }
        vi arr;
        fo(i, lengths.size())
        {
            if (lengths[i] % 2 == 0)
            {
                arr.push_back(0);
            }
            else
            {
                arr.push_back(1);
            }
        }
        ll ans = 0;
        Fo(i, 0, arr.size())
        {
            if (arr[i] == 1 && arr[i + 1] == 1)
            {
                ans += 1;
                arr[i] = 0;
                arr[i + 1] = 0;
            }
            else if (arr[i] == 1 && arr[i + 1] == 0)
            {
                ans++;
                arr[i + 1] = 1;
                arr[i] = 0;
            }
        }
        cout << ans;
        br;
    }
    return 0;
}