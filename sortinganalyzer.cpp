#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Function to generate a random vector of integers
std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000);

    for (int i = 0; i < size; i++) {
        vec.push_back(dist(gen));
    }

    return vec;
}

// Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

// Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int size = 10000;
    std::vector<int> data = generateRandomVector(size);

    // Measure the time for Bubble Sort
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Bubble Sort Time: " << duration.count() << " seconds" << std::endl;

    // Reset the data
    data = generateRandomVector(size);

    // Measure the time for Insertion Sort
    start = std::chrono::high_resolution_clock::now();
    insertionSort(data);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Insertion Sort Time: " << duration.count() << " seconds" << std::endl;

    // Reset the data
    data = generateRandomVector(size);

    // Measure the time for Selection Sort
    start = std::chrono::high_resolution_clock::now();
    selectionSort(data);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Selection Sort Time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
