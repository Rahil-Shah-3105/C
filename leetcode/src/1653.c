#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

// Dynamic programming approach. Down -> Up.
// Runtime: O(n)
// Space: O(1)
int minimumDeletions(char * s){
	fprintf(stderr, ">>> Entering minimumDeletions(s=%s)\n", s);
    int len = strlen(s);
    
	fprintf(stderr, "minimumDeletions(s=%d): len → %d\n", s, len);
    int aStateValue = s[0] == 'b';
	fprintf(stderr, "minimumDeletions(s=%d): aStateValue → %d\n", s, aStateValue);

    int bStateValue = 0;
	fprintf(stderr, "minimumDeletions(s=%d): bStateValue → %d\n", s, bStateValue);
    
    int newAStateValue;
    int newBStateValue;

    for(int i = 1; i < len; i++){
        newAStateValue = aStateValue + (s[i] == 'b');
		fprintf(stderr, "minimumDeletions(s=%d): newAStateValue → %d\n", s, newAStateValue);

        newBStateValue = min(
                               aStateValue,
                               bStateValue + (s[i] == 'a')
                             );
							fprintf(stderr, "minimumDeletions(s=%d): newBStateValue → %d\n", s, newBStateValue);
            
        aStateValue = newAStateValue;
        bStateValue = newBStateValue;
    }
    
	fprintf(stderr, "<<< Exiting minimumDeletions(s=%s)\n", s);
    return min(aStateValue, bStateValue);
}
