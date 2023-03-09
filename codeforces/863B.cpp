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
	// ll t = 1;
	// cin >> t;
	// while (t--)
	// {
	// }
	ll n;
	cin >> n;
	vl a(2*n);
	fo(i, 2*n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vl ans;
	fo(i, 2*n)
	{
		Fo(j, i+1, 2*n)
		{
			vl new_vec;
			fo(k, 2*n)
			{
				if(k != i && k != j)
				{
					new_vec.push_back(a[k]);
				}
			}
			ll sum = 0;
			for(int i=1; i<new_vec.size(); i+=2)
			{
				sum += new_vec[i] - new_vec[i - 1];
			}
			ans.push_back(sum);
		}
	}
	cout << *min_element(ans.begin(),ans.end());
	br;
	return 0;
}