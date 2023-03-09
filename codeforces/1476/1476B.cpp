#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
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
        ll n, k, x;
        cin >> n >> k;
        vl p;
        fo(i, n)
        {
            cin >> x;
            p.push_back(x);
        }
        ll change = 0;
        float temp = 1;
        ll sum = p[0];
        float sum_f = sum;
        Fo(i, 1, n)
        {
            sum_f = sum;
            temp = ((p[i] / sum_f) * 100);
            if (temp <= k)
            {
                sum = sum + p[i];
            }
            else
            {
                if ((p[i] * 100) % k == 0)
                {
                    change += (100 * p[i]) / k - sum;
                    sum = 100 * p[i] / k + p[i];
                }
                else
                {
                    change += (100 * p[i]) / k - sum + 1;
                    sum = 100 * p[i] / k + p[i] + 1;
                }
            }
        }
        cout << change << endl;
    }
    return 0;
}