// Given a string s, returns the number of segments in the string.
int countSegments(char * s){
	fprintf(stderr, ">>> Entering countSegments(s=%s)\n", s);
    int sLen = strlen(s);
    int prevSpace = 1;
	fprintf(stderr, "countSegments(s=%d): prevSpace → %d\n", s, prevSpace);
    int result = 0;
	fprintf(stderr, "countSegments(s=%d): result → %d\n", s, result);
	fprintf(stderr, "countSegments(s=%d): sLen → %d\n", s, sLen);
    char currChar;

    for (int i = 0; i < sLen; i++){
        currChar = s[i];
		fprintf(stderr, "countSegments(s=%d): currChar → %d\n", s, currChar);

        //A string of whitespaces will only be counted once as the condition below is only true when we transition from whitespace to non-whitespace.
        //Since we start with assumed whitespace (prevSpace = 1), initial whitespaces are handled as well, if any
        if (s[i] != ' ' && prevSpace) {
            result++;
        }
        prevSpace = (currChar == ' ');
    }

	fprintf(stderr, "<<< Exiting countSegments(s=%s)\n", s);
    return result;
}
