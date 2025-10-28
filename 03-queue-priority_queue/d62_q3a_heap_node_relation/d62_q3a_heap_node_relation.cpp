#include <iostream>
#include <algorithm>

void check(int parent);

int n, m;
int child;
bool relation;

int main(void)
{
    std::cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;

        relation = false;
        
        if (a == b)
        {
            std::cout << "a and b are the same node" << '\n';
            continue;
        }
        if (a > b)
        {
            child = a;
            check((2 * b) + 1);
            if (!relation)
            {
                check((2 * b) + 2);
            }
            if (relation)
            {
                std::cout << "b is an ancestor of a" << '\n';
                continue;
            }
        }
        else
        {
            child = b;
            check((2 * a) + 1);
            if (!relation)
            {
                check((2 * a) + 2);
            }
            if (relation)
            {
                std::cout << "a is an ancestor of b" << '\n';
                continue;
            } 
        }
        std::cout << "a and b are not related" << '\n';
    }
}

void check(int parent)
{
    if (parent == child)
    {
        relation = true;
        return;
    }

    if (parent >= n)
    {
        return;
    }

    check((2 * parent) + 1);
    if (relation)
    {
        return;
    }

    check((2 * parent) + 2);
    if (relation)
    {
        return;
    }
}
