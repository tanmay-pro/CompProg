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
        ll px, py;
        cin >> px >> py;
        string str;
        cin >> str;
        ll xf = 0;
        ll yf = 0;
        ll rcount = 0, ucount = 0, lcount = 0, dcount = 0;
        fo(i, str.length())
        {
            if (str[i] == 'R')
            {
                xf++;
                rcount++;
            }
            else if (str[i] == 'L')
            {
                xf--;
                lcount++;
            }
            else if (str[i] == 'U')
            {
                yf++;
                ucount++;
            }
            else if (str[i] == 'D')
            {
                yf--;
                dcount++;
            }
        }
        ll diffx = px - xf;
        ll diffy = py - yf;
        bool setx = false;
        bool sety = false;
        if (diffx < 0)
        {
            if (abs(diffx) <= rcount)
            {
                setx = true;
            }
        }
        else if (diffx == 0)
        {
            setx = true;
        }
        else
        {
            if (abs(diffx) <= (lcount))
            {
                setx = true;
            }
        }
        if (diffy < 0)
        {
            if (abs(diffy) <= ucount)
            {
                sety = true;
            }
        }
        else if (diffy == 0)
        {
            sety = true;
        }
        else
        {
            if (abs(diffy) <= (dcount))
            {
                sety = true;
            }
        }
        if (setx == true && sety == true)
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
    return 0;
}