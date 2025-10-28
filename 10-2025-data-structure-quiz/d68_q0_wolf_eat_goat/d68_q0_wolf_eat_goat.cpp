#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
    long n, p, d, x;
    std::vector<long> goat;

    std::cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        std::cin >> p;
        goat.push_back(p);
    }
    std::sort(goat.begin(), goat.end());

    std::cin >> d;
    for (int i = 0 ; i < d; i++)
    {
        std::cin >> x;
        std::vector<long>::iterator goatPosition;

        if (x > *(goat.end() - 1))
        {
            std::cout << abs(x - *(goat.end() - 1)) << '\n';
        }
        else if (x < *(goat.begin()))
        {
            std::cout << abs(*goat.begin() - x) << '\n';
        }
        else
        {
            goatPosition = std::lower_bound(goat.begin(), goat.end(), x);
            std::cout << std::min((abs(x - *goatPosition)), abs(*(goatPosition - 1) - x)) << '\n';
        }
    }
}   
