const int numberOfChildren = 12;
struct Trie
{
  struct Node
  {
    int count = 0;
    Node* child[numberOfChildren];
    Node()
    {
      for(int i = 0; i < numberOfChildren; i++)
        child[i] = NULL;
    }
  };
  Node *root;

  Trie()
  {
    root = new Node();
  }


  void add(vector<int> sequence)
  {
    root->count++;
    Node* cur = root;
    for(int i = 0; i < sequence.size(); i++)
    {
      int next = sequence[i];
      if(cur->child[next] == NULL)
      {
        cur->child[next] = new Node();
      }
      cur = cur->child[next];
      cur->count++;
    }
  }

  int numberOfOccurences(vector<int> sequence)
  {
    Node* cur = root;
    for(int i = 0; i < sequence.size(); i++)
    {
      int next = sequence[i];
      if(cur->child[next] == NULL)
        return 0;
      cur = cur->child[next];
    }
    return cur->count;
  }
};
