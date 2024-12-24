#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int m;
    printf("Hãy nhập vào số dòng : ");
    scanf("%d",&m);
    fflush(stdin);
    FILE *file=fopen("bt05.txt", "w");
    char string[50];
    for(int i=0;i<m;i++){
        printf("Hãy nhập dòng thứ %d cho file :",i+1);
        fgets(string, 50, stdin);
    
        fputs(string, file);
        
    }
    fclose(file);
    file =fopen("bt05.txt", "r");
    int c=fgetc(file);
    while(c!=EOF){
        printf("%c",c);
        c=fgetc(file);
    }
    fclose(file);
    return 0;
}
