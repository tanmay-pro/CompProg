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

bool oddDiv(ll n)
{
    if ((n & (n - 1)) == 0)
        return false;
    else
        return true;
}

bool checkPrime(ll n)
{
    Fo(i, 2, min(n, (ll)50000))
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s2 = "FastestFinger";
        string s1 = "Ashishgup";
        if (n == 1)
        {
            cout << s2 << endl;
        }
        else if (n == 2)
        {
            cout << s1 << endl;
        }
        else if (n % 2 == 1)
        {
            cout << s1 << endl;
        }
        else
        {
            bool check = oddDiv(n);
            int lose = 0;
            if (!check)
            {
                lose = 1;
            }
            else if (checkPrime(n / 2) && n % 4 != 0)
            {
                lose = 1;
            }
            if (lose)
            {
                cout << s2 << endl;
            }
            else
            {
                cout << s1 << endl;
            }
        }
    }
    return 0;
}