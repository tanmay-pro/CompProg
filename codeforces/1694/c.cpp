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

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a(n + 1);
        vl prefSum(n + 1, 0);
        ll sum = 0;
        Fo(i, 1, n + 1)
        {
            cin >> a[i];
            sum += a[i];
            prefSum[i] = prefSum[i - 1] + a[i];
        }
        if (sum != 0)
        {
            cout << "No" << endl;
            continue;
        }
        bool check = true;
        Fo(i, 1, n + 1)
        {
            if (prefSum[i] < 0)
            {
                check = false;
                break;
            }
        }
        bool visZero = false;
        Fo(i, 1, n + 1)
        {
            if (prefSum[i] == 0)
            {
                visZero = true;
            }
            else if (visZero)
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}