
#include<stdio.h>
#include<string.h>

char str1[30],str2[30];

int compare(){
    int ln1,ln2,i,c;
    ln1= strlen(str1);
    ln2= strlen(str2);

    if(ln1!=ln2){
        printf("String not matched");
    }
    else{
        for(i=0;i<ln1-1;i++){
            if(str1[i]==str2[i]){
                c= 0;
            }
            else {
                if(str1[i]>str2[i]){
                    c= 1;
                }
                else{
                    c= -1;
                }
                break;
            }
        }
    }
    return c;
}
int main(){
    int cmp;
    printf("Enter String 1:: ");
    gets(str1);
    printf("Enter String 2:: ");
    gets(str2);

    //compare
    cmp= strcmp(str1,str2);
    if(cmp== 0){
        printf("String Matched %d",cmp);
    }
    else{
        printf("String not matched %d",cmp);
    }
    
    //user define function
    printf("\n-------------------------------\n");
    cmp= compare();
    if(cmp== 0){
        printf("String Matched %d",cmp);
    }
    else{
        printf("String not matched %d",cmp);
    }
    return 0;
}