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
	vl cubes;
	fo(i, n)
	{
		ll x;
		cin >> x;
		cubes.push_back(x);
	}
	vl array;
	array.push_back(cubes[0]);
	Fo(i, 1, cubes.size())
	{
		ll ind = upper_bound(array.begin(), array.end(), cubes[i]) - array.begin();
		if (ind == array.size())
		{
			array.push_back(cubes[i]);
		}
		else
		{
			array[ind] = cubes[i];
		}
	}
	cout << array.size();
	br;
	return 0;
	// vl input(n);
	// vl heap;
	// fo(i,n)
	// {
	// 	cin >>input[i];
	// }
	// fo(i, n)
	// {
	// 	ll x = input[i];
	// 	auto it = upper_bound(heap.begin(), heap.end(), x);
	// 	if(it == heap.end())
	// 	{
	// 		heap.push_back(x);
	// 		continue;
	// 	}
	// 	int index = it - heap.begin();
	// 	heap[index] = x;
	// }
	// cout << heap.size();
	// br;
	// return 0;
}