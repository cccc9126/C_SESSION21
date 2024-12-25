#include <stdio.h>
#include <string.h>
struct Temp{
    int id;
    char name[50];
    int age;
};
struct SinhVien{
    int id;
    char name[50];
    int age;
};

int main(int argc, const char * argv[]) {
    struct Temp user[10]={
        {1,"HUYY",18},
        {2,"HAHA",19},
        {3,"HIHI",20},
        {4,"HUHU",21},
        {5,"HEHE",22}
    };
    
    FILE *file=fopen("students.bin", "wb");
    for(int i=0;i<5;i++){
        fwrite(&user[i], sizeof(struct Temp), 1, file);
    }
    printf("Ghi dữ liệu thành công");
    
    fclose(file);
    file = fopen("students.bin", "rb");
    for(int i=5;i<10;i++){
        fread(&user[i], sizeof(struct Temp), 1, file);
    }
    printf("Lấy dữ liệu thành công");
    fclose(file);
    for(int i = 5;i<10;i++){
        printf("ID : %d\nNAME : %s\nAGE : %d\n",user[i].id,user[i].name,user[i].age);
    }
    return 0;
}
