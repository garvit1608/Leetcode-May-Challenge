/**
 * Given a non negative integer number num.
 * For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 */

/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function (num) {
  let res = [];
  res[0] = 0;
  for (let i = 1; i <= num; i++) {
    res[i] = res[i >> 1] + (i & 1);
  }

  return res;
};
