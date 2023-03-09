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
        ll n, m;
        cin >> n >> m;
        vector<ll> v1;
        vector<ll> v2;
        ll sumx = 0;
        ll sumy = 0;
        ll num = 0;
        fo(i, n)
        {
            fo(j, m)
            {
                char x;
                cin >> x;
                if (x == 'B')
                {
                    num++;
                    sumx += i + 1;
                    sumy += j + 1;
                }
            }
        }
        if(sumx % num != 0 )
        {
            sumx += num - (sumx % num);
        }
        if(sumy % num != 0 )
        {
            sumy += num - (sumy % num);
        }
        cout << sumx / num << " " << sumy / num << endl;
    }

    return 0;
}