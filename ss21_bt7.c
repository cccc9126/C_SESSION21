#include <stdio.h>
#include <string.h>
struct SinhVien{
    int id;
    char name[50];
    int age;
};

void inputItem(struct SinhVien *user,int m);
int main(int argc, const char * argv[]) {
    int m;
    printf("Hãy nhập số lượng sinh viên : ");
    scanf("%d",&m);
    struct SinhVien user[m];
    inputItem(&user,m);
    FILE *file=fopen("students.txt", "w");
    for(int i=0;i<m;i++){
        fprintf(file, "ID : %d\t",i+1);
        fprintf(file, "NAME : %s\t",user[i].name);
        fprintf(file, "AGE : %d\n",user[i].age);
        
    }
    fclose(file);
    file=fopen("students.txt", "r");
    int c;
    while (c!=EOF) {
        c=fgetc(file);
        printf("%c",c);
    }
    return 0;
}
void inputItem(struct SinhVien *user,int m){
    for(int i = 0;i<m;i++){
        printf("Nhập id cho sinh viên %d :",i+1);
        scanf("%d",&user[i].id);
        fflush(stdin);
        printf("Nhập tên cho sinh vien %d : ",i+1);
        fgets(user[i].name, 50, stdin);
        user[i].name[strcspn(user[i].name, "\n")]='\0';
        printf("Hãy nhập tuổi của sinh viên %d : ",i+1);
        scanf("%d",&user[i].age);
        fflush(stdin);
    }
    
}
