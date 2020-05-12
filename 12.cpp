/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
 * Note: Your solution should run in O(log n) time and O(1) space.
 */

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {

    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (mid - l == 0)
        return nums[mid];

      if ((mid - l + 1) % 2 == 0)
      {
        if (nums[mid] == nums[mid - 1])
          l = mid + 1;
        else
          r = mid;
      }
      else if (nums[mid] == nums[mid + 1])
        l = mid + 2;
      else
        r = mid;
    }

    return -1;
  }
};