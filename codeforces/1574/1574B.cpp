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
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b, c, m;
        cin >> a >> b >> c >> m;
        ll m1 = 0;
        ll m2 = 0;
        ll sum = a + b + c;
        m1 = a + b + c - 3;
        if(a <= sum/2 && b <= sum/2 && c <= sum/2)
        {
            m2 = 0;
        }
        else
        {
            if(a > sum/2)
            {
                if(sum % 2 == 0)
                {
                    a -= (sum / 2 + 1);
                    m2++;
                    m2 += a*2;
                }
                else
                {
                    a -= (sum + 1) / 2;
                    m2 += a*2;
                }

            }
            else if(b > sum/2)
            {
                if (sum % 2 == 0)
                {
                    b -= (sum / 2 + 1);
                    m2++;
                    m2 += b * 2;
                }
                else
                {
                    b -= (sum + 1) / 2;
                    m2 += b * 2;
                }
            }
            else if(c > sum/2)
            {
                if (sum % 2 == 0)
                {
                    c -= (sum / 2 + 1);
                    m2++;
                    m2 += c * 2;
                }
                else
                {
                    c -= (sum + 1) / 2;
                    m2 += c * 2;
                }
            }
        }
        // m2 = a + b + c - 1 - 2 * (a + b + c - max(a, max(b, c)));
        //cout << m1 << " " << m2 << endl;
        if (m <= m1 && m >= m2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}