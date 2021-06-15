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

int n, m;
vector<int> adj[200005];

bool vis[100005];

void dfs(int node)
{
    if (vis[node])
        return;
    vis[node] = 1;

    for (auto &x : adj[node])
    {
        dfs(x);
    }
}

void solve()
{
    cin >> n >> m;

    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<int> res;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            res.pb(i);
        }
    }

    cout << res.size() - 1 << ln;

    for (int i = 1; i < sz(res); i++)
    {
        cout << res[i - 1] << " " << res[i] << ln;
    }
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