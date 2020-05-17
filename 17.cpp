class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {

    if (s.empty() || p.length() > s.length())
      return {};

    vector<int> count(26, 0);
    vector<int> answer;
    int substringLength = p.length();

    for (char c : p)
    {
      count[c - 'a']++;
    }

    for (int i = 0; i < s.length() - substringLength + 1; i++)
    {
      vector<int> countCopy = count;
      int pLength = substringLength;

      for (int j = 0; j < substringLength; j++)
      {
        if (--countCopy[s[i + j] - 'a'] >= 0)
          pLength--;
        else
          break;
      }

      if (pLength == 0)
        answer.push_back(i);
    }

    return answer;
  }
};