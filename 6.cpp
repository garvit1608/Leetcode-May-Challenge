/**
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 */

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> M;

    for (int n : nums)
    {
      M[n]++;
    }

    for (auto i : M)
    {
      if (i.second > nums.size() / 2)
      {
        return i.first;
      }
    }

    return -1;
  }
};