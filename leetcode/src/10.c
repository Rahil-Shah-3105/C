#include <stdio.h>
/*
Prompt:

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
- '.' Matches any single character.
- '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.

It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

bool isMatch(char* s, char* p);
bool matchStar(char ch, char* s, char* p);

/*
Uses Rob pikes Regexp matcher - https://www.cs.princeton.edu/courses/archive/spr09/cos333/beautiful.html
Implementation:
    // match: search for regexp anywhere in text 
    int match(char *regexp, char *text)
    {
        if (regexp[0] == '^')
            return matchhere(regexp+1, text);
        do {  
            if (matchhere(regexp, text))
                return 1;
        } while (*text++ != '\0');
		fprintf(stderr, "<<< Exiting match(regexp=%s,text=%s)\n", regexp, text);
        return 0;
    }
*/

bool matchStar(char ch, char* s, char* p) {
fprintf(stderr, ">>> Entering matchStar(ch=%c,s=%s,p=%s)\n", ch, s, p);
  do {
    if (isMatch(s, p))
      return true;
  } while (*s != '\0' && (*s++ == ch || ch == '.'));

fprintf(stderr, "<<< Exiting matchStar(ch=%c,s=%s,p=%s)\n", ch, s, p);
  return false;
}

bool isMatch(char* s, char* p) {
fprintf(stderr, ">>> Entering isMatch(s=%s,p=%s)\n", s, p);
  if (*p == '\0')
    return *s == '\0';

  if (p[1] == '*')
    return matchStar(p[0], s, p + 2);

  if (*s != '\0' && (p[0] == '.' || *p == *s)) {
fprintf(stderr, "<<< Exiting isMatch(s=%s,p=%s)\n", s, p);
    return isMatch(s + 1, p + 1);
  }

  return false;
}
