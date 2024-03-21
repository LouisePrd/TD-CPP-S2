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
int main()
{
    std::vector<int> array{1, 2, 4, 5, 6, 12, 8, 9, 3, 3, 0};
    bubble_sort(array);
    for (unsigned int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << ", ";
    }

    
    return 0;
}