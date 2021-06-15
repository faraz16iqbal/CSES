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

const int N = 1005;
int m, n, x, y;
string grid[N];
bool vis[N][N];

char moves[4] = {'L', 'U', 'R', 'D'};
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

// L, R, D, U
char parent[N][N];
pair<int, int> previous[N][N];

bool isValid(int xx, int yy)
{
    if (xx < 0 || xx >= m || yy < 0 || yy >= n || vis[xx][yy])
        return false;
    if (grid[xx][yy] == '#')
    {
        return false;
    }
    return true;
}

void solve()
{
    cin >> m >> n;

    forn(i, m)
    {
        cin >> grid[i];
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'A')
                x = i, y = j;
        }
    }
    queue<pii> Q;

    Q.push({x, y});
    vis[x][y] = 1;

    bool found = 0;
    int xB, yB;

    while (!Q.empty())
    {
        auto top = Q.front();
        int xx = top.first;
        int yy = top.second;
        Q.pop();

        if (grid[xx][yy] == 'B')
        {
            found = 1;
            xB = xx;
            yB = yy;

            // cout << xx << "  " << yy << " ";
            break;
        }

        forn(i, 4)
        {
            int X = xx + dx[i], Y = yy + dy[i];
            if (isValid(X, Y))
            {
                vis[X][Y] = true;
                Q.push({X, Y});
                parent[X][Y] = moves[i];
                previous[X][Y] = {xx, yy};
            }
        }
    }

    if (!found)
    {
        cout << "NO\n";
        return;
    }

    vector<int> path;

    while (x != xB || y != yB)
    {

        path.pb(parent[xB][yB]);
        pii temp = previous[xB][yB];
        xB = temp.first;
        yB = temp.second;
    }

    reverse(all(path));

    cout << "YES\n"
         << sz(path) << ln;

    for (char x : path)
    {
        cout << x;
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