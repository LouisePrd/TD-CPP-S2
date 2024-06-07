#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const &vec)
{
    return std::is_sorted(vec.begin(), vec.end());
}

// Exercice 1 (tri itératif)
void bubble_sort(std::vector<int> &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        for (unsigned int j = 0; j < vec.size() - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// Exercice 2 (tri récursif)
size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot)
{
    std::swap(vec[pivot], vec[right]);
    int pivotValue = vec[right];
    size_t index = left;

    for (size_t i = left; i < right; i++) {
        if (vec[i] < pivotValue) {
            std::swap(vec[i], vec[index]);
            index++;
        }
    }
    std::swap(vec[index], vec[right]);
    return index;
}

void quick_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left < right) {
        size_t pivot = (left + right) / 2;
        pivot = quick_sort_partition(vec, left, right, pivot);
        if (pivot > 0) {
            quick_sort(vec, left, pivot - 1);
        }
        quick_sort(vec, pivot + 1, right);
    }
}


void quick_sort(std::vector<float> & vec) {
    quick_sort(vec, 0, vec.size() - 1);
}


int main()
{
    // Tri à bulle
    std::vector<int> array{1, 2, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    bubble_sort(array);
    for (unsigned int i = 0; i < array.size(); i++)
    {
        //std::cout << array[i] << ", ";
    }

    // Tri fusion
    std::vector<float> array2{1, 9, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    int size = array2.size();
    quick_sort(array2);
    for (unsigned int i = 0; i < array2.size(); i++)
    {
        std::cout << array2[i] << ", ";
    }

    return 0;
}