#include <stdio.h>


int main() {
    int a[] = {10, 20, 20, 10, 10, 20, 5, 20}; 
    int b = sizeof(a) / sizeof(int); 

    for (int i = 0; i < b; i++) {
        int eleman = a[i];
        int frekans = 1; 

        for (int j = i + 1; j < b; j++) {
            if (a[j] == eleman) {
                frekans++;
                a[j] = -1; 
            }
        }

        if (eleman != -1) {
            printf("%d › %d\n", eleman, frekans);
        }
    }

    return 0;
}

