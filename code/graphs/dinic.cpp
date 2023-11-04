struct Dinitz
{
  struct edge
  {
    int u, v;
    ll flow, cap;
    edge(int u, int v, int flow, int cap) : u(u), v(v),
      flow(flow), cap(cap) { }
  };
  const ll flow_inf = 1e18;
  vector<edge> edges;
  int n, s, t;
  vector<vector<int> > adj; // e_num
  vector<int> layer, ptr;

  Dinitz(int n, int s, int t) : n(n), s(s), t(t)
  {
    adj = vector<vector<int> >(n);
  }

  void addEdge(int u, int v, ll cap)
  {
    int num = edges.size();
    edges.push_back(edge(u, v, 0, cap));
    edges.push_back(edge(v, u, 0, 0));
    adj[u].push_back(num);
    adj[v].push_back(num ^ 1);
  }

  void bfs()
  {
    layer = vector<int>(n, n + 2);
    layer[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
      int g = q.front();
      q.pop();
      for(int e : adj[g])
      {
        int v = edges[e].v;
        if((layer[v] > layer[g] + 1) &&
          (edges[e].flow < edges[e].cap))
        {
          layer[v] = layer[g] + 1;
          q.push(v);
        }
      }
    }
  }

  ll dfs(int u, ll pushed)
  {
    if(u == t)
    {
      return pushed;
    }
    if(pushed == 0)
      return 0;

    ll change = 0;
    for(int& id = ptr[u]; id < adj[u].size(); id++)
    {
      int e = adj[u][id];
      if((layer[edges[e].v] != layer[u] + 1) ||
        (edges[e].cap <= edges[e].flow))
        continue;
      ll fl = dfs(edges[e].v, min(pushed,
        edges[e].cap - edges[e].flow));
      edges[e].flow += fl;
      edges[e ^ 1].flow -= fl;
      pushed -= fl;
      change += fl;
      if(pushed == 0)
        return change;
    }
    return change;
  }

  ll flow()
  {
    bool found = true;
    ll ans = 0;
    while(found)
    {
      bfs();
      ptr = vector<int>(n, 0);
      ll cur = dfs(s, flow_inf);
      ans += cur;
      found = (cur > 0);
    }
    return ans;
  }
};
