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
        vl array(4);
        cin >> array[0] >> array[1];
        cin >> array[3] >> array[2];
        bool ch = false;
        // fo(i, 4)
        // {
        //     cout << array[i] << " ";
        // }
        // br;
        fo(i, 4)
        {
            ll a = array[0];
            ll b = array[1];
            ll c = array[3];
            ll d = array[2];
            if (a < b && b < d && a < c && c < d)
            {
                ch = true;
                break;
            }
            else
            {
                // Rotate right by one element
                rotate(array.begin(), array.begin() + array.size() - 1, array.end());
                // fo(i, 4)
                // {
                //     cout << array[i] << " ";
                // }
                // br;
            }
        }
        if (ch)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}