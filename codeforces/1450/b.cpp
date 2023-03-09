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
int m = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll x[n];
        ll y[n];
        fo(i, n)
        {
            cin >> x[i];
            cin >> y[i];
        }
        bool set = false;
        fo(i, n)
        {
            bool temp = true;
            fo(j, n)
            {
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k)
                {
                    temp = false;
                    break;
                }
            }
            if (temp == true)
            {
                set = true;
                break;
            }
        }
        if (set == true)
        {
            cout << "1";
            br;
        }
        else
        {
            cout << "-1";
            br;
        }
    }
    return 0;
}