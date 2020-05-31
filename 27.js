/**
 * Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
 * Each person may dislike some other people, and they should not go into the same group.
 * Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
 * Return true if and only if it is possible to split everyone into two groups in this way.
 */

/**
 * @param {number} N
 * @param {number[][]} dislikes
 * @return {boolean}
 */
var possibleBipartition = function (N, dislikes) {
  if (!dislikes.length) return true;

  let Graph = {};
  let group = [];
  let q = [];

  for (let i = 1; i <= N; i++) {
    Graph[i] = [];
  }

  // creating adjacency list
  for (let i = 0; i < dislikes.length; i++) {
    Graph[dislikes[i][0]].push(dislikes[i][1]);
    Graph[dislikes[i][1]].push(dislikes[i][0]);
  }

  // dividing people in group 1 and group 2
  for (let i = 1; i <= N; i++) {
    if (!group[i]) {
      group[i] = 1;
      q.push(i);

      while (q.length) {
        const u = q.shift();
        let arr = Graph[u];
        if (!arr) console.log(u, Graph[u]);

        for (let j of Graph[u]) {
          if (!group[j]) {
            if (group[u] === 1) group[j] = 2;
            else group[j] = 1;

            q.push(j);
          } else if (group[u] === group[j]) {
            return false;
          }
        }
      }
    }
  }

  return true;
};
