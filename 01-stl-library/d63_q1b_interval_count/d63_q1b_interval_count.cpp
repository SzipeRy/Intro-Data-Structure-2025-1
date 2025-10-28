#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m, k;
    std::vector<int> range;

    std::cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        range.push_back(x);
    }
    std::sort(range.begin(), range.end());

    for (int i = 0; i < m; i++)
    {
        int center;
        int count = 0;
        std::cin >> center;
        int left = center - k;
        int right = center + k;

        auto itLeft = std::lower_bound(range.begin(), range.end(), left);
        auto itRight = std::lower_bound(range.begin(), range.end(), right);
        
        if (itLeft == range.end())
        {
            std::cout << 0 << ' ';
            continue;
        }
        if (itRight == range.end())
        {
            itRight--;
        }
        if (*itLeft > right)
        {
            std::cout << 0 << ' ';
            continue;
        }

        if (*itRight > right)
        {
            itRight--;
        }
        if (*itRight < left)
        {
            std::cout << 0 << ' ';
            continue;
        }
        if (itRight == range.end())
        {
            std::cout << 0 << ' ';
            continue;
        }
        
        for (auto it = itLeft; it < itRight; it++)
        {
            count++;
        }
        count++;
        std::cout << count << ' ';
    }
}