#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
ll MOD = 1e9 + 7;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())

const int MAX = 1001;
vector<string> grid(MAX);
int dp[1005][1005];
long long n;

void solve()
{
    cin >> n;
    forn(i, n)
    {
        cin >> grid[i];
    }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = grid[0][0] == '.' ? 1 : 0;

    // first row
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = (grid[i][0] == '.' && dp[i - 1][0] == 1) ? 1 : 0;
    }

    // first col
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = (grid[0][i] == '.' && dp[0][i - 1] == 1) ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n - 1][n - 1] % MOD;
}
int main()
{
    fast_cin();

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    // cin >> t;
    for (int it = 0; it < t; it++)
    {
        //cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}