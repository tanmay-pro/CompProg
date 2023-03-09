#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define endl "\n"
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(container, it) \
    for (auto it = container.begin(); it != container.end(); it++)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
ll MOD = 1e9 + 7;
int p = 31;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        string str;
        cin >> str;
        ll num[10] = {0};
        fo(i, len)
        {
            num[str[i] - '0']++;
        }
        if(num[1] != 0)
        {
            cout << 1;
            br;
            cout << 1;
            br;
        }
        else if(num[4] != 0)
        {
            cout << 1;
            br;
            cout << 4;
            br;
        }
        else if(num[6] != 0)
        {
            cout << 1;
            br;
            cout << 6;
            br;
        }
        else if(num[8] != 0)
        {
            cout << 1;
            br;
            cout << 8;
            br;
        }
        else if(num[9] != 0)
        {
            cout << 1;
            br;
            cout << 9;
            br;
        }
        else if(num[2] != 0 && str[0] != '2')
        {
            ll index = 0;
            fo(i, len)
            {
                if(str[i] == '2')
                {
                    index = i;
                    break;
                }
            }
            string sub = str.substr(index-1, 2);
            cout << 2;
            br;
            cout << sub;
            br;
        }
        else if (num[5] != 0 && str[0] != '5')
        {
            ll index = 0;
            fo(i, len)
            {
                if (str[i] == '5')
                {
                    index = i;
                    break;
                }
            }
            string sub = str.substr(index - 1, 2);
            cout << 2;
            br;
            cout << sub;
            br;
        }
        else if(str[0] == '2' && num[7] != 0)
        {
            cout << 2;
            br;
            cout << 27;
            br;
        }
        else if(str[0] == '2' && num[3] > 1)
        {
            cout << 2;
            br;
            cout << 33;
            br;
        }
        else if(num[3] > 1)
        {
            cout << 2;
            br;
            cout << 33;
            br;
        }
        else if(num[7] > 1)
        {
            cout << 2;
            br;
            cout << 77;
            br;
        }
        else if(num[5] > 1)
        {
            cout << 2;
            br;
            cout << 55;
            br;
        }
        else if(num[2] > 1)
        {
            cout << 2;
            br;
            cout << 22;
            br;
        }
        else if(str[0] == '5' && num[7] != 0)
        {
            cout << 2;
            br;
            cout << 57;
            br;
        }
    }
    return 0;
}