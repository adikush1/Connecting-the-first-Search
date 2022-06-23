#include <bits/stdc++.h>
using namespace std;
long long MAX = 1000000;
struct edge
{
    long long a, b, wt;
};
vector<edge> edges;
void bellman(int s){
    vector<long long > dist(s);
    vector<long long>par;
    for (int o=0;o<s;o++){
        dist.push_back(MAX);
        par.push_back(-1);

    }
int x;
for (int o=0;o<s;++o){
    x=-1;
    for (edge w :edges){
        if (dist[w.a]+w.wt<dist[w.b]){
         dist[w.b]=dist[w.a]+w.wt;
         par[w.b]=w.a;
         x=w.b;

        }
        }
    }
if (x==-1){
    cout<<"NO";
}else{
    for (int o=0;o<s;o++){
        x=par[x];}
        vector<long long >cycle;
        for (int v=x;;v=par[v]){
            cycle.push_back(v);
            if (v==x &&cycle.size()>1)break;

        }
        reverse(cycle.begin(),cycle.end());
        cout<<"YES"<<endl;
           for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
    }





int main()
{
    long long t, e, f, g, h, m, i, j;
    cin >> t >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> e >> f >> g;
        edge d;
        d.a = e;
        d.b = f;
        d.wt = g;
        edges.push_back(d);
    }
    bellman(t);
    return 0;
}
