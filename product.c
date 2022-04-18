#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

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
int deleteProduct(Product *p){
    p->price=-1;
    return 1;
}
void searchProduct(Product *p,int count){
    char name[30];
    int num =0;
    printf("검색할 과일이름은? ");
    scanf("%[^\n]s",name);
    printf("*****************************************\n");
    if(strstr(p->name,name)==NULL) num=0;
    else{
        readProduct(p,0);
        num++;
    }
    if(num==0) printf("=> 검색된 데이터 없음\n");
}

void searchPrice(Product *p,int count){
    int searchnum=0;
    int num =0;
    printf("검색할 가격은? ");
    scanf("%d",&searchnum);
    printf("*****************************************\n");
    if(p->price!=searchnum) num=0;
    else{
        readProduct(p,0);
        num++;
    }
    if(num==0) printf("=> 검색된 데이터 없음\n");
}

void searchDeliverynum(Product *p,int count){
    int num =0;
    int search;
    printf("검색할 배송방법은?(1:새벽배송/2:택배배송) ");
    scanf("%d",&search);
    printf("*****************************************\n");
    if(p->deliverynum!=search) num=0;
    else{
        readProduct(p,0);
        num++;
    }
    if(num==0) printf("=> 검색된 데이터 없음\n");
}

void saveData(Product *p,int count){
    FILE *fp;
    fp=fopen("product.txt","w");
        fprintf(fp,"%s\n%s\n%s\n%d\n%d\n", p[count].name,p[count].detail,p[count].weight,p[count].price,p[count].deliverynum);
        fclose(fp);
        printf("=> 저장됨! \n");
}

int loadData(Product *p){
    int count,i=0;
    FILE *fp;
    fp=fopen("product.txt","r");
    if(fp==NULL){
        printf("=> 파일 없음\n");
        return 0;
    }
    else{
            fscanf(fp,"%[^\n]\n %[^\n]\n %[^\n]\n %d\n %d\n", p[i].name, p[i].detail, p[i].weight, &p[i].price, &p[i].deliverynum);
            fclose(fp);
            printf("=> 로딩 성공 ");
            return 1;
        }
}

int main(void){
    Product plist[20];
    int index =0;
    int count = 0, menu;
    count=loadData(plist);
    int no=1;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count==0) printf("정보가 없습니다\n");
            else readProduct(plist,index);
	}
        else if (menu == 2){
            if(count>=1) {
                printf("하나만 입력하실 수 있습니다\n");
                continue;
            }
            else{
            count+=createProduct(&plist[index]);
            printf("=> 추가됨!\n");
            }
        }
	else if (menu == 3){
            if(count==0) printf("정보가 없습니다\n");
            else {
                readProduct(plist,index);
                printf("정말로 수정하겠습니까? (확인 : 1 / 취소 : 0) ");
                scanf("%d",&no);
                if(no==0) {
                    printf("=> 취소됨 \n");
                    continue;
                }
                else{
                updateProduct(&plist[index]);
                printf("=> 수정됨!\n");
                }
            }
	}
	else if (menu == 4){
            if(count==0) printf("점수가 없습니다\n");
            else {
                readProduct(plist,index);
                printf("정말로 삭제하겠습니까? (확인 : 1 / 취소 : 0) ");
                scanf("%d",&no);
                getchar();
                if(no==0) {
                    printf("=> 취소됨 \n");
                    continue;
                }
                else{
                        deleteProduct(&plist[index]);
                        count--;
                        printf("=> 삭제됨!\n");
                    }
                }
        }
	else if(menu==5){
            saveData(plist,index);
        }
	else if(menu==6){
            searchProduct(plist,index);
        }
	else if(menu==7){
            searchPrice(plist,index);
    	}
	else if(menu==8){
            searchDeliverynum(plist,index);
        }
    }
}
