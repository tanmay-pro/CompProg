#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll n, k, a, b, c, d, e, f;
    cin >> n >> k;
    vl arr(n);
    cout << "or 1 2";
    br;
    cout << flush;
    cin >> a;
    cout << "and 1 2";
    br;
    cout << flush;
    cin >> b;
    cout << "or 2 3";
    br;
    cout << flush;
    cin >> c;
    cout << "and 2 3";
    br;
    cout << flush;
    cin >> d;
    cout << "or 1 3";
    br;
    cout << flush;
    cin >> e;
    cout << "and 1 3";
    br;
    cout << flush;
    cin >> f;
    arr[2] = (c + d + e + f - a - b) / 2;
    arr[1] = (a + b + d + c - e - f) / 2;
    arr[0] = (a + b + e + f - c - d) / 2;
    Fo(i, 3, n)
    {
        cout << "or 1 " << i + 1;
        br;
        cout << flush;
        cin >> a;
        cout << "and 1 " << i + 1;
        br;
        cout << flush;
        cin >> b;
        arr[i] = a + b - arr[0];
    }
    sort(arr.begin(), arr.end());
    cout << "finish " << arr[k - 1];
    br;
    cout << flush;
    return 0;
}