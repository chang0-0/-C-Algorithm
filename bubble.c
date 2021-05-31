#include <stdio.h>
#include <stdlib.h>

int bubble(int array[5]);
                                                         
int main(void){
    int array[5];
    int rearray[5];

    for(int i=0; i<sizeof(array)/sizeof(int); i++){
        printf("정수 배열 5개 입력 : ");
        scanf("%d", &array[i]);
    }
    
    rearray[5] = bubble(array[5]);

    for(int i=0; i<sizeof(rearray)/sizeof(int); i++){
        printf("정렬된 배열 rearray[%d] : %d\n",i, rearray[i]);
    }

    return 0;
}

int bubble(int array[5]){ 
    int temp = 0;
    
    for(int i = 0; i < sizeof(array)/sizeof(int); i++){
        for(int j=0; j < sizeof(array)/sizeof(int) -1; j--){
            if(array[i] > array[i+1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}