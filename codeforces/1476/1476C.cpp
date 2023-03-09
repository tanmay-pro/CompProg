#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n;
        vl a, b, c;
        fo(i, n)
        {
            cin >> x;
            c.push_back(x);
        }
        fo(i, n)
        {
            cin >> x;
            a.push_back(x);
        }
        fo(i, n)
        {
            cin >> x;
            b.push_back(x);
        }
        ll curr = c[n - 1] - 1, highest = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            curr += 2;
            if (a[i + 1] == b[i + 1])
            {
                highest = max(highest, curr);
                curr = c[i] - 1;
            }
            else
            {
                ll q = abs(b[i + 1] - a[i + 1]);
                highest = max(highest, curr + q);
                q = c[i] - 1 - q;
                curr += q;
                curr = max(curr, c[i] - 1);
            }
        }
        cout << highest << "\n";
    }
    return 0;
}