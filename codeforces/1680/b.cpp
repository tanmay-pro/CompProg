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
#define file_read                   \
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
    int n, m;
    cin >> n >> m;
    string str[n];
    vpl v;
    fo(i, n)
    {
      cin >> str[i];
      fo(j, m)
      {
        if (str[i][j] == 'R')
        {
          v.push_back(make_pair(i, j));
        }
      }
    }
    sort(v.begin(), v.end());
    ll mini = v[0].first;
    ll minj = v[0].second;
    fo(i, v.size())
    {
      v[i].f -= mini;
      v[i].second -= minj;
    }
    bool check  = false;
    fo(i, v.size())
    {
      if(v[i].s < 0 || v[i].f < 0)
      {
        check = true;
        break;
      }
      // cout << v[i].f << " " << v[i].second << endl;
    }
    if(check)
    {
      cout << "NO";
      br;
    }
    else
    {
      cout << "YES";
      br;
    }
  }
  return 0;
}