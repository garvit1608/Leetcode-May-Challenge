/**
 * Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
 * Each letter in the magazine string can only be used once in your ransom note.
 */

#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
  bool canConstruct(string ransomNote, string magazine)
  {
    // O(m) solution, m is length of magazine
    unordered_map<char, int> M;
    bool is_possible = true;

    for (int i = 0; i < magazine.length(); i++)
    {
      M[magazine[i]]++;
    }

    for (int i = 0; i < ransomNote.length(); i++)
    {
      if (M[ransomNote[i]] > 0)
      {
        M[ransomNote[i]]--;
      }
      else
      {
        return false;
      }
    }

    return is_possible;
  }
};