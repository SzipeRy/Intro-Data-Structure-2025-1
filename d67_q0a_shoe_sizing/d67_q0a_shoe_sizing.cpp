#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    long n, m;
    long s, p;
    std::vector<long> shoeSize;
    std::cin >> n >> m;

    for (long i = 0; i < n; i++)
    {
        std::cin >> s;
        shoeSize.push_back(s);
    }
    std::sort(shoeSize.begin(), shoeSize.end());
    long min_size = *shoeSize.begin();

    for (long i = 0; i < m; i++)
    {
        std::cin >> p;
        auto it = std::lower_bound(shoeSize.begin(), shoeSize.end(), p);
        if (it == shoeSize.end())
        {
            std::cout << *(shoeSize.end()-1) << ' ';
        }
        else if (p < min_size)
        {
            std::cout << min_size << ' ';
        }
        else if (p == *it)
        {
            std::cout << p << ' ';
        }
        else
        {
            long right = abs(*it - p);
            long left = abs(p - *(it-1));

            if (right > left)
            {
                std::cout << *(it-1) << ' ';
            }
            else if (left > right)
            {
                std::cout << *it << ' ';
            }
            else
            {
                std::cout << *it << ' ';
            }
        }
    }

    return 0;
}