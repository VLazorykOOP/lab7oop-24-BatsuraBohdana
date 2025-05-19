#include <iostream>
#include <cstring> 

using namespace std;

// === Шаблон функції послідовного пошуку ===
template <typename T>
int linearSearchLast(T arr[], int size, T key) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            index = i;
        }
    }
    return index;
}

// === Спеціалізація шаблону для char* ===
template <>
int linearSearchLast<char*>(char* arr[], int size, char* key) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (strcmp(arr[i], key) == 0) {
            index = i;
        }
    }
    return index;
}

int main() {
    int arr1[] = {1, 3, 5, 3, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int key1 = 3;
    cout << "Останній індекс (int): " << linearSearchLast(arr1, size1, key1) << endl;

    char* arr2[] = { (char*)"apple", (char*)"banana", (char*)"apple", (char*)"cherry" };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    char key2[] = "apple";
    cout << "Останній індекс (char*): " << linearSearchLast(arr2, size2, key2) << endl;

    return 0;
}
