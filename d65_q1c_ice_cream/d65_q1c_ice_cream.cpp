#include <iostream>
#include <map>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);

    int n, m, start, a, s, x;
    unsigned long day;
    unsigned long p;
    std::map<int, int> changeRate;

    // n = day when Ajarn Dae change amount of saving
    // m = question (output)
    // start = initial amount of saving
    std::cin >> n >> m >> start;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> s;
        changeRate.insert({a,s});
    }

    for (int i = 0; i < m; i++)
    {
        int rate = start;
        day = 0;
        auto itRate = changeRate.begin();
        long saving = start;
        bool iceCream = false;

        std::cin >> p >> x;

        while (!iceCream)
        // for (int j = 0; j < 10; j++)
        {
            if (saving >= p)
            {
                std::cout << day << ' ';
                iceCream = true;
                break;
            }
            day++;
            if (day == itRate->first && itRate != changeRate.end())
            {
                rate = itRate->second;
                itRate++;
            }
            saving += rate;
            if (saving >= p)
            {
                std::cout << day-- << ' ';
                iceCream = true;
            }
            
            if (day == x)
            {
                saving = 0;
            }
            
        }


    }
}