#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Dynamic_arr {
protected:
    int* data;
    int size;

public:
    Dynamic_arr(int s) {
        if (s <= 0) s = 1;
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = 0;
    }

    Dynamic_arr(const Dynamic_arr& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }

    virtual ~Dynamic_arr() {
        delete[] data;
    }

    int get(int index) {
        if (index < 0 || index >= size) return 0;
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) return;
        if (value < -100 || value > 100) return;
        data[index] = value;
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void add_value(int value) {
        if (value < -100 || value > 100) return;

        int* new_data = new int[size + 1];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];
        new_data[size] = value;

        delete[] data;
        data = new_data;
        size++;
    }

    void add_array(Dynamic_arr& other) {
        int max_size = max(size, other.size);

        for (int i = 0; i < max_size; i++) {
            int a = (i < size ? data[i] : 0);
            int b = (i < other.size ? other.data[i] : 0);
            if (i < size) data[i] = a + b;
        }
    }

    void sub_array(Dynamic_arr& other) {
        int max_size = max(size, other.size);

        for (int i = 0; i < max_size; i++) {
            int a = (i < size ? data[i] : 0);
            int b = (i < other.size ? other.data[i] : 0);
            if (i < size) data[i] = a - b;
        }
    }

    int get_size() {
        return size;
    }

    virtual void save() = 0;
};

string make_filename(const string& ext) {
    time_t now = time(nullptr);
    tm* t = localtime(&now);

    char buffer[64];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", t);

    return string(buffer) + "." + ext;
}

class ArrTxt : public Dynamic_arr {
public:
    ArrTxt(int s) : Dynamic_arr(s) {}

    void save() override {
        string filename = make_filename("txt");
        ofstream out(filename);

        for (int i = 0; i < size; i++) {
            out << data[i] << "\n";
        }

        out.close();
        cout << "Saved TXT file: " << filename << endl;
    }
};

class ArrCSV : public Dynamic_arr {
public:
    ArrCSV(int s) : Dynamic_arr(s) {}

    void save() override {
        string filename = make_filename("csv");
        ofstream out(filename);

        for (int i = 0; i < size; i++) {
            out << data[i];
            if (i != size - 1) out << ",";
        }

        out.close();
        cout << "Saved CSV file: " << filename << endl;
    }
};

int main() {
    Dynamic_arr* arr1 = new ArrTxt(5);
    Dynamic_arr* arr2 = new ArrCSV(5);

    arr1->set(0, 10);
    arr1->set(1, 20);
    arr1->set(2, 30);
    arr1->set(3, 40);
    arr1->set(4, 50);

    arr2->set(0, 5);
    arr2->set(1, 15);
    arr2->set(2, 25);
    arr2->set(3, 35);
    arr2->set(4, 45);

    arr1->print();
    arr2->print();

    arr1->save();
    arr2->save();

    delete arr1;
    delete arr2;
    return 0;
}
