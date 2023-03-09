#include <bits/stdc++.h>
using namespace std;
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
        ll n, l, u, d, r;
        int set = 0;
        cin >> n >> u >> r >> d >> l;
        Fo(colorLeft, 0, 2)
        {
            Fo(colorRight, 0, 2)
            {
                Fo(colorUp, 0, 2)
                {
                    Fo(colorDown, 0, 2)
                    {
                        ll left = 0, down = 0, right = 0, up = 0;
                        left += colorLeft + colorUp;
                        down += colorUp + colorRight;
                        right += colorRight + colorDown;
                        up += colorLeft + colorDown;
                        if (r - right < 0 || r - right > n - 2)
                        {
                            continue;
                        }
                        if (l - left < 0 || l - left > n - 2)
                        {
                            continue;
                        }
                        if (d - down < 0 || d - down > n - 2)
                        {
                            continue;
                        }
                        if (u - up < 0 || u - up > n - 2)
                        {
                            continue;
                        }
                        set = 1;
                        cout << "YES";
                        br;
                        break;
                    }
                    if (set)
                    {
                        break;
                    }
                }
                if (set)
                {
                    break;
                }
            }
            if (set)
            {
                break;
            }
        }
        if (set == 0)
        {
            cout << "NO";
            br;
        }
    }
    return 0;
}