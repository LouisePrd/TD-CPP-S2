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
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

int main()
{
    // Tri à bulle
    std::vector<int> array{1, 2, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    bubble_sort(array);
    for (unsigned int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ", ";
    }

    // Tri fusion
    std::vector<int> array2{1, 2, 4, 5, 6, 12, 8, 9, 3, 3, 0};

    return 0;
}