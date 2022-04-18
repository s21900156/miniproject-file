#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int createProduct(Product *p){
    printf("이름은? ");
    scanf("%[^\n]s",p->name);
    getchar();
    printf("원산지는? ");
    scanf("%[^\n]s",p->detail);
    printf("무게는? ");
    scanf("%s",p->weight);
    printf("가격은? ");
    scanf("%d",&p->price);
    printf("배송방법은? (1:새벽배송/2:택배배송) ");
    scanf("%d",&p->deliverynum);
    return 1;
}

int readProduct(Product *p,int count){
    int discount;//구매혜택을 나타내기 위한 변수선언
    discount = p[count].price/100;
    printf("[%s] %s %s\n", p[count].detail,p[count].name,p[count].weight);//원산지, 과일이름, 무게를 출력
    printf("가격 : %d\n",p[count].price);//가격출력
    printf("구매혜택 : 회원적립금 : +%d원\n",discount);
    printf("원산지 : [%s]\n", p[count].detail);
    printf("판매단위: [%s]단위\n",p[count].weight);
    if(p[count].deliverynum==1){
        printf("배송방법: 새벽배송\n");
    }
    else{
        printf("배송방법: 택배배송\n");
    }
   return 0; 
}

int selectMenu(){
    int menu;
    printf("\n*** 쇼핑몰 ***\n");
    printf("1. 과일조회\n");
    printf("2. 과일추가\n");
    printf("3. 과일수정\n");
    printf("4. 과일삭제\n");
    printf("5. 파일저장\n");
    printf("6. 과일검색\n");
    printf("7. 가격검색\n");
    printf("8. 배송방법검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}

int deleteProduct(Product *p){
    p->price=-1;
    return 1;
}

int updateProduct(Product *p){
    getchar();
    printf("새 이름은? ");
    scanf("%[^\n]s",p->name);
    getchar();
    printf("원산지는? ");
    scanf("%[^\n]s",p->detail);
    printf("무게는? ");
    scanf("%s",p->weight);
    printf("가격은? ");
    scanf("%d",&p->price);
    printf("배송방법은? (1:새벽배송/2:택배배송) ");
    scanf("%d",&p->deliverynum);
    return 1;
}

int listProduct(Product *p,int count){
    printf(" **************************************\n ");
    printf("번호   원산지    과일이름    판매단위      가격     배송방법\n");
    for(int i=0 ; i<count; i++){
        if(p[i].price==-1) continue;
        if(p[i].deliverynum==1){
        printf("%2d ) [%9s] %10s    %6s     %8d원   새벽배송\n", i+1, p[i].detail,p[i].name, p[i].weight,p[i].price);
        }
        else{
        printf("%2d ) [%9s] %10s    %6s    %8d원   택배배송\n", i+1, p[i].detail,p[i].name, p[i].weight,p[i].price);
        }
    }
    return 0;
}

int selectDataNum(Product *p, int count){
    int num;
    listProduct(p,count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &num);
    return num;
}

int loadData2(Product *p){
    int i=0;
    FILE *fp;
    fp=fopen("product.txt","r");
    if(fp==NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    else{
        for(;i<100;i++){
            if(feof(fp)) break;
            char temp[50];
            fscanf(fp,"%[^\n]\n %[^\n]\n %[^\n]\n %[^\n]\n %d\n %d\n",temp, p[i].name, p[i].detail, p[i].weight, &p[i].price, &p[i].deliverynum); 
        }
        fclose(fp);
        printf("=> 로딩 성공 ");
        return i;
    }
}
void saveData2(Product *p,int count){
     FILE *fp;
    fp=fopen("product.txt","w");
    for(int i=0;i<count;i++){
        if(p==NULL) continue;
        fprintf(fp,"*******************\n");
        fprintf(fp,"%s\n%s\n%s\n%d\n%d\n", p[i].name,p[i].detail,p[i].weight,p[i].price,p[i].deliverynum);
    }
        fclose(fp);
        printf("=> 저장됨! \n");
}
void searchProduct2(Product *p,int count){
    char name[30];
    int num =0;
    printf("검색할 과일이름은? ");
    scanf("%[^\n]s",name);
    for(int i=0;i<count;i++){
        if(strstr(p[i].name,name)==NULL) continue;
        else{
            printf("*****************************************\n");
            readProduct(p,i);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음\n");
}

void searchPrice2(Product *p,int count){
    int searchnum=0;
    int num =0;
    printf("검색할 가격은? ");
    scanf("%d",&searchnum);
    for(int i=0;i<count;i++){
        if(p[i].price!=searchnum) continue;
        else{
            printf("*****************************************\n");
            readProduct(p,i);
            num++;
        }
    }
    if(num==0) printf("=> 검색된 데이터 없음\n");
}

void searchDeliverynum2(Product *p,int count){
    int num =0;
    int search;
    printf("검색할 배송방법은?(1:새벽배송/2:택배배송) ");
    scanf("%d",&search);
    for(int i=0;i<count;i++){
        if(p[i].deliverynum!=search) continue;
        else{
            printf("*****************************************\n");
            readProduct(p,i);
            num++;
        }
    if(num==0) printf("=> 검색된 데이터 없음\n");
    }
}
