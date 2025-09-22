#include "structs.h"
#include "func.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Point point;
    Circle circle1, circle2;
    Rectangle rectangle1, rectangle2;

    double x_p, y_p;
    double x_c1, y_c1, r1;
    double x_c2, y_c2, r2;
    double x_r1, y_r1, s1;
    double x_r2, y_r2, s2;

    cout << "Введите координаты точки (x y): ";
    cin >> x_p >> y_p;
    point.set_point(x_p, y_p);

    cout << "Введите координаты центра первого круга (x y): ";
    cin >> x_c1 >> y_c1;
    cout << "Введите радиус первого круга: ";
    cin >> r1;
    circle1.set_circle(x_c1, y_c1, r1);
    cout << "Введите координаты центра второго круга (x y): ";
    cin >> x_c2 >> y_c2;
    cout << "Введите радиус второго круга: ";
    cin >> r2;
    circle2.set_circle(x_c2, y_c2, r2);

    cout << "Введите координаты левого верхнего угла первого квадрата (x y): ";
    cin >> x_r1 >> y_r1;
    cout << "Введите сторону первого квадрата: ";
    cin >> s1;
    rectangle1.set_rectangle(x_r1, y_r1, s1);
    cout << "Введите координаты левого верхнего угла второго квадрата (x y): ";
    cin >> x_r2 >> y_r2;
    cout << "Введите сторону второго квадрата: ";
    cin >> s2;
    rectangle2.set_rectangle(x_r2, y_r2, s2);
    cout << endl;

    if (point_in_circle(point, circle1))
        cout << "Точка находится внутри Круга1\n";
    else
        cout << "Точка НЕ находится внутри Круга1\n";

    if (point_in_rectangle(point, rectangle1))
        cout << "Точка находится внутри Квадрата1\n";
    else
        cout << "Точка НЕ находится внутри Квадрата1\n";

    if (point_on_circle(point, circle1))
        cout << "Точка лежит на окружности Круга1\n";
    else
        cout << "Точка НЕ лежит на окружности Круга1\n";

    if (point_on_rectangle(point, rectangle1))
        cout << "Точка лежит на стороне Квадрата1\n";
    else
        cout << "Точка НЕ лежит на стороне Квадрата1\n";

    cout << endl;

    if (circles_intersect(circle1, circle2))
        cout << "Круг1 и Круг2 пересекаются\n";
    else
        cout << "Круг1 и Круг2 НЕ пересекаются\n";

    if (rectangles_intersect(rectangle1, rectangle2))
        cout << "Квадрат1 и Квадрат2 пересекаются\n";
    else
        cout << "Квадрат1 и Квадрат2 НЕ пересекаются\n";

    if (circle_rectangle_intersect(circle1, rectangle1))
        cout << "Круг1 и Квадрат1 пересекаются\n";
    else
        cout << "Круг1 и Квадрат1 НЕ пересекаются\n";

    cout << endl;

    if (circle_in_circle(circle1, circle2))
        cout << "Круг1 находится внутри Круга2\n";
    else
        cout << "Круг1 НЕ находится внутри Круга2\n";

    if (rectangle_in_rectangle(rectangle1, rectangle2))
        cout << "Квадрат1 находится внутри Квадрата2\n";
    else
        cout << "Квадрат1 НЕ находится внутри Квадрата2\n";

    if (rectangle_in_circle(rectangle1, circle1))
        cout << "Квадрат1 находится внутри Круга1\n";
    else
        cout << "Квадрат1 НЕ находится внутри Круга1\n";

    if (circle_in_rectangle(circle1, rectangle1))
        cout << "Круг1 находится внутри Квадрата1\n";
    else
        cout << "Круг1 НЕ находится внутри Квадрата1\n";

    return 0;
}