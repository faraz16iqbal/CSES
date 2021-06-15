#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
char moves[4] = {'L', 'U', 'R', 'D'};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

vll arr(5005);
ll dp[5005][5005];

ll recurse(int l, int r, ll score, bool turn)
{
    if (l > r)
    {
        return score;
    }

    if (turn)
    {
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
    }
    else
    {
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
    }

    if (turn)
    {
        return dp[l][r] = max(recurse(l + 1, r, score + arr[l], !turn), recurse(l, r - 1, score + arr[r], !turn));
    }

    return dp[l][r] = min(recurse(l + 1, r, score, !turn), recurse(l, r - 1, score, !turn));
}

void solve()
{
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    forn(i, n)
    {
        cin >> arr[i];
    }

    ll score = 0;
    recurse(0, n - 1, score, true);

    cout << dp[0][n - 1];
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