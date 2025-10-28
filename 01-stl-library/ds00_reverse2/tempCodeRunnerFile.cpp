#include <iostream>
#include <algorithm>
#include <vector>

void debug(std::vector<int> &v);

void reverse(std::vector<int> &v, std::vector<int>::iterator a, std::vector<int>::iterator b)
{
    auto stop = b;
    for (auto x = stop - 1; x >= a; x--)
    {
        v.push_back(*x);
    }
    for (auto x = stop; x < v.end(); x++)
    {
        v.push_back(*x);
    }
    for (auto x = a; x < stop; x++)
    {
        v.erase(a);
    }
    
}

int main(void)
{
    int n, a, b;
    std::cin >> n;
    std::vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        v.push_back(c);
    }
    
    std::cin >> a >> b;
    reverse(v, v.begin()+a, v.begin()+b+1);

    for (auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

void debug(std::vector<int> &v)
{
    for (auto &x : v)
    {
        std::cout << x << '\n';
    }
}