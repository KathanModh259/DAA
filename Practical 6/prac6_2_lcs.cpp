#include <iostream>
#include <vector>
using namespace std;

// DP solution for LCS
int LCS(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "Length of LCS: " << LCS(s1, s2) << endl;
    return 0;
}
