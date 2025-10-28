#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

int main(void)
{
    // std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, m;
    int round = 1;
    std::multiset<int> myCard;
    bool gameStatus = true;
    // true == game continue, false == game end
    
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        myCard.insert(p);
    }
    
    for (int i = 0; i < m; i++)
    {
        // std::cout << "ENEMYHAND" << '\n';
        int enemyHand;
        std::cin >> enemyHand;
        for (int j = 0; j < enemyHand; j++)
        {
            // std::cout << "ENEMYCARD" << '\n';
            int p;
            std::cin >> p;
            auto it = myCard.upper_bound(p);
            // std::cout << it->first << '\n';
            if (it == myCard.end())
            {
                gameStatus = false;
                break;
            }
            else
            {
                myCard.erase(it);
            }
        }
        if (!gameStatus)
        {
            break;
        }
        round++;
    }

    std::cout << round << '\n';
}