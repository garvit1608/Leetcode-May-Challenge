class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int dp[rows][cols];
    int result = 0;

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = matrix[i][j];
        else if (matrix[i][j])
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        else
          dp[i][j] = 0;
        result += dp[i][j];
      }
    }
    return result;
  }
};