#include <iostream>
#include "priority_queue.h"

int main(void)
{
    int n, m;
    CP::priority_queue<int> pq;

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        pq.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        
        size_t out;
        out = pq.count_common_ancestors(a, b);
        std::cout << out << '\n';
    }
}