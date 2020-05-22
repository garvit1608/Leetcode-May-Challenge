class Solution
{
public:
  string frequencySort(string s)
  {
    int count[256] = {0};
    string result = "";

    for (int c : s)
    {
      count[c]++;
    }

    vector<pair<int, char>> v;

    for (int i = 0; i < 256; i++)
    {
      if (count[i])
        v.push_back({count[i], i});
    }

    sort(v.begin(), v.end(), greater<pair<int, char>>());

    for (auto i : v)
    {
      result += string(i.first, i.second);
    }

    return result;
  }
};