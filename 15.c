
int kadane(int *A, int ASize)
{
  int maxSoFar = INT_MIN;
  int maxEndingHere = 0;

  for (int i = 0; i < ASize; i++)
  {
    maxEndingHere += A[i];

    if (maxSoFar < maxEndingHere)
    {
      maxSoFar = maxEndingHere;
    }

    if (maxEndingHere < 0)
    {
      maxEndingHere = 0;
    }
  }

  return maxSoFar;
}
int maxSubarraySumCircular(int *A, int ASize)
{

  int maxKadane = kadane(A, ASize);

  int sum = 0;

  for (int i = 0; i < ASize; i++)
  {
    sum += A[i];
    A[i] = -A[i];
  }

  sum = sum + kadane(A, ASize);

  if (sum <= 0)
    return maxKadane;

  return (sum > maxKadane) ? sum : maxKadane;
}