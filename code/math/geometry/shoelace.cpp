double Shoelace(double X[], double Y[], int N)
{
  double ats = 0;
  for(int i=0; i<N; i++)
  {
    ats += X[i]*Y[(i+1)%N] - X[(i+1)%N]*Y[i];
  }
  ats /= (double) 2;
  return abs(ats);
}
