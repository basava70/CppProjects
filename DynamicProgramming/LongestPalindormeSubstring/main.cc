#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
private:
  int findPalindrome(std::string s, int left, int right)
  {
    while (left >= 0 && right < s.length() && left <= right &&
           s[left] == s[right])
    {
      left--;
      right++;
    }

    int current_length = right - left - 1;
    return current_length;
  }

public:
  int longestPalindromSubstring(std::string s)
  {
    int max_index = 0;
    int max_length = 0;
    int odd_length, even_length;
    int current_length = 0;
    int correction = 0;

    for (int i = 0; i < s.length(); i++)
    {
      odd_length = findPalindrome(s, i, i);
      correction = 0;
      if (odd_length == 1)
      {
        even_length = findPalindrome(s, i, i + 1);
        if (even_length > 0)
          correction = 1;
      }
      current_length = std::max(odd_length, even_length);
      if (current_length >= max_length)
      {
        max_length = current_length;
        max_index = (max_length % 2 == 0 ? (i + 1 - max_length / 2) : (i - max_length / 2));
      }
    }
    std::cout << "Longest palindrome substring is " << s.substr(max_index, max_length) << std::endl;
    return max_length;
  }
};

int main()
{
  Solution solution;
  int answer;
  answer = solution.longestPalindromSubstring("babad");
  std::cout << "solution for babad " << answer << std::endl;
  answer = solution.longestPalindromSubstring("cbbd");
  std::cout << "solution for cbbd " << answer << std::endl;
  answer = solution.longestPalindromSubstring("racecar");
  std::cout << "solution for racecar " << answer << std::endl;
  answer = solution.longestPalindromSubstring("axxxyyxxxab");
  std::cout << "solution for axxxyyxxxab " << answer << std::endl;

  return 0;
}
