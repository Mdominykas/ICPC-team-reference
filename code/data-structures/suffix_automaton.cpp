struct suffixAutomaton
{
  struct node
  {
    int link, len;
    map<char, int> next;
  };

  int last;
  vector<node> nodes;

  suffixAutomaton()
  {
    node root;
    root.link = -1;
    root.len = 0;
    nodes.push_back(root);
    last = 0;
  }

  void extend(char c)
  {
    int p = last;
    int cur = nodes.size();
    nodes.push_back(node());
    nodes[cur].len = nodes[last].len + 1;
    while((p != -1) && (nodes[p].next.count(c) == 0))
    {
      nodes[p].next[c] = cur;
      p = nodes[p].link;
    }
    if(p != -1)
    {
      int q = nodes[p].next[c];
      if(nodes[q].len == nodes[p].len + 1)
      {
        nodes[cur].link = q;
      }
      else
      {
        int clone = nodes.size();
        nodes.push_back(nodes[q]);
        nodes[clone].len = nodes[p].len + 1;
        while((p != -1) && (nodes[p].next.count(c) > 0)
          && (nodes[p].next[c] == q))
        {
          nodes[p].next[c] = clone;
          p = nodes[p].link;
        }
        nodes[q].link = nodes[cur].link = clone;
      }
    }
    else
    {
      nodes[cur].link = 0;
    }

    last = cur;
  }
};