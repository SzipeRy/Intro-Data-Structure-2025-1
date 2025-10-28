#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
    int n, m;
    int round = 1;
    std::map<int,int> myCard;
    std::vector<int> enemyCard;
    bool gameStatus = true; 
    // true == game continue, false == game end
    
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        myCard[i] = p;
    }
    std::sort(myCard.begin(), myCard.end());
    
    
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
            auto it = std::upper_bound(myCard.begin(), myCard.end(), p);
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