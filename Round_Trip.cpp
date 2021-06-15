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

int m, n;
vi adj[200005];
bool visited[100005];

int parent[100005];

void dfs(int node)
{
    visited[node] = true;
    for (auto u : adj[node])
    {
        if (!visited[u])
        {
            parent[u] = node;
            // cout << u << " " << parent[u] << " ";
            dfs(u);
        }
        else if (visited[u] && u != parent[node])
        {

            vi res;
            res.push_back(u);
            while (1)
            {
                res.pb(node);
                if (u == node)
                {
                    break;
                }
                node = parent[node];
            }
            // cout << u << " " << parent[u] << " " << parent[parent[0]] << " ";

            reverse(all(res));

            cout << sz(res) << ln;

            for (auto &x : res)
            {
                cout << x << " ";
            }
            exit(0);
        }
    }
}

void solve()
{
    memset(visited, false, sizeof(visited));
    cin >> n >> m;

    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE";
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