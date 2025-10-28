#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main(void)
{
    long n, m;
    long s, p;
    std::set<long> shoeSize;
    std::vector<long> out;
    std::cin >> n >> m;

    for (long i = 0; i < n; i++)
    {
        std::cin >> s;
        shoeSize.insert(s);
    }
    long max_size = *std::max_element(shoeSize.begin(), shoeSize.end());

    for (long i = 0; i < m; i++)
    {
        std::cin >> p;
        
        if (p > max_size)
        {
            out.push_back(max_size);
        }
        else
        {
            auto it = shoeSize.lower_bound(p);
            out.push_back(*it);
        }
    }

    for (auto x : out)
    {
        std::cout << x << ' ';
    }
    return 0;
}