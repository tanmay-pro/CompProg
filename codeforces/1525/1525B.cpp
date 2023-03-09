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
        ll n;
        cin >> n;
        vl array;
        fo(i, n)
        {
            ll x;
            cin >> x;
            array.push_back(x);
        }
        bool sorted = true;
        ll count = 0;
        fo(i, n)
        {
            if (array[i] != i + 1)
            {
                sorted = false;
                break;
            }
        }
        if (sorted == true)
        {
            cout << 0;
            br;
        }
        else
        {
            if (array[0] == 1)
            {
                cout << 1;
            }
            else if (array[n - 1] == n)
            {
                cout << 1;
            }
            else
            {
                if (array[0] == n && array[n - 1] == 1)
                    cout << 3;
                else
                    cout << 2;
            }
            br;
        }
    }
    return 0;
}