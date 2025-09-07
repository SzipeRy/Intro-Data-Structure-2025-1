#include <iostream>
#include <vector>

void multiple_add(std::vector<int> &v, int value, int position, int count);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, value, position, count;
    std::cin >> n >> value >> position >> count;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++)
    {
        std::cin >> v[i];
    }

    multiple_add(v, value, position, count);

    std::cout << "After call multiple_add" << '\n' << "Size = " << v.size() << '\n';
    for (auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

void multiple_add(std::vector<int> &v, int value, int position, int count)
{
    v.insert(v.begin() + position, count, value);
}