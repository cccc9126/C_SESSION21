#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char bt01[50]="hello hahaa";
    bt01[strcspn(bt01, "\n")]='\0';
    int length = (int)strlen(bt01);
    FILE *file=fopen("bt01.txt", "w");
    for(int i =0;i<length;i++){
        fputc(bt01[i], file);
    }
    fclose(file);
    file=fopen("bt01.txt", "r");
    FILE *filetemp=fopen("bt06.txt", "w");
    int c;
    while((c=fgetc(file))!=EOF){
        
        fputc(c, filetemp);
    }
    fclose(file);
    fclose(filetemp);
    filetemp=fopen("bt06.txt", "r");
    int t ;
    while((t = fgetc(filetemp))!=EOF){
        printf("%c",t);

    }
    fclose(filetemp);
    return 0;
}
