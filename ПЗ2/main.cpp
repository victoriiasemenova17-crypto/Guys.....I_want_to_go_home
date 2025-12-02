#include <iostream> 
using namespace std;

class Dynamic_arr {
    int* data;
    int size;
public:
    Dynamic_arr(int s) {
        if (s <= 0) {
            s = 1;
        }
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    Dynamic_arr( Dynamic_arr& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    ~Dynamic_arr() {
        delete[] data;
    }

    int get(int index)  {
        if (index < 0 || index >= size) {
            return 0;
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            return;
        }
        if (value < -100 || value > 100) {
            return;
        }
        data[index] = value;
    }

    void print()  {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void add_value(int value) {
        if (value < -100 || value > 100) {
            return;
        }

        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];
        new_data[size] = value;

        delete[] data;
        data = new_data;
        size++;
    }

    void add_array( Dynamic_arr& other) {
        int max_size;
        if (size > other.size)
            max_size = size;
        else
            max_size = other.size;

        for (int i = 0; i < max_size; i++) {
            int a, b;
            if (i < size)
                a = data[i];
            else
                a = 0;

            if (i < other.size)
                b = other.data[i];
            else
                b = 0;

            if (i < size)
                data[i] = a + b;
        }
    }

    void sub_array( Dynamic_arr& other) {
        int max_size;
        if (size > other.size)
            max_size = size;
        else
            max_size = other.size;

        for (int i = 0; i < max_size; i++) {
            int a, b;
            if (i < size)
                a = data[i];
            else
                a = 0;

            if (i < other.size)
                b = other.data[i];
            else
                b = 0;

            if (i < size)
                data[i] = a - b;
        }
    }

    int get_size()  {
        return size;
    }
};

int main() {
    Dynamic_arr arr1(3);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    cout << "array1: ";
    arr1.print();

    Dynamic_arr arr2 = arr1;
    arr2.add_value(40);
    cout << "array2 + value: ";
    arr2.print();

    arr1.add_array(arr2);
    cout << "array1 + array2: ";
    arr1.print();

    arr1.sub_array(arr2);
    cout << "(array1 + array2) - array2 : ";
    arr1.print();

    return 0;
}
