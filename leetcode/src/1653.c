#include "stdio.h"
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

// Dynamic programming approach. Down -> Up.
// Runtime: O(n)
// Space: O(1)
int minimumDeletions(char * s){
	fprintf(stderr, "[ERROR] >>> Entering minimumDeletions(s=%s)\n", s);
    int len = strlen(s);
    
	fprintf(stderr, "[ERROR] minimumDeletions(s=%s): len → %d\n", s, len);
    int aStateValue = s[0] == 'b';
	fprintf(stderr, "[ERROR] minimumDeletions(s=%s): aStateValue → %d\n", s, aStateValue);

    int bStateValue = 0;
    
    int newAStateValue;
    int newBStateValue;

    for(int i = 1; i < len; i++){
        newAStateValue = aStateValue + (s[i] == 'b');
		fprintf(stderr, "[ERROR] minimumDeletions(s=%s): newAStateValue → %d\n", s, newAStateValue);

        newBStateValue = min(
                               aStateValue,
                               bStateValue + (s[i] == 'a')
                             );
							fprintf(stderr, "[DEBUG] minimumDeletions(s=%s): newBStateValue → %d\n", s, newBStateValue);
            
        aStateValue = newAStateValue;
        bStateValue = newBStateValue;
		fprintf(stderr, "[ERROR] minimumDeletions(s=%s): bStateValue → %d\n", s, bStateValue);
    }
    
	fprintf(stderr, "[WARN] <<< Exiting minimumDeletions(s=%s)\n", s);
    return min(aStateValue, bStateValue);
}
