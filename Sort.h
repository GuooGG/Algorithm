#pragma once
#include <iostream>
#include <vector>

class Sort
{
public:
    template<typename T>
    static void bubbleSort(std::vector<T>& arr);
    template<typename T>
    static void selectionSort(std::vector<T>& arr);
    template <typename T>
    static void insertionSort(std::vector<T>& arr);
    template<typename T>
    static void shellSort(std::vector<T>& arr);
    template<typename T>
    static void mergeSort(std::vector<T>& arr,int left,int right);
    template<typename T>
    static void quickSort(std::vector<T>& arr, int left, int right);
private:
    template<typename T>
    static void merge(std::vector<T>& arr, int left, int mid, int right);
    template<typename T>
    static int partition(std::vector<T>& arr, int left, int right);
};

template<typename T>
void Sort::bubbleSort(std::vector<T>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void Sort::selectionSort(std::vector<T>& arr)
{
    int n = arr.size();
    // i 代表当前要进行选择排序的位置
    for (int i = 0; i < n; i++) {
        // 遍历 i 后面的元素，找到最小值所在的位置
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 将最小值与当前位置交换
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void Sort::insertionSort(std::vector<T>& arr)
{
    int n = arr.size();
    // 从第二个元素开始，逐一将其插入到已排序的子数组中
    for (int i = 1; i < n; i++) {
        T key = arr[i]; // 记录当前待插入的元素
        int j = i - 1; // j指向已排好序的子数组的最后一个元素
        // 向后移动已排序的元素，为当前待插入的元素找到插入位置
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将待插入元素插入到其正确的位置上
        arr[j + 1] = key;
    }
}

template<typename T>
void Sort::shellSort(std::vector<T>& arr)
{
    int n = arr.size();
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }
    while (gap) {
        T key(arr[0]);
        for (int i = gap; i < n; i++) {
            key = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > key) {
                arr[j + gap] = arr[j];
                j = j - gap;
            }
            arr[j+gap] = key;
        }
        gap /= 3;
    }
}

template<typename T>
void Sort::mergeSort(std::vector<T>& arr,int left,int right)
{
    if (left < right) {
        int mid = ((right - left) >> 1) + left;
        Sort::mergeSort(arr, left, mid);
        Sort::mergeSort(arr, mid + 1, right);
        Sort::merge(arr, left, mid, right);
    }

}

template<typename T>
inline int Sort::partition(std::vector<T>& arr, int left, int right)
{
    int pivot = left;
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= j && arr[i] <= arr[pivot]) {
            i++;
        }
        while (i <= j && arr[j] >= arr[pivot]) {
            j--;
        }
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[pivot], arr[j]);
    return j;
}

template<typename T>
void quickSort(std::vector<T>& arr, int left, int right)
{
    if (left >= right)
        return;
    int pivotIndex = Sort::partition(arr, left, right);
    Sort::quickSort(arr, left, pivotIndex - 1);
    Sort::quickSort(arr, pivotIndex + 1, right);
}

template<typename T>
void Sort::merge(std::vector<T>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<T> temp(right - left + 1);
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}