#include <vector>
#include <algorithm>
// #include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back(A[i]);
    }
    for (int i = 0; i < B.size(); i++)
    {
        if (std::find(v.begin(), v.end(), B[i]) != v.end())
        {
            v.push_back(B[i]);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    for (int i = 0; i < A.size(); i++)
    {
        if (std::find(B.begin(), B.end(), A[i]))
        {
            v.push_back(A[i]);
        }
    }
    return v;
}
