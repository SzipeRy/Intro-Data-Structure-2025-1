#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    std::map<int, int> range;
    std::cin >> n >> m;
    
    for (int i = 0 ; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        range[a] = b;
    }
    
    // for (auto x : range)
    // {
    //     std::cout << '[' << x.first << ' ' << x.second << ']';
    // }

    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        bool found = false;

        auto it = range.lower_bound(x);
        if (it->first == x)
        {
            std::cout << 1 << ' ';
            continue;
        }
        if (it == range.end())
        {
            it--;
        }
        else if (it->first > x)
        {
            it--;
        }

        if (it->first <= x && x <= it->second)
        {
            std::cout << 1 << ' ';
            continue;
        }
        std::cout << 0 << ' ';
    }
}