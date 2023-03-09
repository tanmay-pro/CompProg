#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define sp cout << " "
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
int p = 31;

int main()
{
    amazing;
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a;
        fo(i, n)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        fo(i, n)
        {
            while (a[i] > n)
            {
                a[i] /= 2;
            }
        }
        ll freq[n + 1] = {0};
        fo(i, n)
        {
            freq[a[i]]++;
        }
        int k = 0;
        fo(j, n)
        {
            Fo(i, 1, n + 1)
            {
                if (freq[i] > 1)
                {
                    freq[i / 2]++;
                    freq[i]--;
                }
            }
        }
        Fo(i, 1, n+1)
        {
            if (freq[i] == 1)
            {
                k++;
            }
        }
        if(k == n)
        {
            cout << "YES";
            br;
        }
        else 
        {
            cout << "NO";
            br;
        }
    }
}