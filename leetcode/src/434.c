#include "stdio.h"
// Given a string s, returns the number of segments in the string.
int countSegments(char * s){
	fprintf(stderr, "[ERROR] >>> Entering countSegments(s=%s)\n", s);
    int sLen = strlen(s);
    int prevSpace = 1;
	fprintf(stderr, "[ERROR] countSegments(s=%s): prevSpace → %d\n", s, prevSpace);
    int result = 0;
	fprintf(stderr, "[ERROR] countSegments(s=%s): result → %d\n", s, result);
	fprintf(stderr, "[ERROR] countSegments(s=%s): sLen → %d\n", s, sLen);
    char currChar;

    for (int i = 0; i < sLen; i++){
        currChar = s[i];
		fprintf(stderr, "[DEBUG] countSegments(s=%s): currChar → %c\n", s, currChar);

        //A string of whitespaces will only be counted once as the condition below is only true when we transition from whitespace to non-whitespace.
        //Since we start with assumed whitespace (prevSpace = 1), initial whitespaces are handled as well, if any
        if (s[i] != ' ' && prevSpace) {
            result++;
        }
        prevSpace = (currChar == ' ');
    }

	fprintf(stderr, "[WARN] <<< Exiting countSegments(s=%s)\n", s);
    return result;
}
