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
        vl a(n);
        fo(i, n)
        {   
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool zeropresent  = false;
        fo(i, n)
        {
            if(a[i] == 0)
            {
                zeropresent = true;
                break;
            }
        }
        if(zeropresent)
        {
            ll ans = 0;
            fo(i, n)
            {
                if(a[i] != 0)
                {
                    ans++;
                }
            }    
            cout << ans;
            br;
        }
        else
        {
            bool duplicatepresent = false;
            fo(i, n)
            {
                if(a[i] == a[i+1])
                {
                    duplicatepresent = true;
                    break;
                }
            }
            if(duplicatepresent)
            {
                cout << n;
                br;
            }
            else
            {
                cout << n+1;
                br;
            }
        }
        
    }
    return 0;
}