#include <algorithm>
#include <iostream>
#include <vector>

void debugVector(std::vector<long> &v);

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
        if (std::find(goat.begin(), goat.end(), x) != goat.end())
        {
            std::cout << '0' << '\n';
        }   
        else
        {
            goatPosition = std::lower_bound(goat.begin(), goat.end(), x);
            auto right = *goatPosition - x;
            auto left = x - *(goatPosition - 1);
            
            if (left < right)
            {
                std::cout << left << '\n';
            }
            else if (right < left)
            {
                std::cout << right << '\n';
            }
        }
    }
}   

void debugVector(std::vector<long> &v)
{
    for (auto x : v)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}