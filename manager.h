#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int loadData2(Product *p);// 저장된 데이터들을 받아오는 함수
void saveData2(Product *p,int count);//다중데이터들을 파일로 저장하는 함수
void searchProduct2(Product *p,int count);//제품 이름을 검색하는 함수(다중데이터)
void searchPrice2(Product *p,int count);//제품 가격을 검색하는 함수(다중데이터)
void searchDeliverynum2(Product *p,int count);//제품 배송방법이 같은 것을 검색하는 함수(다중데이터)

