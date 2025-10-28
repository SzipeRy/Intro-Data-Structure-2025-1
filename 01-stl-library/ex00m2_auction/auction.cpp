#include <iostream>
#include <vector>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, a;

    std::vector<int> item;
    char action;

    std::cin >> n >> m >> a;
    for (int i = 0; i < n; i++)
    {
        int amount;
        std::cin >> amount;
        item.push_back(amount);
    }

    for (int j = 0; j < a; j++)
    {
        int u, i, v;
        std::cin >> action;
        if (action == 'B')
        {
            for (int g = 0; g < 3; g++)
            {
                std::cin >> u >> i >> v;

            }
        }
        else if (action == 'W')
        {
            for (int g = 0; g < 2; g++)
            {
                std::cin >> u >> i;

            }
        }
    }
    return 0;
}