#include <iostream>
#include <map>

void debugSpeed(std::map<long, long> &speed);

int main(void)
{
    long n, m, k;
    std::map<long, long> brake;
    std::map<long, long> speed;
    std::map<long, long> speedReverse;
    std::map<long, long> test;
    // n is number of lines about brake pressing
    // m is question with input of a and q
    // a is question, q is answer
    // k is number of times when brake is pressed
    std::cin >> n >> m >> k;
    speed.insert({0, k});

    for (int i = 0; i < n; i++)
    {
        long t, d;
        std::cin >> t >> d;
        brake.insert({t,d});
    }
    // for (auto it : brake)
    // {
    //     test.insert({it.first, it.second});
    // }
    // debugSpeed(test);
    // speedReverse.insert({k, 0});

    long tmpSpeed = k;
    for (auto it : brake)
    {
        if (tmpSpeed > 0)
        {
            tmpSpeed -= it.second;
            if(tmpSpeed < 0)
            {
                tmpSpeed = 0;
            }
            speed.insert({it.first, tmpSpeed});
            speedReverse.insert({tmpSpeed, it.first});
        }
        else if (tmpSpeed <= 0)
        {
            speed.insert({it.first, 0});
            speedReverse.insert({0, it.first});
        }
    }
    speedReverse.insert({k, 0});
    debugSpeed(speed);
    debugSpeed(speedReverse);
    
    long tmpK = k;

    for (int i = 0; i < m; i++)
    {
        int a;
        long q;
        std::cin >> a >> q;
        if (a == 1)
        {
            auto it = speed.lower_bound(q);
            if (q != it->first)
            {
                std::cout << (--it)->second << '\n';
            }
            else if (q == it->first)
            {
                std::cout << it->second << '\n';
            }
            else if (it == speed.end())
            {
                std::cout << '0' << '\n';
            }
        }
        else if (a == 2)
        {
            auto it = speedReverse.lower_bound(q);
            if (q == it->first)
            {
                std::cout << (--it)->second << '\n';
            }
            else if (q < it->first)
            {
                std::cout << (--it)->second << '\n';
            }
            else if (it == speedReverse.end())
            {
                std::cout << (--it)->second << '\n';
            }
        }
    }
}

void debugSpeed(std::map<long, long> &speed)
{
    long tmp = 0;
    for (auto it : speed)
    {
        std::cout << it.first << " : " << it.second << '\n';
        tmp += it.second;
    }
    // std::cout << tmp << '\n';
}