#include <structs.h>
#include <func.h>

int main() {
    setlocale(LC_ALL, "Russian");

    Point point;
    Circle circle;
    Rectangle rectangle;

    double x_p, y_p, x_c, y_c, x_r, y_r, radius_c, side_r;

    cout << "Введите координаты точки(x y): ";
    cin >> x_p >> y_p;

    cout << "Введите координаты центра круга(x y): ";
    cin >> x_c >> y_c;

    cout << "Введите координаты левого верхнего угла квадрата(x y): ";
    cin >> x_r >> y_r;

    cout << "Введите радиус круга: ";
    cin >> radius_c;

    cout << "Введите длину стороны квадрата: ";
    cin >> side_r;

    point.set_point(x_p, y_p);
    cout << "Точка:" << endl;
    point.get_point();
    cout << endl;

    circle.set_circle(x_c, y_c, radius_c);
    cout << "Круг:" << endl;
    circle.get_circle();
    cout << "Длина окружности: " << circle.len_circle() << endl;
    cout << "Площадь круга: " << circle.square_circle() << endl;
    cout << endl;

    rectangle.set_rectangle(x_r, y_r, side_r);
    cout << "Квадрат:" << endl;
    rectangle.get_rectangle();

    cout << "Периметр квадрата: " << rectangle.len_rectangle() << endl;
    cout << "Площадь квадрата: " << rectangle.square_rectangle() << endl;

    return 0;
}
