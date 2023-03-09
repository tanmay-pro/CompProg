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
        ll m;
        cin >> m;
        vvl a(2, vl(m));
        fo(i, 2)
        {
            fo(j, m)
            {
                char c;
                cin >> c;
                if (c == 'W')
                    a[i][j] = 0;
                else
                    a[i][j] = 1;
            }
        }
        if (a[0][0] == 1 && a[1][0] == 1)
        {
            map<pll, bool> visited;
            pll currCell;
            currCell = {0, 0};

            visited[currCell] = true;
            Fo(i, 1, m)
            {
                currCell.second = i;
                if (a[currCell.first][i] == 0)
                {
                    break;
                }
                else
                {
                    visited[currCell] = true;
                }
                if (currCell.first == 0)
                {
                    if (a[1][i] == 1)
                    {
                        currCell.first = 1;
                        visited[currCell] = true;
                    }
                }
                else if (currCell.first == 1)
                {
                    if (a[0][i] == 1)
                    {
                        currCell.first = 0;
                        visited[currCell] = true;
                    }
                }
            }

            map<pll, bool> visited2;
            pll currCell2;
            currCell2 = {1, 0};
            
            visited2[currCell2] = true;
            Fo(i, 1, m)
            {
                currCell2.second = i;
                if (a[currCell2.first][i] == 0)
                {
                    break;
                }
                else
                {
                    visited2[currCell2] = true;
                }
                if (currCell2.first == 0)
                {
                    if (a[1][i] == 1)
                    {
                        currCell2.first = 1;
                        visited2[currCell2] = true;
                    }
                }
                else if (currCell2.first == 1)
                {
                    if (a[0][i] == 1)
                    {
                        currCell2.first = 0;
                        visited2[currCell2] = true;
                    }
                }
            }
            if (visited[{1, m - 1}] || visited[{0, m - 1}] || visited2[{1, m - 1}] || visited2[{0, m - 1}])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            map<pll, bool> visited;
            pll currCell;
            if (a[0][0] == 1)
                currCell = {0, 0};
            else
                currCell = {1, 0};
            // cout << currCell.first << " " << currCell.second << endl;
            visited[currCell] = true;
            Fo(i, 1, m)
            {
                currCell.second = i;
                if (a[currCell.first][i] == 0)
                {
                    break;
                }
                else
                {
                    visited[currCell] = true;
                    // cout << currCell.first << " " << i << endl;
                }
                if (currCell.first == 0)
                {
                    if (a[1][i] == 1)
                    {
                        currCell.first = 1;
                        visited[currCell] = true;
                        // cout << currCell.first << " " << i << endl;
                    }
                }
                else if (currCell.first == 1)
                {
                    if (a[0][i] == 1)
                    {
                        currCell.first = 0;
                        visited[currCell] = true;
                        // cout << currCell.first << " " << i << endl;
                    }
                }
            }
            if (visited[{1, m - 1}] || visited[{0, m - 1}])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}