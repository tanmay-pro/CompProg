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
        ll n, k;
        cin >> n >> k;
        vl damage;
        vl additional(n);
        vl netPositive(n);
        vpl pairedPos;
        vl tobeSkipped;

        ll sum = 0;
        fo(i, n)
        {
            ll d;
            cin >> d;
            damage.pb(d);
            additional[i] = n - 1 - i;
            netPositive[i] = -additional[i] + d;
            pairedPos.pb({netPositive[i], i});
        }
        sort(pairedPos.begin(), pairedPos.end());
        fo(i, k)
        {
            tobeSkipped.push_back(pairedPos[n - 1 - i].ss);
        }
        sort(tobeSkipped.begin(), tobeSkipped.end());
        ll skipped = 0;
        fo(i, n)
        {
            if (binary_search(tobeSkipped.begin(), tobeSkipped.end(), i))
            {
                skipped++;
            }
            else
            {
                sum += damage[i] + skipped;
            }
        }
        if (k < n)
            cout << sum;
        else
            cout << 0;
        br;
    }
    return 0;
}