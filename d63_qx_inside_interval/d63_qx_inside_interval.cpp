#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    std::vector<std::pair<int,int>> range;
    std::cin >> n >> m;

    for (int i = 0 ; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if (a > b)
        {
            range.push_back({b,a});
        }
        else
        {
            range.push_back({a,b});
        }
    }

    for (int i = 0; i < m; i++)
}