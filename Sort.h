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
    // i ����ǰҪ����ѡ�������λ��
    for (int i = 0; i < n; i++) {
        // ���� i �����Ԫ�أ��ҵ���Сֵ���ڵ�λ��
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ����Сֵ�뵱ǰλ�ý���
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void Sort::insertionSort(std::vector<T>& arr)
{
    int n = arr.size();
    // �ӵڶ���Ԫ�ؿ�ʼ����һ������뵽���������������
    for (int i = 1; i < n; i++) {
        T key = arr[i]; // ��¼��ǰ�������Ԫ��
        int j = i - 1; // jָ�����ź��������������һ��Ԫ��
        // ����ƶ��������Ԫ�أ�Ϊ��ǰ�������Ԫ���ҵ�����λ��
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        // ��������Ԫ�ز��뵽����ȷ��λ����
        arr[j + 1] = key;
    }
}
