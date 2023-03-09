#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (ll int i = 0; i < n; i++)
#define Fo(i, k, n) for (ll int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define f first
#define s second
#define pb push_back
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll int q, d, input;
        cin >> q >> d;
        vl v;
        fo(i, q)
        {
            cin >> input;
            v.push_back(input);
        }
        fo(i, q)
        {
            if (v[i] >= 10 * d)
            {
                cout << "YES\n";
                continue;
            }
            else
            {
                bool set = false;
                for (int j = v[i] - d; j >= 0; j -= d)
                {
                    if (j % 10 == 0)
                    {
                        cout << "YES\n";
                        set = true;
                        break;
                    }
                }
                if (set == false)
                    cout << "NO\n";
            }
        }
    }
    return 0;
}