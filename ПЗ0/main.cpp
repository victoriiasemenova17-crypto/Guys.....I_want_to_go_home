#include "structs.h"
#include "func.h"

int main() {

    Point point;
    Circle circle1, circle2;
    Rectangle rectangle1, rectangle2;

    double x_p, y_p;
    double x_c1, y_c1, r1;
    double x_c2, y_c2, r2;
    double x_r1, y_r1, s1;
    double x_r2, y_r2, s2;

    cout << "Enter point coordinates (x y): ";
    cin >> x_p >> y_p;
    point.set_point(x_p, y_p);

    cout << "Enter the center of the first circle (x y): ";
    cin >> x_c1 >> y_c1;
    cout << "Enter the radius of the first circle: ";
    cin >> r1;
    circle1.set_circle(x_c1, y_c1, r1);

    cout << "Enter the center of the second circle (x y): ";
    cin >> x_c2 >> y_c2;
    cout << "Enter the radius of the second circle: ";
    cin >> r2;
    circle2.set_circle(x_c2, y_c2, r2);

    cout << "Enter the top-left corner of the first square (x y): ";
    cin >> x_r1 >> y_r1;
    cout << "Enter the side length of the first square: ";
    cin >> s1;
    rectangle1.set_rectangle(x_r1, y_r1, s1);

    cout << "Enter the top-left corner of the second square (x y): ";
    cin >> x_r2 >> y_r2;
    cout << "Enter the side length of the second square: ";
    cin >> s2;
    rectangle2.set_rectangle(x_r2, y_r2, s2);

    cout << endl;

    if (point_in_circle(point, circle1))
        cout << "Point is inside Circle1\n";
    else
        cout << "Point is NOT inside Circle1\n";

    if (point_in_rectangle(point, rectangle1))
        cout << "Point is inside Square1\n";
    else
        cout << "Point is NOT inside Square1\n";

    if (point_on_circle(point, circle1))
        cout << "Point is on the boundary of Circle1\n";
    else
        cout << "Point is NOT on the boundary of Circle1\n";

    if (point_on_rectangle(point, rectangle1))
        cout << "Point is on the boundary of Square1\n";
    else
        cout << "Point is NOT on the boundary of Square1\n";

    cout << endl;

    if (circles_intersect(circle1, circle2))
        cout << "Circle1 and Circle2 intersect\n";
    else
        cout << "Circle1 and Circle2 do NOT intersect\n";

    if (rectangles_intersect(rectangle1, rectangle2))
        cout << "Square1 and Square2 intersect\n";
    else
        cout << "Square1 and Square2 do NOT intersect\n";

    if (circle_rectangle_intersect(circle1, rectangle1))
        cout << "Circle1 and Square1 intersect\n";
    else
        cout << "Circle1 and Square1 do NOT intersect\n";

    cout << endl;

    if (circle_in_circle(circle1, circle2))
        cout << "Circle1 is inside Circle2\n";
    else
        cout << "Circle1 is NOT inside Circle2\n";

    if (rectangle_in_rectangle(rectangle1, rectangle2))
        cout << "Square1 is inside Square2\n";
    else
        cout << "Square1 is NOT inside Square2\n";

    if (rectangle_in_circle(rectangle1, circle1))
        cout << "Square1 is inside Circle1\n";
    else
        cout << "Square1 is NOT inside Circle1\n";

    if (circle_in_rectangle(circle1, rectangle1))
        cout << "Circle1 is inside Square1\n";
    else
        cout << "Circle1 is NOT inside Square1\n";

    return 0;
}
