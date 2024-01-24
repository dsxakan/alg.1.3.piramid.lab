#include <iostream>
#include <vector>

using namespace std;

// Процедура "просеивания" для пирамидальной сортировки
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Пирамидальная сортировка
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Строим первоначальную пирамиду
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Извлекаем элементы из пирамиды по одному
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // Исходный массив
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }

    // Применяем пирамидальную сортировку
    heapSort(arr);

    // Выводим отсортированный массив
    cout << "\nОтсортированный массив (по возрастанию): ";
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
