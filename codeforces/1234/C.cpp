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

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vl a(n * 2);
        string str1;
        cin >> str1;
        fo(i, n)
        {
            a[i] = str1[i] - '0';
        }
        string str2;
        cin >> str2;
        fo(i, n)
        {
            a[i + n] = str2[i] - '0';
        }
        ll currX = 0;
        ll prevmove = 1;
        while (currX < 2 * n)
        {
            if (a[currX] == 1 || a[currX] == 2)
            {
                if (prevmove == 2)
                {
                    break;
                }
                currX++;
                if (currX == n)
                {
                    break;
                }
            }
            else
            {
                if (prevmove == 1)
                {
                    if (currX < n)
                        currX += n;
                    else
                        currX -= n;
                    prevmove = 2;
                }
                else if (prevmove = 2)
                {
                    currX += 1;
                    prevmove = 1;
                    if (currX == n)
                    {
                        break;
                    }
                }
            }
        }
        if (currX == 2 * n)
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