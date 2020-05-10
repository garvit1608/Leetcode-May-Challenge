class Solution
{
public:
  int findJudge(int N, vector<vector<int>> &trust)
  {

    if (N == 1)
      return 1;

    // unordered_map<int, int> firstIndex;
    unordered_map<int, int> secondIndex;

    for (int i = 0; i < trust.size(); i++)
    {
      secondIndex[trust[i][1]]++;
      secondIndex[trust[i][0]]--;
    }

    for (auto i : secondIndex)
    {
      if (i.second == N - 1)
        return i.first;
    }

    return -1;
  }
};