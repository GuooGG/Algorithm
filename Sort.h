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
