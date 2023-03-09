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

int binarySearch(vl &arr, ll l, ll r, ll x)
{
	ll val = -1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] == x)
		{
			val = m;
			r = m;
			Fo(j, m+1 , arr.size())
			{
				if(arr[j] == x)
				{
					val = j;
					r = j;
				}
				else
					break;
			}
			break;
		}
		if (arr[m] < x)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return r;
}

int main()
{
    amazing;
//    ll t = 1;
//    cin >> t;
//    while (t--)
//    {
//    }
	ll n, k;
	cin >> n >> k;
	vl a(n);
	fo(i, n)
	{
		cin >> a[i];
	}
	while(k--)
	{
		ll x;
		cin >> x;
		if(x < a[0])
		{
			cout << 0;
			br;
			continue;
		}
		int index = binarySearch(a, 0, n-1, x);
		cout << index + 1;
		br;
	}
		
    return 0;
}