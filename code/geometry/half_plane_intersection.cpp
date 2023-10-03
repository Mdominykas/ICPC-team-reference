vector<Pt> solve(vector<HalfPlane> lines)
{
  // if lines are not closed
  lines.push_back(HalfPlane(Pt(-inf,-inf),Pt(2*inf,0)));
  lines.push_back(HalfPlane(Pt(inf,-inf),Pt(0,2*inf)));
  lines.push_back(HalfPlane(Pt(inf,inf),Pt(2*(-inf),0)));
  lines.push_back(HalfPlane(Pt(-inf,inf),Pt(0,2*(-inf))));

  sort(lines.begin(), lines.end());

  deque<HalfPlane> dq;

  for(HalfPlane hp : lines)
  {
    while((dq.size() > 1) &&
      (hp.out(inter(dq.back(), dq[dq.size() - 2]))))
      dq.pop_back();
    while((dq.size() > 1) &&
      (hp.out(inter(dq[0], dq[1]))))
      dq.pop_front();

    bool wasParallel = false;
    if((!dq.empty()) &&
      (fabsl(cross(hp.pq, dq.back().pq)) < eps))
    {
      if(dot(hp.pq, dq.back().pq) < 0.0)
        return vector<Pt>();
      else if (hp.out(dq.back().p))
        dq.pop_back();
      else
        continue;
    }
    dq.push_back(hp);
  }

    while ((dq.size() > 2) &&
      (dq[0].out(inter(dq[dq.size()-1], dq[dq.size()-2]))))
        dq.pop_back();

    while ((dq.size() > 2) &&
      (dq[dq.size() - 1].out(inter(dq[0], dq[1]))))
        dq.pop_front();

  assert(!dq.empty());
  vector<Pt> internalPolygon;
  for(int i = 1; i < dq.size(); i++)
    internalPolygon.push_back(inter(dq[i], dq[i - 1]));
  internalPolygon.push_back(inter(dq[0], dq.back()));

  return internalPolygon;
}
