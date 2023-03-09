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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a;
        ll sum = 0;
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        ll m;
        cin >> m;
        vl b;
        fo(i, m)
        {
            ll x;
            cin >> x;
            b.push_back(x);
        }
        vl c;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (a[i] > b[j])
            {
                c.push_back(a[i]);
                i++;
            }
            else
            {
                c.push_back(b[j]);
                j++;
            }
        }
        for (; i < n;)
        {
            c.push_back(a[i]);
            i++;
        }
        for (; j < m;)
        {
            c.push_back(b[j]);
            j++;
        }
        cout << "wait" << endl;
        fo(i, c.size())
        {
            cout << c[i] << ", ";
        }
        br;
        ll maxel = 0;
        fo(i, c.size())
        {
            sum += c[i];
            if (sum > maxel)
            {
                maxel = sum;
            }
        }
        cout << maxel;
        br;
    }
    return 0;
}