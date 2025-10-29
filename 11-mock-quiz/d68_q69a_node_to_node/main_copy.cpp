#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long long n, k;
    int m;
    std::cin >> n >> k >> m;

    for (int i = 0; i < m; i++)
    {
        std::vector<long long> root1;
        std::stack<long long> root2;

        long long p, q;
        
        std::cin >> p >> q;

        while (p != q)
        {
            
            if (p < q)
            {
                root2.push(q);
                q = (q-1)/k;
            }
            else
            {
                root1.push_back(p);
                p = (p-1)/k;
            }
        }
        root1.push_back(p);
        root2.push(q);

        std::cout << root1.size() + root2.size() - 2 << '\n';
        for (auto it = root1.begin(); it < root1.end() - 1; it++)
        {
            std::cout << *it << " -> ";
        }
        while(root2.size() > 1)
        {
            std::cout << root2.top() << " -> ";
            root2.pop();
        }
        std::cout << root2.top() << '\n';;
    }   
}