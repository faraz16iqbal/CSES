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
vector<int> adj[200005];
vector<bool> visited(100005, 0);
vector<int> color(100005, 0);

void solve()
{
    cin >> n >> m;

    forn(i, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bool isBipartite = true;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            q.push(i);
            visited[i] = 1;
            color[i] = 1;

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (auto &node : adj[curr])
                {
                    if (!visited[node])
                    {
                        visited[node] = 1;
                        color[node] = color[curr] ^ 1;
                        q.push(node);
                    }
                    else
                    {
                        isBipartite &= color[curr] != color[node];
                    }
                }
            }
        }
    }

    if (!isBipartite)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (color[i])
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 2 << " ";
        }
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