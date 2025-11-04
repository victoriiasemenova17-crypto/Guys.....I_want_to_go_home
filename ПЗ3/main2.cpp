#include <iostream>
#include <algorithm> 
using namespace std;

class Dynamic_arr {
protected:
    int* data;
    int size;
public:
    Dynamic_arr(int s) {
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

    int get(int index) const {
        if (index < 0 || index >= size)
            return 0;
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size)
            return;
        if (value < -100 || value > 100)
            return;
        data[index] = value;
    }

    void print() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void add_value(int value) {
        if (value < -100 || value > 100)
            return;

        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];
        new_data[size] = value;

        delete[] data;
        data = new_data;
        size++;
    }

    int get_size() const {
        return size;
    }
};

class Advanced_arr : public Dynamic_arr {
public:
    Advanced_arr(int s) : Dynamic_arr(s) {}
    Advanced_arr(const Dynamic_arr& other) : Dynamic_arr(other) {}

    double average() const {
        if (size == 0) return 0;
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return static_cast<double>(sum) / size;
    }

    double median() const {
        if (size == 0) return 0;
        int* temp = new int[size];
        for (int i = 0; i < size; i++)
            temp[i] = data[i];
        sort(temp, temp + size);

        double med;
        if (size % 2 == 0)
            med = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
        else
            med = temp[size / 2];

        delete[] temp;
        return med;
    }

    int min_value() const {
        if (size == 0) return 0;
        int minVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] < minVal)
                minVal = data[i];
        return minVal;
    }

    int max_value() const {
        if (size == 0) return 0;
        int maxVal = data[0];
        for (int i = 1; i < size; i++)
            if (data[i] > maxVal)
                maxVal = data[i];
        return maxVal;
    }
};

int main() {
    Advanced_arr arr(5);
    arr.set(0, 32);
    arr.set(1, 52);
    arr.set(2, 37);
    arr.set(3, 7);
    arr.set(4, 9);

    cout << "Array: ";
    arr.print();

    cout << "Average value: " << arr.average() << endl;
    cout << "Median: " << arr.median() << endl;
    cout << "Minimum: " << arr.min_value() << endl;
    cout << "Maximum: " << arr.max_value() << endl;

    return 0;
}
