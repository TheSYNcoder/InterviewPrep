/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/


// funtional code

class Solution {
     public boolean isValid(String s) {
         if (s.length() % 2 != 0) return false;
          
          // create a stack to store parentheses.
         Stack<Character> stack = new Stack<>();
         for (int i = 0; i < s.length(); i++) {
             char c = s.charAt(i);
              // push opening parentheses.
             if (c == '(') {
                 stack.push(')');
             } else if (c == '[') {
                 stack.push(']');
             } else if (c == '{') {
                 stack.push('}');
             }
              // check for coressponding closing parentheses if it is not there then return false.
              else if (stack.isEmpty() || stack.pop() != c) return false;
         }
          
          // if the stack is empty that means parentheses are valid.
         return stack.isEmpty();
     }
