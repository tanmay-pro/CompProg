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

bool search(ll num2, ll upper, ll num)
{
    ll mid;
    ll lower = 1;
    while (lower <= upper)
    {
        mid = (lower + upper) / 2;
        if ((pow(mid, 3) + pow(num2, 3)) == num)
        {
            return true;
        }
        else if ((pow(mid, 3) + pow(num2, 3)) > num)
        {
            upper = mid - 1;
        }
        else
        {
            lower = mid + 1;
        }
    }
    return false;
}

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll right;
        ll num;
        cin >> num;
        right = cbrt(num);
        bool check = false;
        for (ll i = right; i >= 0; --i)
        {
            if (search(i, i, num))
            {
                check = true;
                break;
            }
        }
        if (num == 1)
        {
            cout << "NO";
            br;
        }
        else if (check == true)
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