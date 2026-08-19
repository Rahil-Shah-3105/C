#include <stdio.h>
long numberOfWaysForChar(char * s, char c){
	fprintf(stderr, ">>> Entering numberOfWaysForChar(s=%s,c=%c)\n", s, c);
    long firstBuildingAppearNumber = 0;
    long secondBuildingAppearNumber = 0;
    long result = 0;
	fprintf(stderr, "numberOfWaysForChar(s=%s,c=%c): result → %d\n", s, c, result);
    
    int sLength = strlen(s);
	fprintf(stderr, "numberOfWaysForChar(s=%s,c=%c): sLength → %d\n", s, c, sLength);
    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            result += secondBuildingAppearNumber;

            firstBuildingAppearNumber += 1;
            continue;
        }

        secondBuildingAppearNumber += firstBuildingAppearNumber;
    }
    
	fprintf(stderr, "<<< Exiting numberOfWaysForChar(s=%s,c=%c)\n", s, c);
    return result;
        
}

// numberOfWays returns the sum of number ways of selecting first building
// and the number of ways of selecting second building which gives us the
// number of ways of selecting three building such that no
// consecutive buildings are in the same category.
// Runtime: O(n)
// Space: O(n)
long long numberOfWays(char * s){
    return numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
}
