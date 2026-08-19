#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int intersectionSize(int p11, int p12, int p21, int p22){
	fprintf(stderr, ">>> Entering intersectionSize(p11=%d,p12=%d,p21=%d,p22=%d)\n", p11, p12, p21, p22);
    if (p11 >= p22 || p12 <= p21){
        return 0;
    }

    if (p11 < p21){
	fprintf(stderr, "<<< Exiting intersectionSize(p11=%d,p12=%d,p21=%d,p22=%d)\n", p11, p12, p21, p22);
        return min(p12 - p21, p22 - p21);
    }

    return min(p22 - p11, p12 - p11);
}

// Calculation area of the A, then area of the B then minus intersection of A and B
// Runtime: O(1)
// Space: O(1)
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
	fprintf(stderr, ">>> Entering computeArea(ax1=%d,ay1=%d,ax2=%d,ay2=%d,bx1=%d,by1=%d,bx2=%d,by2=%d)\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    int areaA = (ay2 - ay1) * (ax2 - ax1);
    int areaB = (by2 - by1) * (bx2 - bx1);
	fprintf(stderr, "computeArea(ax1=%d,ay1=%d,ax2=%d,ay2=%d,bx1=%d,by1=%d,bx2=%d,by2=%d): areaB → %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, areaB);
    int areaInteresection = intersectionSize(ax1, ax2, bx1, bx2) * intersectionSize(ay1, ay2, by1, by2);
	fprintf(stderr, "computeArea(ax1=%d,ay1=%d,ax2=%d,ay2=%d,bx1=%d,by1=%d,bx2=%d,by2=%d): areaInteresection → %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, areaInteresection);
	fprintf(stderr, "computeArea(ax1=%d,ay1=%d,ax2=%d,ay2=%d,bx1=%d,by1=%d,bx2=%d,by2=%d): areaA → %d\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2, areaA);
    fprintf(stderr, "<<< Exiting computeArea(ax1=%d,ay1=%d,ax2=%d,ay2=%d,bx1=%d,by1=%d,bx2=%d,by2=%d)\n", ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    
    return areaA + areaB - areaInteresection;
}
