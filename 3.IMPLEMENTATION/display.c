#include "cafe.h"
/**
 * @brief displayOrder declared
 * 
 * @return int 
 */

int displayOrder(){
    int i=0;
    int totalPrice=0;
    char order[10][20]={""};
    printf("\n     Your Final Order     \n");
    while(strlen(order[i])!=0){
        printf("item = %s, quantity = %s\n",order[i],order[i+1]);
        i = i+2;
    }
    printf("Total Price = %d",totalPrice);
    printf("\n\n\nThank you for visiting our cafe");
    return 0;
}