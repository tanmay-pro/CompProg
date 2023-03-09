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

// ll recursiveSum(vl &a, ll i, ll sum1, ll sum2)
// {
// 	if(i == a.size())
// 		return abs(sum1 - sum2);
// 	return min(recursiveSum(a, i+1, sum1 + a[i], sum2), recursiveSum(a, i+1, sum1, sum2 + a[i]));
// }


// int main()
// {
//     amazing;
// 	ll n;
// 	cin >> n;
// 	vl a(n);
// 	fo(i, n) cin >> a[i];
// 	cout << recursiveSum(a, 0, 0, 0) << endl;
// }

int main()
{
	amazing;
	ll n;
	cin >> n;
	vl a(n);
	ll minim = LONG_LONG_MAX;
	fo(i, n) cin >> a[i];
	for (ll i = 0; i < (1<< n); i++)
	{
		ll sum1 = 0, sum2 = 0;
		for(ll j= 0; j < n; j++)
		{
			if(i & (1 << j))
				sum1 += a[j];
			else
				sum2 += a[j];
		}
		minim = min(minim, abs(sum1 - sum2));
	}
	cout << minim << endl;
}