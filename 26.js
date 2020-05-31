// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxLength = function (nums) {
  let sum = 0;
  let maxLen = 0;
  let history = {};

  for (let i = 0; i < nums.length; i++) {
    if (!nums[i]) sum--;
    else sum++;

    if (sum === 0) maxLen = i + 1;

    if (history.hasOwnProperty(sum))
      maxLen = Math.max(maxLen, i - history[sum]);
    else history[sum] = i;
  }
  return maxLen;
};
