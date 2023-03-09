#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
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

int main()
{
    amazing;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vvl array;
        fo(i, n)
        {
            vl temp;

            fo(j, m)
            {
                ll x;
                cin >> x;
                temp.push_back(x);
            }
            array.push_back(temp);
        }
        vl bad;
        fo(i, n)
        {
            if (bad.empty())
            {
                vl b = array[i];
                sort(b.begin(), b.end());
                fo(j, m)
                {
                    if (array[i][j] != b[j])
                    {
                        bad.push_back(j);
                    }
                }
            }
            else
            {
                break;
            }
        }

        if (bad.size() == 0)
        {
            cout << "1 1";
        }
        else if (bad.size() > 2)
        {
            cout << "-1";
        }
        else
        {
            fo(i, n)
                swap(array[i][bad[0]], array[i][bad[1]]);
            bool temp = false;
            fo(i, n)
            {
                Fo(j, 1, m)
                {
                    if (array[i][j] < array[i][j - 1])
                    {
                        temp = true;
                        break;
                    }
                }
                if (temp)
                {
                    break;
                }
            }
            if (!temp)
            {
                cout << bad[0] + 1 << " " << bad[1] + 1;
            }
            else
            {
                cout << "-1";
            }
        }
        br;
    }
    return 0;
}