/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var removeKdigits = function (num, k) {
  if (num.length == k) return '0';

  for (let i = 1; i <= k; i++) {
    let j = 0;

    while (j < num.length - 1 && num[j] <= num[j + 1]) j++;

    num = num.replace(num[j], '');

    if (num[0] == 0 && num.length > 1) num = num.replace(num[0], '');
  }

  return num;
};
