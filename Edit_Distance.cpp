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
ll MOD = 998244353;
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

int dp[5005][5005];
string s, t;

int helper(int m, int n)
{
    if (m == 0)
        return n;
    if (n == 0)
        return m;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (s[m - 1] == t[n - 1])
        return dp[m][n] = helper(m - 1, n - 1);

    return dp[m][n] = 1 + min({helper(m - 1, n), helper(m, n - 1), helper(m - 1, n - 1)});
}

void solve()
{
    cin >> s >> t;
    int m = sz(s);
    int n = sz(t);

    // memset(dp, -1, sizeof(dp));
    // cout << helper(sz(s), sz(t));

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    cout << dp[m][n];
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