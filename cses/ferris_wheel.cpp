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
	ll n, x;
	cin >> n >> x;
	vl p(n);
	fo(i, n)
	{
		cin >> p[i];
	}
	sort(p.begin(), p.end(), greater<ll>());
	int j = n - 1;
	int ans = 0;
	fo(i, n)
	{
		if (i > j)
			break;
		else if (i == j)
		{
			ans++;
			break;	
		}
		if (p[i] + p[j] <= x)
		{
			j--;
			ans++;
		}
		else
		{
			ans++;
		}
	}
	cout << ans;
	br;
	// int j = n-1;
	// ll count = 0;
	// for(int i =0; i<n;)
	// {
	// 	if(i == j)
	//     {
	// 		if(p[i] <= x)
	// 	    {
	// 			count++;
	// 	    }
	//     }
	//     if(j <= i)
	// 	    break;
	// 	if(p[i] + p[j] <= x)
	//     {
	// 		count++;
	//         i++;
	//         j--;
	//     }
	// 	else
	//     {
	// 		j--;
	// 		count++;
	//     }
	// }
	// cout << count;
	// br;
	return 0;
}