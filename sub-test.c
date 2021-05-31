#include <stdio.h>
#include <stdlib.h>

void sub(int n) {
    int sum = 0;
    int i = 0;
    for(i=n; i>0;i=i-3) {
        sum = sum + i;
        printf("%d ",sum);
    }
}

int main(void) {
    sub(10);

    return 0;
}