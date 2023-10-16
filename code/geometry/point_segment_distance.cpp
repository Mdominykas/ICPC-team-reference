ld pointToSegment(Pt p, pair<Pt, Pt> line){
  Pt ln = line.second - line.first;
  ld proj1 = dot(ln, p - line.first);
  ld proj2 = dot(Pt(0, 0) - ln, p - line.second);
  if((proj1 < 0) || (proj2 < 0))
    return min(dist(p, line.first), dist(p, line.second));

  ld d = dist(line.first, line.second);
  Pt base = line.first + ln * (proj1 / (d * d));
  return dist(base, p);
}
