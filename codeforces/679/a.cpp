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
    ll n = 50;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    bool composite = false;
    vl divisors;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            cout << i;
            br;
            string ans;
            getline(cin, ans);
            if (ans == "yes")
            {
                divisors.pb(i);
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && i * i <= 100)
        {
            cout << i * i;
            br;
            string ans;
            getline(cin, ans);
            if (ans == "yes")
            {
                divisors.pb(i);
            }
        }
    }
    if (divisors.size() > 1)
    {
        cout << "composite";
    }
    else
    {
        cout << "prime";
    }
    br;

    return 0;
}