#include <cstdio>
#include <cmath>

struct Point{ double x, y; };  // 结构体

double dist(struct Point a, struct Point b)
{
    return hypot(a.x-b.x, a.y-b.y);
}

// Or:
typedef struct{ double x, y; }Point2;

double dist2(Point2 a, Point2 b)
{
    return hypot(a.x-b.x, a.y-b.y);
}

int main()
{
    struct Point m, n;
    m.x = 5, m.y = 10, n.x = 3, n.y = 17;
    printf("%f\n", dist(m, n));

    Point2 o, p;
    o.x = 5, o.y = 10, p.x = 3, p.y = 17;
    printf("%f\n", dist2(o, p));
    return 0;
}