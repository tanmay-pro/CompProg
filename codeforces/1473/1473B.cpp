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
#define fo(i, n) for (i = 0; i < n; i++)
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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

long long compute_hash(string const &s)
{
    const int p = 31; // Take 53 if both uppercase and lowercase letters
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    char c;
    for (int i = 0; i < s.length(); ++i)
    {
        c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main()
{

    int q = 1;
    si(q);
    while (q--)
    {
        string s;
        string t;
        cin >> s;
        cin >> t;
        ll c = lcm(s.length(), t.length());
        string str1, str2;
        for (int i = 0; i < c / s.length(); ++i)
        {
            str1 += s;
        }
        for (int i = 0; i < c / t.length(); ++i)
        {
            str2 += t;
        }
        ll h1 = compute_hash(str1);
        ll h2 = compute_hash(str2);
        if (h1 == h2)
            cout << str1 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}