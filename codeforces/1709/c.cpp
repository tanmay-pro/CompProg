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
        string str;
        cin >> str;
        ll n = str.length();
        ll clos = 0, open = 0, ques = 0;
        if (str[0] == '?')
        {
            str[0] = '(';
        }
        if (str[n - 1] == '?')
        {
            str[n - 1] = ')';
        }
        fo(i, n)
        {
            if (str[i] == '?')
            {
                ques++;
            }
            else if (str[i] == ')')
            {
                clos++;
            }
            else
            {
                open++;
            }
        }

        ll ro = 0, rc = 0;
        ll val = abs(clos - open);
        ro += (ques - val) / 2;
        rc += (ques - val) / 2;
        if (clos > open)
        {
            ro += val;
        }
        else
        {
            rc += val;
        }
        vl ind;
        fo(i, n)
        {
            if (str[i] == '?')
            {
                ind.pb(i);
            }
        }
        if (rc == 0 || ro == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        string corr = "";
        vl neg;
        vl pos;
        fo(i, n)
        {
            if (str[i] != '?')
            {
                corr += str[i];
            }
            else
            {
                if (ro > 0)
                {
                    corr += '(';
                    ro--;
                    pos.push_back(i);
                }
                else
                {
                    corr += ')';
                    rc--;
                    neg.push_back(i);
                }
            }
        }
        bool check = 0;
        fo(i, pos.size())
        {
            string tmp = corr;
            if (corr[pos[i]] == '(')
            {
                tmp[pos[i]] = ')';
                tmp[neg[0]] = '(';
            }
            bool flag = 1;
            // cout << tmp << endl;
            ll openSoFar = 0, closedSofar = 0;
            fo(j, n)
            {
                if (tmp[j] == '(')
                {
                    openSoFar++;
                }
                else if (tmp[j] == ')')
                {
                    closedSofar++;
                }
                if (closedSofar > openSoFar)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                check = 1;
                break;
            }
        }
        if (!check)
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