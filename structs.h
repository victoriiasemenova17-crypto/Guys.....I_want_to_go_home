#include <iostream>
#include <cmath>
#pragma once
using namespace std;

extern const double PI;

struct Point {
    double x;
    double y;

    void set_point(double x_p, double y_p) {
        x = x_p;
        y = y_p;
    }

    void get_point() {
        cout << "x точки: " << x << endl;
        cout << "y точки: " << y << endl;
    }
};

struct Circle {
    Point centre;
    double radius;

    void set_circle(double x_c, double y_c, double radius_c) {
        centre.set_point(x_c, y_c);
        radius = radius_c;
    }

    void get_circle() {
        cout << "центр круга: (" << centre.x << ", " << centre.y << ")" << endl;
        cout << "радиус круга: " << radius << endl;
    }

    double len_circle() {
        return 2 * PI * radius;
    }

    double square_circle() {
        return PI * radius * radius;
    }
};
struct Rectangle {
    Point up_left_corner;
    double side;

    void set_rectangle(double x_r, double y_r, double side_r) {
        up_left_corner.set_point(x_r, y_r);
        side = side_r;
    }

    void get_rectangle() {
        cout << "левый верхний угол квадрата: (" << up_left_corner.x << ", " << up_left_corner.y << ")" << endl;
        cout << "длина стороны квадрата: " << side << endl;
    }

    double len_rectangle() {
        return 4 * side;
    }

    double square_rectangle() {
        return side * side;
    }
};