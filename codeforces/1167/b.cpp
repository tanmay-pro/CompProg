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

ll ask(ll a, ll b)
{
    cout << "? " << a + 1 << " " << b + 1 << endl;
    ll ans;
    cin >> ans;
    return ans;
}

int main()
{
    amazing;
    vl a(6, -1);
    vl mul(4);
    ll x[] = {4, 8, 15, 16, 23, 42};
    mul[0] = ask(0, 1);
    mul[1] = ask(1, 2);
    mul[2] = ask(2, 3);
    mul[3] = ask(3, 4);
    map<ll, ll> freq;
    fo(i, 6)
    {
        fo(j, 6)
        {
            fo(k, 6)
            {
                fo(l, 6)
                {
                    fo(r, 6)
                    {
                        if (x[i] * x[j] == mul[0] && x[j] * x[k] == mul[1] && x[k] * x[l] == mul[2] && x[l] * x[r] == mul[3])
                        {
                            a[0] = x[i];
                            a[1] = x[j];
                            a[2] = x[k];
                            a[3] = x[l];
                            a[4] = x[r];
                            freq[i]++;
                            freq[j]++;
                            freq[k]++;
                            freq[l]++;
                            freq[r]++;
                        }
                    }
                }
            }
        }
    }
    fo(i, 6)
    {
        if (freq[i] == 0)
        {
            a[5] = x[i];
        }
    }
    cout << "! ";
    fo(i, 6)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}