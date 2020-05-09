/**
 * Given a positive integer num, write a function which returns True if num is a perfect square else False.
 */

class Solution
{
public:
  bool isPerfectSquare(int num)
  {

    if (num == 1)
      return true;

    for (long i = 1; i <= num / 2; i++)
    {
      long sq = i * i;

      if (sq > num)
      {
        return false;
      }
      else if (sq == num)
      {
        return true;
      }
    }

    return false;
  }
};