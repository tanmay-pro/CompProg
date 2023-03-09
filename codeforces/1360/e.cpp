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
        vector<string> v;
        fo(i, n)
        {
            string s;
            cin >> s;
            v.pb(s);
        }
        vector<vector<ll>> a;
        fo(i, n)
        {
            vector<ll> temp;
            fo(j, n)
            {
                if (v[i][j] == '1')
                {
                    temp.pb(1);
                }
                else
                {
                    temp.pb(0);
                }
            }
            a.pb(temp);
        }
        bool allCheck = true;
        fo(i, n)
        {
            fo(j, n)
            {
                if (a[i][j] == 0)
                    continue;
                int ch = -1;
                if (i + 1 < n && a[i + 1][j] == 0)
                {
                    ch = 0;
                }
                int ch2 = -1;
                if (j + 1 < n && a[i][j + 1] == 0)
                {
                    ch2 = 0;
                }
                if (ch2 == 0 && ch == 0)
                {
                    allCheck = false;
                    break;
                }
            }
            if (allCheck == false)
            {
                break;
            }
        }
        if (allCheck)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}