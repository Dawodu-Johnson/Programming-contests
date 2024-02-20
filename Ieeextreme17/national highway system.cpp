//
// Created by JOHNSON on 2/20/2024.
// 49.74%
#include <bits/stdc++.h>

using namespace std;


struct union_find {
    int n;
    vector<int> parent, rank;
    int connected;

    union_find(int n) : n(n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
        connected = n - 1;
    }

    int find(int a) {
        if (parent[a] == a)return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);

        if (a == b)return;

        if (rank[a] < rank[b]) {
            parent[a] = b;
            rank[b] += rank[a];
        } else {
            parent[b] = a;
            rank[a] += rank[b];
        }
        connected -= 1;
    }

    int get() { return connected; }
};
/*


int main()
{

    int n;
    cin >> n;
    string a, b;
    long long cost;
    unordered_map<string, int>store;
    int counter = 1;

    vector<tuple<long long, int, int>>mini;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
         cin >> a >> b;

         if(store.find(a) == store.end()){
            store[a] = counter++;
         }

         if(store.find(b) == store.end()) {
             store[b] = counter++;
         }
         cin >> cost;
         maxi = max(maxi, counter);

         mini.push_back({cost, store[a], store[b]});
    }

    sort(mini.begin(), mini.end());



    union_find u(maxi+1);
    long long sum =0, prev= -1;

    for(int i = 0; i < mini.size(); i++) {
         auto [cost, a, b] = mini[i];

         if(u.find(a) != u.find(b)) {
             u.unite(a,b);
             prev = cost;
             sum += cost;
         }
         else if(prev == cost){
            sum += cost;
         }
    }

    if(u.get() ==1)cout << sum << "\n";
    else cout << -1 << "\n";



    return 0;
}*/


#define ll long long
#define debug(x) cout << #x << " = " << x << '\n'
using namespace std;
const int mxn = 2e5 + 3;
const ll inf = 2e18;
struct Edge {
    int u, v, id;
    ll w;
};

struct DSU {
    vector<int> par;

    void init(int n) {
        par.resize(n + 3);
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }

    int find_set(int u) {
        return (par[u] == u) ? u : par[u] = find_set(par[u]);
    }

    bool same_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return true;
        par[v] = u;
        return false;
    }
} dsu;

struct Node {
    int par;
    ll max_w;
};
vector <Edge> edges;
vector <Edge> g[mxn];
int n, m, h[mxn];
Node jump[mxn][20];
ll d[mxn], mst_weight = 0, res[mxn];

void buildMST() {
    sort(edges.begin(), edges.end(), [&](Edge a, Edge b) {
        return a.w < b.w;
    });
    for (Edge i: edges) {
        if (dsu.same_set(i.u, i.v)) continue;
        int u = i.u, v = i.v, id = i.id;
        ll w = i.w;
        g[u].push_back({0, v, id, w});
        g[v].push_back({0, u, id, w});
        mst_weight += w;
        res[id] = -1; // edge belongs to MST
    }
}

void dfs(int u) {
    for (Edge e: g[u]) {
        int v = e.v;
        ll w = e.w;
        if (v == jump[u][0].par) continue;
        h[v] = h[u] + 1, d[v] = d[u] + w;
        jump[v][0].par = u, jump[v][0].max_w = w;
        dfs(v);
    }
}

void buildLCA() {
    dfs(1);
    for (int j = 1; j < 20; ++j) {
        for (int u = 1; u <= n; ++u) {
            int p = jump[u][j - 1].par;
            jump[u][j].par = jump[p][j - 1].par;
            jump[u][j].max_w = max(jump[u][j - 1].max_w, jump[p][j - 1].max_w);
        }
    }
}
// find max weight of some edge in path from u to v in MST
ll calc(int u, int v) {
    ll res = -inf;
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for (int j = 0; (1 << j) <= k; ++j) {
            if (k & (1 << j)) {
                res = max(res, jump[u][j].max_w);
                u = jump[u][j].par;
            }
        }
    }
    if (u == v) return res;
    int k = log2(h[u]);
    for (int j = k; j >= 0; --j) {
        if (jump[u][j].par != jump[v][j].par) {
            res = max({res, jump[u][j].max_w, jump[v][j].max_w});
            u = jump[u][j].par;
            v = jump[v][j].par;
        }
    }
    res = max({res, jump[u][0].max_w, jump[v][0].max_w});
    return res;
}

void solve() {

    cin >> m;
    unordered_map<string, int> store;
    vector <tuple<string, string, int>> stor;
    vector <tuple<long long, int, int>> mini;
    stor.push_back({"", "", 1});
    int counter = 0;
    for (int i = 1; i <= m; ++i) {
        string a, b;
        cin >> a >> b;


        if (store.find(a) == store.end()) {
            store[a] = counter++;
        }

        if (store.find(b) == store.end()) {
            store[b] = counter++;
        }

        ll w;
        cin >> w;
        stor.push_back({a, b, w});
        mini.push_back({w, store[a], store[b]});
        edges.push_back({store[a], store[b], i, w});
    }

    sort(mini.begin(), mini.end());


    union_find u(store.size() + 1);
    long long sum = 0, prev = -1;

    for (int i = 0; i < mini.size(); i++) {
        auto [cost, a, b] = mini[i];

        if (u.find(a) != u.find(b)) {
            u.unite(a, b);
            prev = cost;
            sum += cost;
        }
    }


    dsu.init(store.size());
    buildMST();
    buildLCA();

    for (Edge i: edges) {
        if (res[i.id] == -1) {
            res[i.id] = mst_weight;
            continue;
        }
        res[i.id] = mst_weight + i.w - calc(i.u, i.v);
    }

    long long minii = numeric_limits<long long>::max();

    for (int i = 1; i <= m; ++i) {
        // cout << res[i] << '\n';
        minii = min(minii, res[i]);
    }

    long long summ = 0;

    for (int i = 1; i <= m; i++) {
        if (res[i] == sum) {
            summ += get<2>(stor[i]);
        }
    }
    //cout << u.get() << endl;
    if (u.get() == 1)cout << summ << "\n";

    else cout << -1 << "\n";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("read.inp", "r", stdin);
    // freopen("write.out", "w", stdout);
    // clock_t tStart = clock();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    // fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
}
