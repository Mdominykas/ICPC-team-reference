struct node
{
  int start, finish;
  long long value, lazy;
  node *left, *right;
  node() { }
  node(int pr, int pb, int A[])
  {
    start = pr;
    finish = pb;
    lazy = 0;
    if(start == finish)
    {
      left = NULL;
      right = NULL;
      value = A[start];
    }
    else
    {
      left = new node(pr, (pr + pb) / 2, A);
      right = new node((pr + pb) / 2+1, pb, A);
      value = min(left->value, right->value);
    }
  }
  long long get(int pr, int pb)
  {
    fix();
    if((pr <= start) && (finish <= pb))
      return value;
    else if ((finish < pr) || (pb < start))
      return INT_MAX;
    else
      return min(left->get(pr, pb), right->get(pr, pb));
  }
  void fix()
  {
    if(lazy != 0)
    {
      if(left != NULL)
      {
        left->lazy += lazy;
        left->value += lazy;
        right->lazy += lazy;
        right->value += lazy;
      }
      lazy = 0;
    }
  }
  void update(int pr, int pb, long long delta)
  {
    fix();
    if((pr <= start) && (finish <= pb))
    {
        lazy += delta;
        value += delta;
    }
    else if ((finish < pr) || (pb < start))
    {
      return;
    }
    else
    {
      left->update(pr, pb, delta);
      right->update(pr, pb, delta);
      value = min(left->value, right->value);
    }
  }
};
