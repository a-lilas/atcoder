#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define ALL(n) (n).begin(), (n).end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> mat;

const ll MAX_V = 100000;
const ll INF = 1e9;
const ll MOD = 998244353;

class Dinic{
    // to:頂点インデックス, cap:容量, rev:逆辺を表すGのインデックス
    struct edge{int to, cap, rev;};
    void bfs(int s);
    int dfs(int v, int t, int f);
    public:
        // G:隣接リスト, level:sからの距離, iter:調べたかどうかのフラグ
        vector<vector<edge>> G;
        int level[MAX_V];
        int iter[MAX_V];
        Dinic(mat g);
        int solve(int s, int t);
};

Dinic::Dinic(mat g){
    G.resize(MAX_V);
    // g : 隣接行列, Dinic.G : 隣接リスト
    REP(from, g.size()) REP(to, g.size()){
        if (g[from][to] > 0){
            G[from].pb((edge){to, g[from][to], G[to].size()});
            G[to].pb((edge){from, 0, G[from].size()-1});
        }
    }
}

// フローを流せる全ての頂点について，頂点sからの最短距離をBFSで計算する
void Dinic::bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        REP(i, G[v].size()){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int Dinic::dfs(int v, int t, int f){
    if (v == t) return f;
    for (int i=iter[v]; i<G[v].size(); i++){
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int Dinic::solve(int s, int t){
    // cout << G[0][0].cap << endl;
    int flow = 0;
    while(true){
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }

}

int main(){
    int N, G, E; cin >> N >> G >> E;
    // g[N][N]
    mat g(N+1, vi(N+1, 0));
    REP(i, G){
        int p;
        cin >> p;
        g[p][N] = 1;
        g[N][p] = 1;
    }
    REP(i, E){
        int a, b; cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
     }

     Dinic dn(g);
     int ans = dn.solve(0, N);
     cout << ans << endl;
}