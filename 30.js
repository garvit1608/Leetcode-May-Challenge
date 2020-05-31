/**
 * We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
 */

var swap = function (arr, i, j) {
  const temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
};

/**
 * @param {number[][]} points
 * @param {number} K
 * @return {number[][]}
 */
var kClosest = function (points, K) {
  const distance = [];
  const result = [];

  for (const point of points) {
    const d = Math.sqrt(Math.pow(point[0], 2) + Math.pow(point[1], 2));
    distance.push(d);
  }

  for (let i = 0; i < K; i++) {
    let idx = i;
    for (j = i + 1; j < distance.length; j++) {
      if (distance[j] < distance[idx]) idx = j;
    }
    if (i !== idx) {
      swap(distance, i, idx);
      swap(points, i, idx);
    }
    result.push(points[i]);
  }

  return result;
};
