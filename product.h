#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product{
    char name[30];
    char detail[100];
    char weight[20];
    int price;
    int deliverynum;// (1:새벽배송/2:택배배송)
}Product;

int createProduct(Product *p);//제품을 추가하는 함수
int readProduct(Product *p,int count);//제품하나를 출력하는 함수
int listProduct(Product *p,int count);//전체 등록된 제품 리스트 출력함수
int deleteProduct(Product *p);//제품을 삭제하는 함수
int selectDataNum(Product *p, int count); // 수정하거나 삭제할 때 필요한 번호를 입력받는 함수
int loadData(Product *p);//저장된 파일에서 데이터를 불러오는 함수
void saveData(Product *p,int count);//파일로 저장하는 함수
int updateProduct(Product *p);//제품을 수정하는 함수
void searchProduct(Product *p,int count);//제품 이름을 검색하는 함수
int selectMenu();//실해하려는 메뉴들을 출력하고, 메뉴번호를 입력받는 함수
void searchPrice(Product *p,int count);//제품 가격을 검색하는 함수
void searchDeliverynum(Product *p,int count);//제품 배송방법이 같은 것을 검색하는 함수

