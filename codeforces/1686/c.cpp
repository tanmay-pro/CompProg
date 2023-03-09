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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a(n);
        fo(i, n)
        {
            cin >> a[i];
        }
        if (n % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        vl bigArray;
        Fo(i, n / 2, n)
        {
            bigArray.pb(a[i]);
        }
        vl smallArray;
        Fo(i, 0, n / 2)
        {
            smallArray.pb(a[i]);
        }
        bool possible = true;
        if (!(smallArray[0] < bigArray[0] && smallArray[0] < bigArray[bigArray.size() - 1]))
        {
            possible = false;
        }
        Fo(i, 1, smallArray.size())
        {
            if (!(smallArray[i] < bigArray[i] && smallArray[i] < bigArray[i - 1]))
            {
                possible = false;
                break;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
            fo(i, n / 2)
            {
                cout << smallArray[i] << " " << bigArray[i] << " ";
            }
            br;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}