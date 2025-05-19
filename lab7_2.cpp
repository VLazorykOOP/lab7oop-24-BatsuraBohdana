#include <iostream>
#include <cstring> 

using namespace std;

// Шаблонна функція сортування вставками
template<typename T>
void insertionSort(T arr[], int size) {
    for (int i = 1; i < size; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Спеціалізація шаблону для типу const char*
template<>
void insertionSort<const char*>(const char* arr[], int size) {
    for (int i = 1; i < size; ++i) {
        const char* key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {

    int intArr[] = {4, 2, 5, 1, 3};
    int n1 = sizeof(intArr) / sizeof(intArr[0]);
    insertionSort(intArr, n1);
    cout << "Відсортований масив int: ";
    for (int i = 0; i < n1; ++i) cout << intArr[i] << " ";
    cout << endl;

    
    const char* strArr[] = {"pear", "apple", "banana", "orange"};
    int n2 = sizeof(strArr) / sizeof(strArr[0]);
    insertionSort(strArr, n2);
    cout << "Відсортований масив const char*: ";
    for (int i = 0; i < n2; ++i) cout << strArr[i] << " ";
    cout << endl;

    return 0;
}
