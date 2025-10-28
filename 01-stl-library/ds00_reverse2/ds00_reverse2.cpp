#include <iostream>
#include <vector>

void reverse(std::vector<int> &v, std::vector<int>::iterator a, std::vector<int>::iterator b)
{
    std::vector<int> tmp;
    for (auto x = v.begin(); x < a; x++)
    {
        tmp.push_back(*x);
    }
    for (auto x = b - 1; x >= a; x--)
    {
        tmp.push_back(*x);
    }
    for (auto x = b; x < v.end(); x++)
    {
        tmp.push_back(*x);
    }
    v = tmp;
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