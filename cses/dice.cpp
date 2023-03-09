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
    ll n;
    cin >> n;
    vl ways(n + 1, 0);
    ways[0] = 1;
    ways[1] = 1;
    ways[2] = 2;
    Fo(i, 3, n + 1)
    {
        if (i <= 6)
        {
            ways[i] += 1;
        }
        Fo(j, 1, 7)
        {
            if (i > j)
                ways[i] += ways[i - j] % m;
            else
                break;
        }
    }
    cout << ways[n] % m << endl;
    return 0;
}