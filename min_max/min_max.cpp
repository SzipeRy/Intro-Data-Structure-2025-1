#include <iostream>

using namespace std;

int main(void)
{
    // n is row
    // m is column
    // r is number of interest area 
    int n,m,r;
    cin >> n >> m;
    cin >> r;

    // matrix input
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int value;
            cin >> value;
            matrix[i][j] = value;
        }
    }

    // r input
    int r1, c1, r2, c2;
    for (int i = 0; i < r; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        // Invalid matrix selection
        if (r2 < r1 || c2 < c1)
        {
            cout << "INVALID" << endl;
            continue;
        }
        // Outside matrix selection
        if (r1 > n || c1 > m)
        {
            cout << "OUTSIDE" << endl;
            continue;
        }
        // Outside matrix fix
        if (r2 > n)
        {
            r2 = n;
        }
        if (c2 > m)
        {
            c2 = m;
        }
        // fix the r1, c1, r2, c2 value by -1 to match the index
        r1--;
        r2--;
        c1--;
        c2--;
        int max;
        for (int row = r1; row <= r2; row++)
        {
            for (int col = c1; col <= c2; col++)
            {
                if (row == r1 && col == c1)
                {
                    max = matrix[row][col];
                    continue;
                }
                if (matrix[row][col] > max)
                {
                    max = matrix[row][col];
                }
            }
        }
        cout << max << endl;
    }
    
}