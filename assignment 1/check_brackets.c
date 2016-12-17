/***************************************************************************
 *
 * Problem: Check brackets in the code
 *
 * Problem Introduction
 * In this problem you will implement a feature for a text editor to find errors
 * in the usage of brackets in the code.
 *
 * Problem Description
 * Task: Your friend is making a text editor for programmers. He is currently
 * working on a feature that will find errors in the usage of different types of
 * brackets. Code can contain any brackets from the set []{}(), where the opening
 * brackets are [,{, and ( and the closing brackets corresponding to them are
 * ],}, and ). For convenience, the text editor should not only inform the user
 * that there is an error in the usage of brackets, but also point to the exact
 * place in the code with the problematic bracket.
 * -First priority is to find the first unmatched closing bracket which either
 * doesn’t have an opening bracket before it, like ] in ](), or closes the wrong
 * opening bracket, like } in ()[}.
 * -If there are no such mistakes, then it should find the first unmatched opening
 * bracket without the corresponding closing bracket after it, like ( in {}([].
 * -If there are no mistakes, text editor should inform the user that the usage of
 * brackets is correct.
 * -Apart from the brackets, code can contain big and small latin letters, digits
 * and punctuation marks.
 * -More formally, all brackets in the code should be divided into pairs of
 * matching brackets, such that in each pair the opening bracket goes before the
 * closing bracket, and for any two pairs of brackets either one of them is nested
 * inside another one as in (foo[bar]) or they are separate as in f(a,b)-g[c].
 * The bracket [ corresponds to the bracket ], { corresponds to }, and (
 * corresponds to ).
 *
 * Input Format
 * Input contains one string S which consists of big and small latin letters,
 * digits, punctuation marks and brackets from the set []{}().
 *
 * Constraints
 * The length of S is at least 1 and at most 10^5.
 *
 * Output Format
 * If the code in S uses brackets correctly, output “Success" (without the quotes).
 * Otherwise, output the 1-based index of the first unmatched closing bracket,
 * and if there are no unmatched closing brackets, output the 1-based index of
 * the first unmatched opening bracket.
 *
*************************************************************************/

#include <stdio.h>
#define MAX_SIZE 10000

struct bracket {
  unsigned int position;
  char type;
};

unsigned short match_c(char type, char c) {
  if ( (type == '[' && c == ']') ||
       (type == '{' && c == '}') ||
       (type == '(' && c == ')') )
      return 1;
  return 0;
}

int main() {
  // Create stack to track opening brackets (max input length = 10^5)
  struct bracket bracket_stack[MAX_SIZE];
  int top_index = -1;
  // Get input string -- e.g. '{{[]}}[]{}' (valid) or '}' (not valid)
  char input[MAX_SIZE];
  if (fgets(input, MAX_SIZE, stdin) != NULL) {
    // For each char
    int i;
    for (i = 0; input[i] != '\n'; i++) {
      char c = input[i];
      // Push to stack if it is an opening bracket, i.e. '(' / '[' / '{'
      if (c == '(' || c == '[' || c == '{') {
        struct bracket *b = &bracket_stack[++top_index];
        b->type = c;
        b->position = i;
      }
      // Else if it is a closing brakets, i.e. ')' / ']' / '}'
      if (c == ')' || c == ']' || c == '}') {
        // VIOLATION if the stack is empty or the top doesn't match: print position
        if (top_index < 0 || !match_c(bracket_stack[top_index].type, c)) {
          printf("%d\n", (i+1));
          return 0;
        // Else it matches: pop the stack
        } else {
          --top_index;// bracket_stack[top_index--] = NULL;
        }
      }
    }
    // If the stack is empty, print "Success"
    if (top_index == -1) {
      printf("Success\n");
    // Else print the position of the last opening bracket pushed
    } else {
      printf("%d\n", (1 + bracket_stack[top_index].position));
    }
  }

  return 0;
}
