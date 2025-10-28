#include <iostream>
#include <vector>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, q;
    int left, right;
    
    std::cin >> n >> q;
    std::vector<int> town(n);
    

    for (int i = 0; i < q; i++)
    {
        std::cin >> left >> right;
        for (int j = left - 1; j < right; j++)
        {
            town[j] = 12345;
        }

        int out = 0;
        for (int j = 0; j < town.size(); j++)
        {
            if (town[j] != 12345)
            {
                out++;
            }
        }
        std::cout << out << '\n';
    }


}