#include <stdio.h>

//이중 배열 생성
int main(void) {
    int two[10];

    for(int i=0; i<10; i++) {
        two[i] = 1;
        if(i==0) {
            two[i] = 1;
        }
        for(int j=0; j<i; j++) {
            two[i] *= 2;
        }

        printf("%d \n",two[i]);
    }

    return 0;
}