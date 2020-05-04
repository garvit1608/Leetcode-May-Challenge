/**
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 * O(N) solution
 */

class Solution
{
public:
  int findComplement(int num)
  {
    int result = 0;
    int powerOfTwo = 1;

    while (num > 0)
    {
      if (!(num & 1))
      {
        result += powerOfTwo;
      }

      num >>= 1;
      powerOfTwo <<= 1;
    }

    return result;
  }
};