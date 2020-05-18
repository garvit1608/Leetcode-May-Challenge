class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    if (s1.empty())
      return true;

    if ((!s1.empty() && s2.empty()) || (s1.length() > s2.length()))
      return false;

    vector<int> s1map(26, 0);
    vector<int> s2map(26, 0);

    for (int i = 0; i < s1.length(); i++) //O(S1)
    {
      s1map[s1[i] - 'a']++;
      s2map[s2[i] - 'a']++; //setting initial sliding window
    }

    for (int i = 0; i < s2.length() - s1.length(); i++) //O(S2-S1)
    {
      if (compare(s1map, s2map)) // 26 * O(S2-S1)
        return true;

      s2map[s2[i] - 'a']--;
      s2map[s2[i + s1.length()] - 'a']++;
    }

    return compare(s1map, s2map);
  }

private:
  bool compare(vector<int> &v1, vector<int> &v2)
  {
    for (int i = 0; i < 26; i++)
    {
      if (v1[i] != v2[i])
        return false;
    }

    return true;
  }
};