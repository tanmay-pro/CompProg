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
        ll sum = 0;
        ll number_of_negative = 0;
        ll number_of_zero = 0;
        ll smallest = m;
        ll n, r;
        cin >> n >> r;
        fo(i, n)
        {
            fo(j, r)
            {
                ll x;
                cin >> x;
                sum += abs(x);
                if (x < 0)
                {
                    number_of_negative++;
                }
                else if (x == 0)
                {
                    number_of_zero++;
                }
                if (smallest > abs(x))
                {
                    smallest = abs(x);
                }
            }
        }
        if (number_of_zero > 0)
        {
            cout << sum;
            br;
        }
        else
        {
            if (number_of_negative % 2 == 0)
            {
                cout << sum;
                br;
            }
            else
            {
                cout << sum - 2 * abs(smallest);
                br;
            }
        }
    }
    return 0;
}