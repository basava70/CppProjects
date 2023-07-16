/**
 * Copyright Seshadri 2023
 * Longest substring without repeating of a given string
 * Written on July 15
 *
 **/

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class Solution
{
public:
  int longest_substring(std::string s)
  {
    int current_length = 0, max_length = 0;
    int window_left = 0;
    std::vector<int> frequency(26);
    for (int i = 0; i < s.size(); i++)
    {
      frequency[s[i] - 'a']++;
      if (frequency[s[i] - 'a'] != 2)
      {
        current_length++;
        max_length = std::max(max_length, current_length);
      }
      else
      {
        while (frequency[s[i] - 'a'] != 1)
        {
          frequency[s[window_left] - 'a']--;
          window_left++;
        }
        current_length = i - window_left;
      }
    }
    return max_length;
  }
};

int main()
{
  Solution solution;
  int answer = solution.longest_substring("bbbbb");
  std::cout << "length of longest substring for bbbbb " << answer << std::endl;
  answer = solution.longest_substring("abcabcbb");
  std::cout << "length of longest substring for abcabcbb " << answer << std::endl;
  answer = solution.longest_substring("pwwkew");
  std::cout << "length of longest substring for pwwkew " << answer << std::endl;
  return 0;
}
