#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int main()
{

    int t = 1;
    si(t);
    while (t--)
    {
        int n, d;
        si(n);
        si(d);
        vi arr;
        int c = 0;
        int x;
        fo(i, n)
        {
            si(x);
            arr.push_back(x);
            if (x > d)
                c++;
        }
        sort(arr.begin(), arr.end());
        int min = arr[0] + arr[1];
        if (c == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (min <= d)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
    return 0;
}