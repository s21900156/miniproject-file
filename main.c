#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

int main(void){
    printf("***DEBUG: %s %s %s %d\n", __DATE__,__TIME__,__FILE__,__LINE__);

    Product plist[20];
    int index =0;
    int count = 0, menu;
    count=loadData2(plist);
    index=count;
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        
	if (menu == 1){
            if(count==0) printf("정보가 없습니다\n");
            else listProduct(plist,index);
        }
        else if (menu == 2){
            count+=createProduct(&plist[index++]);
            printf("=> 추가됨!\n");
        }
        else if (menu == 3){
            if(count==0) printf("정보가 없습니다\n");
            else {
                int no=selectDataNum(plist,index);
                if(no==0) {
                    printf("=> 취소됨 \n");
                }
                else{
                updateProduct(&plist[no-1]);
                printf("=> 수정됨!\n");
                }
            }

        }
        else if (menu == 4){
            if(count==0) printf("점수가 없습니다\n");
            else {
                int no=selectDataNum(plist,index);
                if(no==0) {
                    printf("=> 취소됨 \n");
                }
                else{
                        int deleteok;
                        printf("정말로 삭제하시겠습니까?(삭제 : 1)");
                        scanf("%d",&deleteok);
                        if(deleteok==1){
                        deleteProduct(&plist[no-1]);
                        count--;
                        printf("=> 삭제됨!\n");
                        }
                    }
                }
        }
        else if(menu==5){
            saveData2(plist,index);
        }
        else if(menu==6){
            searchProduct2(plist,index);
        }
        else if(menu==7){
            searchPrice2(plist,index);
        }
        else if(menu==8){
            searchDeliverynum2(plist,index);
        }
    }
    printf("종료됨!\n");
    return 0;
}
