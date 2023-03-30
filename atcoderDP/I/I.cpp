#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
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
    ll n;
    cin >> n;
    vector<double> p(n);
    fo(i, n)
    {
    	cin >> p[i];
    }
    double dp[n+1][n+1];
    fo(i, n+1)
    {
    	fo(j, n+1)
	    {
    		dp[i][j] = 0;
	    }
    }
    dp[1][0] = 1 - p[0];
    dp[1][1] = p[0];
    Fo(i, 2, n+1)
    {
    	fo(j, n+1)
	    {
		    if(j == 0)
		    {
			    dp[i][0] = dp[i-1][0]*(1 - p[i-1]);
		    }
		    else
		    {
			    dp[i][j] = dp[i-1][j]*(1 - p[i-1]) + dp[i-1][j-1]*p[i-1];
		    }
    	}
    }
    double sum = 0;
    int x = n/2 + 1;
    while(x != n+1)
    {
    	sum += dp[n][x];
    	x++;
    }
	printf("%.10F\n", sum);
    return 0;
}