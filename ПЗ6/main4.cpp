#include <iostream>
#include <stdexcept>
using namespace std;

class Dynamic_arr {
    int* data;
    int size;

public:
    Dynamic_arr(int s) {
        if (s <= 0) s = 1;
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    Dynamic_arr(const Dynamic_arr& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Dynamic_arr() {
        delete[] data;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Error: index is out of range");
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("Error: index is out of range");
        }
        if (value < -100 || value > 100) {
            throw invalid_argument("Error: value must be between -100 and 100");
        }
        data[index] = value;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void add_value(int value) {
        if (value < -100 || value > 100) {
            throw invalid_argument("Error: value must be between -100 and 100");
        }

        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];
        new_data[size] = value;

        delete[] data;
        data = new_data;
        size++;
    }

    int get_size() {
        return size;
    }
};
int main() {
    Dynamic_arr arr(3);

    try {
        arr.set(0, 50);
        arr.set(1, -200);
        arr.set(5, 10);
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    try {
        cout << arr.get(2) << endl;
        cout << arr.get(10) << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    arr.print();
    return 0;
}
