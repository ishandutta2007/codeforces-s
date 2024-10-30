#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Graph
{
    int n;
    vector<vector<int>> g;
    
    Graph(int n) : n(n){
        g.resize(n);
    }
    
    void add_edge(int from, int to){
        g[from].push_back(to);
    }
};

struct Tree	//create tree(directed) from graph(undirected)
{
    int n;
    int root;
    vector<vector<int>> t;
    vector<int> par;
    vector<int> dpt;
    
    void init(Graph &g, int root_){
        n = g.n;
        root = root_;
        t.resize(n);
        par.resize(n);
        dpt.resize(n);
        fill(dpt.begin(), dpt.end(), -1);
        queue<int> que;
        par[root] = -1;
        dpt[root] = 0;
        que.push(root);
        while(que.size()){
            int pa = que.front();
            que.pop();
            for(int ch : g.g[pa]){
                if(dpt[ch] == -1){
                    t[pa].push_back(ch);
                    par[ch] = pa;
                    dpt[ch] = dpt[pa] + 1;
                    que.push(ch);
                }
            }
        }
    }

    Tree(){}
    
    Tree(Graph &g, int root_){
        init(g, root_);
    }
    
    vector<int> toposort(){
        typedef pair<int, int> P;
        vector<P> p(n);
        for(int i = 0; i < n; i++) p[i] = P(dpt[i], i);
        sort(p.begin(), p.end(), greater<P>());
        vector<int> res(n);
        for(int i = 0; i < n; i++) res[i] = p[i].second;
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        a--; b--;
        Graph g(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            g.add_edge(u, v);
            g.add_edge(v, u);
        }
        Tree t1(g, a);
        int l = 0;
        for(int i = 0; i < n; i++){
            if(t1.dpt[i] > t1.dpt[l]) l = i;
        }
        Tree t2(g, l);
        int r = 0;
        for(int i = 0; i < n; i++) r = max(r, t2.dpt[i]);
        if(d <= c * 2 || t1.dpt[b] <= c || r <= c * 2) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}