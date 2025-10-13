#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    
    char sen[100];
    char cipher[100];
    printf("Enter the string: ");
    fgets(sen, 100, stdin);    
    printf("Output : %s", sen);
    int shift;
    printf("Enter the shifting number: ");
    scanf("%d", &shift);
    
        for(int i=0; i<=strlen(sen);i++){
            i=i+shift;
            printf("%s", i);

            
            //printf("The string is: %s\n",sen);
        }
    }
