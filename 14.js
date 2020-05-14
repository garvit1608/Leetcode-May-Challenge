/**
 * Initialize your data structure here.
 */
var Trie = function () {
  // this.arr = [];
  this.obj = {};
};

/**
 * Inserts a word into the trie.
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function (word) {
  // this.arr.push(word);
  if (!this.obj[word[0]]) {
    this.obj[word[0]] = [];
  }
  this.obj[word[0]].push(word);
};

/**
 * Returns if the word is in the trie.
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function (word) {
  const arr = this.obj[word[0]] || [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] == word) return true;
  }
  return false;
};

/**
 * Returns if there is any word in the trie that starts with the given prefix.
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function (prefix) {
  const arr = this.obj[prefix[0]] || [];
  for (let i = 0; i < arr.length; i++) {
    if (arr[i].startsWith(prefix)) return true;
  }
  return false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
