int coundDevices(char* bankRow){
	fprintf(stderr, ">>> Entering coundDevices(bankRow=%s)\n", bankRow);
    int result = 0;
    int bankRowSize = strlen(bankRow);
	fprintf(stderr, "coundDevices(bankRow=%d): bankRowSize → %d\n", bankRow, bankRowSize);
	fprintf(stderr, "coundDevices(bankRow=%d): result → %d\n", bankRow, result);
    for(int i = 0; i < bankRowSize; i++){
        if (bankRow[i] == '1'){
            result++;
        }
    }

	fprintf(stderr, "<<< Exiting coundDevices(bankRow=%s)\n", bankRow);
    return result;
}

// Counting devices in each row
// Runtime: O(n*m), n-number of bank rows, m - max size of row.
// Space: O(1)
int numberOfBeams(char ** bank, int bankSize){
	fprintf(stderr, ">>> Entering numberOfBeams(bank=%s,bankSize=%d)\n", bank, bankSize);
    int prevRowDevices = 0;
    int result = 0;
	fprintf(stderr, "numberOfBeams(bank=%d,bankSize=%d): result → %d\n", bank, bankSize, result);
	fprintf(stderr, "numberOfBeams(bank=%d,bankSize=%d): prevRowDevices → %d\n", bank, bankSize, prevRowDevices);
    for(int i = 0; i < bankSize; i++){
        int devices = coundDevices(bank[i]);
		fprintf(stderr, "numberOfBeams(bank=%d,bankSize=%d): devices → %d\n", bank, bankSize, devices);
        if (devices == 0){
            continue;
        }

        result += devices * prevRowDevices;
        prevRowDevices = devices;
    }

	fprintf(stderr, "<<< Exiting numberOfBeams(bank=%s,bankSize=%d)\n", bank, bankSize);
    return result;
}
