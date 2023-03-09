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
    ll n, q;
    cin >> n >> q;
    vvl arr(n, vl(n, 0));
    fo(i, n)
    {
        fo(j, n)
        {
            char x;
            cin >> x;
            if (x == '*')
                arr[i][j] = 1;
        }
    }
    vvl prefix(n, vl(n, 0));
    prefix[0][0] = arr[0][0];
    Fo(i, 1, n)
    {
        prefix[i][0] = arr[i][0] + prefix[i - 1][0];
        prefix[0][i] = arr[0][i] + prefix[0][i - 1];
    }
    Fo(i, 1, n)
    {
        Fo(j, 1, n)
        {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }
    // fo(i, n)
    // {
    //     fo(j, n)
    //     {
    //         cout << prefix[i][j] << " ";
    //     }
    //     br;
    // }
    while (q--)
    {
        ll a, b, A, B;
        cin >> a >> b >> A >> B;
        a--;
        b--;
        A--;
        B--;
        ll ans = prefix[A][B];
        if (a - 1 >= 0)
            ans -= prefix[a - 1][B];
        if (b - 1 >= 0)
            ans -= prefix[A][b - 1];
        if (a - 1 >= 0 && b - 1 >= 0)
            ans += prefix[a - 1][b - 1];
        cout << ans;
        br;
    }
    return 0;
}