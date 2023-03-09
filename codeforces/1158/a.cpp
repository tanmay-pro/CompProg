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
//    ll t = 1;
//    cin >> t;
//    while (t--)
//    {
//    }
	ll n, m;
	cin >> n >> m;
	ll sum = 0;
	vl b(n), g(m);
	fo(i, n)
	{
		cin >> b[i];
	}
	fo(i, m)
	{
		cin >> g[i];
	}
	sort(b.begin(), b.end());
	if(*min_element(g.begin(), g.end()) < b[n-1])
	{
		cout << -1;
		return 0;
	}
	ll min_sum = 0;
	fo(i, n-1)
	{
		min_sum += b[i];
	}
	fo(i, m)
	{
		sum += g[i];
		sum += min_sum;
	}
	if(*min_element(g.begin(), g.end()) != b[n-1])
	{
		sum -=b[n-2];
		sum+=b[n-1];
	}
	cout << sum;
	br;
	return 0;
}