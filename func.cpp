#include <structs.h>

const double RATE = pow(10, -5);

bool equal_nums(double a, double b) {
    return fabs(a - b) < RATE;
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool point_in_circle(Point p, Circle c) {
    return distance(p, c.centre) < c.radius - RATE;
}

bool point_in_rectangle(Point p, Rectangle r) {
    double x1 = r.up_left_corner.x;
    double y1 = r.up_left_corner.y;
    double x2 = x1 + r.side;
    double y2 = y1 - r.side;
    return (p.x > x1 + RATE && p.x < x2 - RATE && p.y > y2 + RATE && p.y < y1 - RATE);
}

bool point_on_circle(Point p, Circle c) {
    return equal_nums(distance(p, c.centre), c.radius);
}

bool point_on_rectangle(Point p, Rectangle r) {
    double x1 = r.up_left_corner.x;
    double y1 = r.up_left_corner.y;
    double x2 = x1 + r.side;
    double y2 = y1 - r.side;
    bool on_left = equal_nums(p.x, x1) && p.y <= y1 && p.y >= y2;
    bool on_right = equal_nums(p.x, x2) && p.y <= y1 && p.y >= y2;
    bool on_up = equal_nums(p.y, y1) && p.x >= x1 && p.x <= x2;
    bool on_down = equal_nums(p.y, y2) && p.x >= x1 && p.x <= x2;

    return on_left || on_right || on_up || on_down;
}

bool circles_intersect(Circle c1, Circle c2) {
    double d = distance(c1.centre, c2.centre);
    return d <= c1.radius + c2.radius + RATE && d >= fabs(c1.radius - c2.radius) - RATE;
}

bool rectangles_intersect(Rectangle r1, Rectangle r2) {
    double x1_min = r1.up_left_corner.x;
    double y1_max = r1.up_left_corner.y;
    double x1_max = x1_min + r1.side;
    double y1_min = y1_max - r1.side;
    double x2_min = r2.up_left_corner.x;
    double y2_max = r2.up_left_corner.y;
    double x2_max = x2_min + r2.side;
    double y2_min = y2_max - r2.side;
    return !(x1_max < x2_min - RATE || x2_max < x1_min - RATE ||
        y1_min > y2_max + RATE || y2_min > y1_max + RATE);
}

bool circle_rectangle_intersect(Circle c, Rectangle r) {
    double x1 = r.up_left_corner.x;
    double y1 = r.up_left_corner.y;
    double x2 = x1 + r.side;
    double y2 = y1 - r.side;
    double closest_x = max(x1, min(c.centre.x, x2));
    double closest_y = max(y2, min(c.centre.y, y1));
    Point closest = { closest_x, closest_y };
    return distance(c.centre, closest) <= c.radius + RATE;
}

bool circle_in_circle(Circle c1, Circle c2) {
    double d = distance(c1.centre, c2.centre);
    return d + c1.radius < c2.radius - RATE;
}

bool rectangle_in_rectangle(Rectangle r1, Rectangle r2) {
    double x1_min = r1.up_left_corner.x;
    double y1_max = r1.up_left_corner.y;
    double x1_max = x1_min + r1.side;
    double y1_min = y1_max - r1.side;
    double x2_min = r2.up_left_corner.x;
    double y2_max = r2.up_left_corner.y;
    double x2_max = x2_min + r2.side;
    double y2_min = y2_max - r2.side;
    return (x1_min > x2_min + RATE && x1_max < x2_max - RATE &&
        y1_min > y2_min + RATE && y1_max < y2_max - RATE);
}

bool rectangle_in_circle(Rectangle r, Circle c) {
    Point p1 = r.up_left_corner;
    Point p2 = { p1.x + r.side, p1.y };
    Point p3 = { p1.x, p1.y - r.side };
    Point p4 = { p1.x + r.side, p1.y - r.side };
    return point_in_circle(p1, c) && point_in_circle(p2, c) &&
        point_in_circle(p3, c) && point_in_circle(p4, c);
}

bool circle_in_rectangle(Circle c, Rectangle r) {
    double x1 = r.up_left_corner.x;
    double y1 = r.up_left_corner.y;
    double x2 = x1 + r.side;
    double y2 = y1 - r.side;
    return (c.centre.x - c.radius > x1 + RATE &&
        c.centre.x + c.radius < x2 - RATE &&
        c.centre.y - c.radius > y2 + RATE &&
        c.centre.y + c.radius < y1 - RATE);
}
