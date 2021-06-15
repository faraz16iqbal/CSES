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
bool vis[200005];

vi parent(200005);

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

    bool found = 0;

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        vis[top] = 1;

        if (top == n)
        {
            found = 1;
            break;
        }

        for (auto u : adj[top])
        {
            if (vis[u])
                continue;
            vis[u] = 1;
            parent[u] = top;
            q.push(u);
        }
    }

    if (!found)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi path;

    while (1)
    {
        path.pb(n);
        if (n == 1)
        {
            break;
        }
        n = parent[n];
    }

    reverse(all(path));

    cout << sz(path) << ln;
    for (auto &x : path)
    {
        cout << x << " ";
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
