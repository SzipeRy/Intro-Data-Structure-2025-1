#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    int n, m;
    int x, y;
    bool pairDetect;
    std::cin >> n >> m;

    std::vector<int> a;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        a.push_back(x);
    }
    std::sort(a.begin(), a.end());

    for (int h = 0; h < m; h++)
    {
        pairDetect = false;
        std::cin >> y;
        // must find something + something(v.2) == y
        for (std::vector<int>::iterator i = a.begin(); i < a.end() - 1; i++)
        {
            int first = *i;
            int second = y - first;
            std::vector<int>::iterator tmp = std::find(i+1, a.end(), second);
            if (tmp > i && tmp != a.end())
            {
                std::cout << "YES" << '\n';
                pairDetect = true;
                break;
            }
        }
        if (!pairDetect)
        {
            std::cout << "NO" << '\n';
        }
    }
}