#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#define file struct File
struct File{
    char name[20],num[13];

};

int Lofcont,i,j,cnt=0,cnt1=0,nd,com,com2,c,uni,I=0,len,xz;
char or,sear[20],shot1[20],shot2[20];
file x[100]={},delnam[100]={},nase[10]={},tamp,update1;

void shotdata(){
    for(j=0;j<Lofcont;j++){
        for(i=0;i<Lofcont;i++){
            strcpy(shot1,x[j].name);
            strcpy(shot2,x[i].name);
            if(strcmp(strlwr(shot1),strlwr(shot2))<0){
                    tamp=x[j];
                    x[j]=x[i];
                    x[i]=tamp;
            }
        }
    }
}

void showdata(){
    system("cls");
    readdata();
    shotdata();
    for(i=0;i<Lofcont;i++){
        or=x[i].name[0];
        if(toupper(or)!=I){
            printf("------%c------\n\n",toupper(or));
            I=toupper(or);
        }
        printf("%s\n",x[i].name);
        printf("%s\n",x[i].num);
//        printf("%s\n",x[i].add);
        printf("\n");
    }
}

void readdata(){
    FILE *ph;
    ph=fopen("Phonenum.txt","r");
    fscanf(ph,"%d",&Lofcont);
    for(i=0;i<Lofcont;i++){
        fscanf(ph," %[^\n]",x[i].name);
        fscanf(ph,"%s",&x[i].num);
//        fscanf(ph," %[^\n]",x[i].add);
    }
    fclose(ph);
}

void writedata(){
    shotdata();
    FILE *ph;
    ph=fopen("Phonenum.txt","w");
    fprintf(ph,"%d\n",Lofcont);
    for(i=0;i<Lofcont;i++){
        fprintf(ph,"%s\n",x[i].name);
        fprintf(ph,"%s\n",x[i].num);
//        fprintf(ph,"%s\n",x[i].add);
    }
    fclose(ph);
}

void adddata(){
    printf("Number of contect to add=");
    scanf("%d",&c);
    for(i=Lofcont;i<Lofcont+c;i++){
        j:
        printf("Name=");
        scanf(" %[^\n]",x[i].name);
        for(j=0;j<Lofcont;j++){
            if(strcmp(x[i].name,x[j].name)==0){
                printf("\nName has been used\n\n");
                goto j;
            }
        }
        k:
        printf("Number=");
        scanf("%s",&x[i].num);
        for(j=0;j<Lofcont;j++){
            if(strcmp(x[i].num,x[j].num)==0){
                printf("\nNumber has been used\n\n");
                goto k;
            }
        }
    }
//        printf("Address=");
//        scanf(" %[^\n]",x[i].name);
        Lofcont=Lofcont+c;
        writedata();
        printf("\nAdded Successfully.\n");
}

void update(){
    n:
    printf("Name=");
    scanf(" %[^\n]",&delnam[0].name);
    readdata();
    FILE *ph;
    ph=fopen("Phonenum.txt","w");
    fprintf(ph,"%d\n",Lofcont);
    cnt1=0;
    for(i=0;i<Lofcont;i++){
        com=strcmp(delnam[0].name, x[i].name);
        if(com!=0){
            fprintf(ph,"%s\n",x[i].name);
            fprintf(ph,"%s\n",x[i].num);
        }else{
            l:
            printf("Number=");
            scanf("%s",&delnam[0].num);
            for(j=0;j<Lofcont;j++){
                if(strcmp(delnam[0].num ,x[j].num)==0){
                    printf("\nNumber has been used\n\n");
                    goto l;
                }
            }
            fprintf(ph,"%s\n",delnam[0].name);
            fprintf(ph,"%s\n",delnam[0].num);
            cnt1=99;
        }
    }if(cnt1!=99){
        printf("\nNama doesn't exist\n\n");
        goto n;
    }
    fclose(ph);
    printf("\nNumber updated Successfully\n");
}

void searchdata(){
    system("cls");
    char sear[20]={};
    len=0;
    cnt=0;
    printf("Name=");
    scanf(" %[^\n]",&nase[0].name);
    len=strlen(nase[0].name);
    for(i=0;i<Lofcont;i++){
        strncpy(sear,x[i].name,len);//1
        com2=strcmp(strlwr(nase[0].name),strlwr(sear));
        if(com2==0){
            cnt++;
            printf("\n");
            printf("%s\n",x[i].name);
            printf("%s\n",x[i].num);
        }
    }
    if(cnt==0){
        printf("\nNot found\n");
    }
}

void Menu(){
    system("cls");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("|                                         PhoneBook                                                 |\n");
    printf("|                                   Show Contact(press 1)                                           |\n");
    printf("|                                      Add Data(press 2)                                            |\n");
    printf("|                                    Delete Data(press 3)                                           |\n");
    printf("|                                    Search Data(press 4)                                           |\n");
    printf("|                                      Update(press 5)                                              |\n");
    printf("|                                       Exit(press 10)                                              |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void printmenu(){
    printf("|                                       Menu(Press 11)                                              |\n");
    printf("|                                       Exit(press 10)                                              |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
}

void deletedata(){
        o:
        cnt1=0;
        printf("Name=");
        scanf(" %[^\n]",&delnam[1].name);
        readdata();
        FILE *ph;
        ph=fopen("Phonenum.txt","w");
        fprintf(ph,"%d\n",Lofcont-1);
        for(i=0;i<Lofcont;i++){
            com=strcmp(delnam[1].name, x[i].name);
            if(com!=0){
                fprintf(ph,"%s\n",x[i].name);
                fprintf(ph,"%s\n",x[i].num);
            }else{
                cnt1=99;
            }
        }
        if(cnt1!=99){
            printf("\nNama doesn't exist\n\n");
            goto o;
        }
        fclose(ph);
        printf("\nDeleted Successfully.\n");
}

int main(){
    int d;
    readdata();
    Menu();
    for(i=0;;i++){
        scanf("%d",&d);
        if(d==1){
            showdata();
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|                                   Show Contact(press 1)                                           |\n");
            printmenu();
        }else if(d==2){
            adddata();
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|                                      Add Data(press 2)                                            |\n");
            printmenu();
        }else if(d==3){
            deletedata();
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|                                    Delete Data(press 3)                                           |\n");
            printmenu();
        }else if(d==4){
            searchdata();
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|                                    Search Data(press 4)                                           |\n");
            printmenu();
        }else if(d==5){
            update();
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("|                                      Update(press 5)                                              |\n");
            printmenu();
        }else if(d==10){
            break;
        }else if(d==11){
            Menu();
        }
    }
    return 0;
}

