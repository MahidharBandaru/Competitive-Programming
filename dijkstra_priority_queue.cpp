//Here n is a global variable denoting the number of nodes in the graph
void dijkstra(ll s, ll d[], ll p[]) {
    fill(d, d+n, inf);
    fill(p, p+n, -1);

    d[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        ll dist = d[v];
        for (auto edge : adj1[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (dist + len < d[to]) {
                d[to] = dist + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
