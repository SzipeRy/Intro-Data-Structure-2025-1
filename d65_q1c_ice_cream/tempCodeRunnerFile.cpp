#include <iostream>
#include <map>
#include <vector>

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

    std::vector<int> daySaving(100000);
    auto itRate = changeRate.begin();
    int rate = start;
    long saving = 0;

    for (int j = 0; j < 100000; j++)
    {
        if (j == itRate->first)
        {
            rate = itRate->second;
            itRate++;
        }
        saving += rate;   
        daySaving[j] = saving; 
    }

    for (int i = 0; i < m; i++)
    {        
        std::cin >> p >> x;
        
        auto itIce = std::lower_bound(daySaving.begin(), daySaving.end(), p);

        if (itIce - daySaving.begin() <= x)
        {
            std::cout << itIce - daySaving.begin() << ' ';
        }
        else
        {
            p += daySaving[x];
            auto newItIce = std::lower_bound(itIce, daySaving.end(), p);
            std::cout << newItIce - daySaving.begin() << ' ';
        }

    }
}