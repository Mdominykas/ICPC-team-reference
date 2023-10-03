struct Pt
{
  long double x, y;
  Pt() : x(0), y(0) { }
  Pt(long double x, long double y) : x(x), y(y) { }
  friend Pt operator+(const Pt &p, const Pt &q)
  {
    return Pt(p.x + q.x, p.y + q.y);
  }
  friend Pt operator-(const Pt &p, const Pt &q)
  {
    return Pt(p.x - q.x, p.y - q.y);
  }
  friend Pt operator*(const Pt &p, const long double k)
  {
    return Pt(p.x * k, p.y * k);
  }
  friend long double dot(const Pt &p, const Pt &q)
  {
    return p.x * q.x + p.y * q.y;
  }
  friend long double cross(const Pt &p, const Pt &q)
  {
    return p.x * q.y - p.y * q.x;
  }
};

struct HalfPlane
{
  // p - passing point, pq - direction vector
  Pt p, pq;
  double angle;
  HalfPlane(Pt p, Pt pq) : p(p), pq(pq)
  {
    angle = atan2(pq.y, pq.x);
  }
  bool operator<(const HalfPlane &other) const
  {
    return angle < other.angle;
  }
  bool out(const Pt &r)
  {
    return cross(pq, r - p) < -eps;
  }
  friend Pt inter(HalfPlane const &s, HalfPlane const &t)
  {
    return s.p +
    s.pq * (cross(t.p - s.p, t.pq) / cross(s.pq, t.pq));
  }
};

struct Pt3
{
  long double x, y, z;
  Pt3() : x(0), y(0), z(0) { }
  Pt3(long double x, long double y) : x(x), y(y) { }
  friend Pt3 operator+(const Pt3 &p, const Pt3 &q)
  {
    return Pt3(p.x + q.x, p.y + q.y, p.z + q.z);
  }
  friend Pt3 operator-(const Pt3 &p, const Pt3 &q)
  {
    return Pt3(p.x - q.x, p.y - q.y), p.y - q.y;
  }
  friend Pt3 operator*(const Pt3 &p, const long double k)
  {
    return Pt3(p.x * k, p.y * k, p.z * k);
  }
  friend long double dot(const Pt3 &p, const Pt3 &q)
  {
    return p.x * q.x + p.y * q.y + p.z * q.z;
  }
  friend Pt3 cross(const Pt3 &a, const Pt3 &b)
  {
    return Pt3(a.y * b.z - a.z * b.y,
               a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
  }
};
