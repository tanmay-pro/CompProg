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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vvl a;
        map<ll, ll> first;
        fo(i, n)
        {
            vl temp;
            fo(j, n - 1)
            {
                ll x;
                cin >> x;
                temp.push_back(x);
                if (j == 0)
                    first[x]++;
            }
            a.push_back(temp);
        }
        ll maxim = LONG_LONG_MIN, elem1;
        tr(first, it)
        {
            if (it->second > maxim)
            {
                maxim = it->second;
                elem1 = it->first;
            }
        }
        vl ans;
        ans.push_back(elem1);
        fo(i, n)
        {
            bool present = false;
            vl temp;
            fo(j, n - 1)
            {
                temp.push_back(a[i][j]);
                if (a[i][j] == elem1)
                {
                    present = true;
                    break;
                }
            }
            if (!present)
            {
                fo(i, temp.size())
                {
                    ans.push_back(temp[i]);
                }
                break;
            }
        }
        fo(i, n)
        {
            cout << ans[i] << " ";
        }
        br;
    }
    return 0;
}