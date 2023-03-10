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
        ll n;
        cin >> n;
        vl a(n);
        vl moda;
        fo(i, n)
        {
            cin >> a[i];
            moda.push_back(a[i] % 10);
        }
        ll freq[10] = {0};
        fo(i, n)
        {
            freq[moda[i]]++;
        }
        bool stat = false;
        fo(i, 10)
        {
            fo(j, 10)
            {
                fo(k, 10)
                {
                    if (i + j + k == 3 || (i + j + k) % 10 == 3)
                    {
                        if (i == j && j == k && freq[i] >= 3)
                        {
                            stat = true;
                            break;
                        }
                        else if (i == j && j != k && freq[i] >= 2 && freq[k] >= 1)
                        {
                            stat = true;
                            break;
                        }
                        else if (i != j && i != k && j != k && freq[i] >= 1 && freq[j] >= 1 && freq[k] >= 1)
                        {
                            stat = true;
                            break;
                        }
                    }
                }
                if (stat)
                {
                    break;
                }
            }
            if (stat)
            {
                break;
            }
        }
        if (stat)
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