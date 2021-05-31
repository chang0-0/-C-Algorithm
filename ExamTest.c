#include <stdio.h>

int main(void) {
    int i=2, j=0;

    // for(i=2; i<10; i++) {
    //     for(j=1; j<10; j++) {
    //         printf("%d %d \n",i, j);
    //     }
    // }  

    while(i<10) {
        while(j<10) {
            j++;
        }
        printf("%d \n", i);
        i++;

        printf("%d\n", i);

    }


    printf("%d %d %d",i, j, i*j);
}