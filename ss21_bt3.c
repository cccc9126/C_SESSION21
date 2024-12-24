#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char bt01[50];
    printf("Hãy nhập chuỗi bất kì vào file : ");
    fgets(bt01, 50, stdin);
    bt01[strcspn(bt01, "\n")]='\0';
    int length = (int)strlen(bt01);
    FILE *file=fopen("bt01.txt", "w");
    for(int i =0;i<length;i++){
        fputc(bt01[i], file);
    }
    fclose(file);
    file=fopen("bt01.txt", "a");
    printf("hãy nhập chuỗi bất kì để thêm vào file : ");
    char anyString[50];
    fgets(anyString, 50, stdin);
    anyString[strcspn(anyString, "\n")]='\0';
    int length1 = (int)strlen(anyString);
    for(int i =0;i<length1;i++){
        fputc(anyString[i], file);
    }
    fclose(file);
    file = fopen("bt01.txt", "r");
    int c=fgetc(file);
    while(c!=EOF){
        c=fgetc(file);
        printf("%c\n",c);
    }
    fclose(file);
    return 0;
}
