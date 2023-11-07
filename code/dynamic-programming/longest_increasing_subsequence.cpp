int lis(vector<int> &a)
{
  // small[i] - smallest value that length i lis can end
  vector<int> small;
  small.push_back(0);
  for(int ai : a)
  {
    if(ai > small.back())
      small.push_back(ai);
    else
    {
      int first = 0, last = small.size() - 1;
      int best = 0;
      while(first <= last)
      {
        int mid = (first + last) / 2;
        if(small[mid] < ai)
        {
          best = mid;
          first = mid + 1;
        }
        else
          last = mid - 1;
      }
      small[best + 1] = min(small[best + 1], ai);
    }
  }
  return small.size() - 1;
}
