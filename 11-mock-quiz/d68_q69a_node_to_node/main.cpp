#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

int main(void)
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    long long n, k;
    int m;
    std::cin >> n >> k >> m;

    for (int i = 0; i < m; i++)
    {
        std::vector<int> root1;
        std::vector<int> root2;

        long long p, q;
        long h_p, h_q;
        
        std::cin >> p >> q;

        h_p = (long) (log2l(p+1)/log2l(k));
        h_q = (long) (log2l(q+1)/log2l(k));
        while(h_p != h_q)
        {
            if (h_p > h_q)
            {
                root1.push_back(p);
                p = (p-1)/k;
                h_p = (long) (log2l(p+1)/log2l(k));
            }
            else if (h_p < h_q)
            {
                root2.push_back(q);
                q = (q-1)/k;
                h_q = (long) (log2l(q+1)/log2l(k));
            }
        }

        while (p != q)
        {
            root1.push_back(p);
            root2.push_back(q);

            p = (p - 1) / k;
            q = (q - 1) / k;
        }

        root1.push_back(p);
        root2.push_back(q);
            
        std::cout << root1.size() + root2.size() - 2 << '\n';
        for (int i = 0 ;i < root1.size(); i++)
        {
            std::cout << root1[i] << " -> ";
        }
        for (auto i = root2.end() - 2; i > root2.begin(); i--)
        {
            std::cout << *i << " -> ";
        }
        std::cout << *(root2.begin()) << '\n';
    }   
}