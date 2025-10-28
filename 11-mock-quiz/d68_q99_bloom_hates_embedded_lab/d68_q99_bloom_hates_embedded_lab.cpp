#include <algorithm>
#include <iostream>
#include <vector>

void debug(std::vector<unsigned long long> &x);

int main(void)
{
    // n is mainboard component
    // m is how many times nigga bloom smash the board
    // q is how many question jarn Yam about to cook nigga bloom
    
    unsigned long long n, m, q;
    std::vector<unsigned long long> component;
    std::cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
    {
        component.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        unsigned long long centerBloom, forceBloom;
        std::cin >> centerBloom >> forceBloom;

        centerBloom--;
        // change vector value
        component[centerBloom] = 0;
        for (int j = 1; j <= forceBloom; j++)
        {
            if (centerBloom + j < component.size())
            {
                component[centerBloom + j] = 0;
            }
            if (centerBloom - j > 0)
            {
                component[centerBloom - j] = 0;
            }
        }
        // debug(component);
    }

    for (int i = 0; i < q; i++)
    {  
        unsigned long long left, right;
        unsigned long long out = 0;
        std::cin >> left >> right;
        for (auto j = component.begin() + left - 1; j < component.begin() + right; j++)
        {
            if (*j != 0)
            {
                out++;
            }
        }
        std::cout << out << '\n';
    }
}

void debug(std::vector<unsigned long long> &x)
{
    for (auto y : x)
    {
        std::cout << y << ' ';
    }
    std::cout << '\n';
}