#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll w, h, n;
        cin >> w >> h >> n;
        ll sheets = 1;
        while (sheets < n)
        {
            if (w % 2 == 0 && h % 2 == 0)
            {
                w /= 2;
                sheets *= 2;
            }
            else if (h % 2 == 0)
            {
                h /= 2;
                sheets *= 2;
            }
            else if (w % 2 == 0)
            {
                w /= 2;
                sheets *= 2;
            }
            else
            {
                break;
            }
        }
        if (sheets >= n)
        {
            cout << "YES";
            br;
        }
        else
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}