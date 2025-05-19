#include <iostream>
using namespace std;

template <typename T>
class MyArray {
private:
    T* data;
    int size;

public:
    // Конструктор
    MyArray(int s = 0) : size(s) {
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = T(); // ініціалізація типу за замовчуванням
    }

    // Конструктор копіювання
    MyArray(const MyArray& other) {
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    // Деструктор
    ~MyArray() {
        delete[] data;
    }

    // Оператор =
    MyArray& operator=(const MyArray& other) {
        if (this == &other) return *this; // захист від самоприсвоєння
        delete[] data;
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
        return *this;
    }

    // Оператор []
    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("Індекс поза межами!");
        return data[index];
    }

    // Оператор +
    MyArray operator+(const MyArray& other) const {
        if (size != other.size)
            throw logic_error("Різні розміри масивів!");

        MyArray result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] + other.data[i];
        return result;
    }

    // Оператор +=
    MyArray& operator+=(const MyArray& other) {
        if (size != other.size)
            throw logic_error("Різні розміри масивів!");

        for (int i = 0; i < size; ++i)
            data[i] += other.data[i];
        return *this;
    }

    // Оператор -
    MyArray operator-(const MyArray& other) const {
        if (size != other.size)
            throw logic_error("Різні розміри масивів!");

        MyArray result(size);
        for (int i = 0; i < size; ++i)
            result.data[i] = data[i] - other.data[i];
        return result;
    }

    // Оператор -=
    MyArray& operator-=(const MyArray& other) {
        if (size != other.size)
            throw logic_error("Різні розміри масивів!");

        for (int i = 0; i < size; ++i)
            data[i] -= other.data[i];
        return *this;
    }

    // Виведення масиву
    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    // Метод для заповнення випадковими значеннями
    void fillRandom(int min = 0, int max = 100) {
        for (int i = 0; i < size; ++i)
            data[i] = min + rand() % (max - min + 1);
    }
};

// ======================
// Демонстрація
int main() {
    srand(time(0));

    MyArray<int> arr1(5), arr2(5);
    arr1.fillRandom(1, 10);
    arr2.fillRandom(1, 10);

    cout << "arr1: "; arr1.print();
    cout << "arr2: "; arr2.print();

    MyArray<int> sum = arr1 + arr2;
    cout << "arr1 + arr2: "; sum.print();

    arr1 += arr2;
    cout << "arr1 після += arr2: "; arr1.print();

    MyArray<int> diff = arr1 - arr2;
    cout << "arr1 - arr2: "; diff.print();

    arr1 -= arr2;
    cout << "arr1 після -= arr2: "; arr1.print();

    return 0;
}
