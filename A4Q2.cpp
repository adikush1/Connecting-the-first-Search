#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> adlist[1000000];
long long MAX = 1000000;
long long min_edge[1000000] = {0};
long long max_edge[1000000] = {0};
long long dist[1000000];
long long nsp[1000000];
const long long modulo = int(1e9) + 7;

long long processed[1000000] = {0};

long long mindist(long long arr[], long long n, long long process[])
{
    long long min = MAX;
    long long min_index = MAX;
    for (long long o = 1; o < n + 1; o++)
    {
        if (process[o] == 0 && min >= arr[o])
        {
            min = arr[o];
            min_index = o;
        }
    }
    return min_index;
}
void dijskitra(long long p, long long n)
{
    for (long long l = 0; l < 1000000; l++)
    {
        dist[l] = MAX;
        nsp[l] = 1;
    }

    dist[p] = 0;
    for (long long q = 1; q <= n; q++)
    {
        long long u = mindist(dist, n, processed);
        processed[u] = 1;
        if (u == MAX)
            break;
        for (auto edge : adlist[u])
        {
            long long  conn = edge.first;
            long long wt = edge.second;
            if (dist[u] + wt < dist[conn]&&processed[conn]==0)
            {
                dist[conn] = (dist[u] + wt) % modulo;
                nsp[conn] = nsp[u];
                min_edge[conn] = min_edge[u] + 1;
                max_edge[conn] = max_edge[u] + 1;
            }
            else if (dist[u] + wt == dist[conn]&&processed[conn]==0)
            {
                nsp[conn] = (nsp[conn] + nsp[u]) % modulo;
                if (min_edge[conn] > min_edge[u] + 1)
                {
                    min_edge[conn] = min_edge[u] + 1;
                }
                if (max_edge[conn] < max_edge[u] + 1)
                {
                    max_edge[conn] = max_edge[u] + 1;
                }
            }
        }
    }
    cout << dist[n] << " " << nsp[n] << " " << min_edge[n] << " " << max_edge[n];
}
int main()
{
    long long t, e, f, g, h, m, i, j;
    cin >> t >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> e >> f >> g;
        adlist[e].push_back({f, g});
    }
    dijskitra(1, t);

    return 0;
}