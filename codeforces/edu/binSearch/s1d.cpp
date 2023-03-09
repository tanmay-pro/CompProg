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

int binarySearchgreater(vl &arr, ll l, ll r, ll x)
{
	ll val = -1;
	while (l + 1 < r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] >= x)
		{
			r = m;
		}
		else
		{
			l = m;
		}
	}
	return r;
}

int binarySearchlesser(vl &arr, ll l, ll r, ll x)
{
	while (l + 1 < r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] <= x)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	return l;
}

int main()
{
	ll n, k;
	cin >> n;
	vl a(n);
	fo(i, n)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cin >> k;
	while(k --)
	{
		ll l, r;
		cin >> l >> r;
		ll set = 1;
		if(l > a[n-1] || r < a[0])
		{
			set = -1;
		}
		if(set != -1)
		{
			int index1 = binarySearchgreater(a, -1, n, l);
			int index2 = binarySearchlesser(a, -1, n, r);
			cout << index2 - index1 + 1 << " ";
		}
		else
			cout << "0 ";
	}
	br;
}