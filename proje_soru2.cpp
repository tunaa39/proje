#include <stdio.h>

	int	main() {
	 	
    int dizi1[] = {1, 3, 4, 5};
    int dizi2[] = {2, 4, 6, 8};
    int uzunluk1 = sizeof(dizi1) / sizeof(int);
    int uzunluk2 = sizeof(dizi2) / sizeof(int);
    int dizi3[uzunluk1 + uzunluk2]; 

    int i = 0, j = 0, k = 0;

    while (i < uzunluk1 && j < uzunluk2) {
        if (dizi1[i] < dizi2[j]) {
            dizi3[k] = dizi1[i];
            i++;
        } else {
            dizi3[k] = dizi2[j];
            j++;
        }
        k++;
    }

    while (i < uzunluk1) {
        dizi3[k] = dizi1[i];
        i++;
        k++;
    }

    while (j < uzunluk2) {
        dizi3[k] = dizi2[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        printf("%d ", dizi3[m]);
    }

    return 0;
}


