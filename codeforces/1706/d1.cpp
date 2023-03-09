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
        ll n, k;
        cin >> n >> k;
        vl a(n);
        fo(i, n) cin >> a[i];
        vvl poss;
        fo(i, n)
        {
            vl temp;
            Fo(j, 1, k + 1)
            {
                ll val = a[i] / j;
                temp.push_back(val);
            }
            poss.push_back(temp);
        }
        ll ans = LONG_LONG_MAX;
        fo(i, k)
        {
            ll firstSel = poss[0][i];
            vl temp;
            temp.push_back(firstSel);
            double avg = firstSel;
            ll numElem = 1;
            Fo(j, 1, n)
            {
                ll minim = LONG_LONG_MAX;
                ll elem = -1;
                fo(r, k)
                {
                    ll diff = abs((ll)(poss[j][r] - avg));
                    if (diff < minim)
                    {
                        minim = diff;
                        elem = poss[j][r];
                    }
                }
                temp.push_back(elem);
                double sum = numElem * avg + elem;
                avg = sum / (numElem + 1);
                numElem++;
            }
            ll diffVal = *max_element(temp.begin(), temp.end()) - *min_element(temp.begin(), temp.end());
            ans = min(ans, diffVal);
        }
        cout << ans << endl;
    }
    return 0;
}