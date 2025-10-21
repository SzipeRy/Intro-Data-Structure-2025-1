#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, min, max;
    std::cin >> n;
    std::map<int,int> range;

    for (int i = 1; i <= n; i++)
    {
        std::cin >> min >> max;
        if (i == 1)
        {
            range[min] = max;
            std::cout << i << ' ';
            continue;
        }
        auto it = range.lower_bound(min);
        if (it->first == min)
        {
            continue;
        }
        else if (it->second >= max && max >= it-first)
    }
}