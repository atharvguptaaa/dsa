#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
    vector<vector<int>> ans(m, vector<int>(n));
    if (m * n != original.size()) return {};
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = original[i * n + j];
        }
    }
    return ans;
}

int main()
{
    vector<int> original = {1, 2, 3, 4, 5, 6};
    int m = 3, n = 2;
    vector<vector<int>> ans = construct2DArray(original, m, n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}