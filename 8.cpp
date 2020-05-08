/**
 * You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
 */

class Solution
{
  float getSlope(vector<vector<int>> &coordinates, int first, int second)
  {
    float t = (float)(coordinates[second][1] - coordinates[first][1]) / (coordinates[second][0] - coordinates[first][0]);
    return t;
  }

public:
  bool checkStraightLine(vector<vector<int>> &coordinates)
  {
    if (coordinates.size() == 2)
    {
      return true;
    }

    float slope = getSlope(coordinates, 0, 1);

    for (int i = 1; i < coordinates.size() - 1; i++)
    {
      float s = getSlope(coordinates, i, i + 1);
      if (s != slope)
      {
        return false;
      }
    }

    return true;
  }
};