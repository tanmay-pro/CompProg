#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265
#define br cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define amazing ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define f first
#define s second
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

int MOD = 1e9 + 7;

int main()
{
    amazing;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vs str;
        string sentence, word;
        char ch, cch;
        while ((ch = getchar()) != '\n')
        {
            sentence += ch;
        }
        sentence += ' ';
        fo(i, sentence.length())
        {
            cch = sentence[i];
            if (cch == ' ')
            {
                str.push_back(word);
                word = "";
            }
            else
            {
                word += cch;
            }
        }
        int arr[26] = {0};
        fo(i, n)
        {
            arr[(int)str[i][0] - 97]++;
        }
        vs temp;
        fo(i, n)
        {
            if (arr[str[i][0] - 97] == 1)
            {
                temp.push_back(str[i]);
            }
        }
        int ans = temp.size();
        cout << ans * (ans - 1);
        br;
    }
    return 0;
}