var dependencyGraph = {};
var visited = [];
var stack = [];

/**
 * @function Check for cycle using DFS
 * @param {number} vertex u
 * @return {boolean}
 */
var isCyclic = function (u) {
  if (!visited[u]) {
    visited[u] = true;
    stack[u] = true;

    for (let adj of dependencyGraph[u]) {
      if (!visited[adj] && isCyclic(adj)) return true;
      else if (stack[adj]) return true;
    }

    stack[u] = false;
    return false;
  }
};

/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
  // initialization
  for (let i = 0; i < numCourses; i++) {
    dependencyGraph[i] = [];
    visited[i] = false;
    stack[i] = false;
  }

  // building adjacency list
  for (let i = 0; i < prerequisites.length; i++) {
    dependencyGraph[prerequisites[i][0]].push(prerequisites[i][1]);
  }

  // Depth first Traversal
  for (let j in dependencyGraph) {
    if (!visited[j] && isCyclic(j)) return false;
  }

  return true;
};
