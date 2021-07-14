/**
 * @file coffee.c
 * @author ShivaliGokhale (shivaligokhale.4@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>

void showMenu();
int takeOrder();
int displayOrder();
void refreshOrderlist();
char menu[5][20] = {"Latte","Cappuccinoo","Mocha","Cold Coffee","Expresso"};
int stock[5]={1000,1000,1000,1000,1000};
int prices[5]={70,120,100,50,80};
char order[10][20]={""};
int totalPrice=0;
int flag;
int j=0;
void main()
{
    while(1)
    {
        int user;
        char order[10][20]={"0"};
        printf("\nWelcome to the cafe \n");
        printf("1. Old User\n");
        printf("2. New User\n");
        scanf("%d",&user);
        if(user==1){
            int option;
            printf("1. Show Menu\n");
            printf("2. Order Directly\n");
            scanf("%d",&option);
            if(option==1){
                showMenu();
                printf("What would you like to have..?");
                int y = takeOrder();
                int x = displayOrder();
            }
            else{
                printf("What would you like to have..?");
                int y = takeOrder();
                int x = displayOrder();
            }

        }
        else if(user==2){
            showMenu();
            printf("What would you like to have..?");
            int y = takeOrder();
            int x = displayOrder();
        }
        refreshOrderlist();
        printf("\nPress 0 to exit system or any other no. key for next order");
        scanf("%d",&flag);
        if(flag == 0){
            break;
        }
    }
}
void showMenu(){
    printf("----------------------------------------------------\n");
    printf("| no. |Name         |Price |Stock |\n");
    printf("----------------------------------------------------\n");
    printf("|  1. |%s        |%d    |%d  |\n",menu[0],prices[0],stock[0]);
    printf("----------------------------------------------------\n");
    printf("|  2. |%s  |%d   |%d  |\n",menu[1],prices[1],stock[1]);
    printf("----------------------------------------------------\n");
    printf("|  3. |%s        |%d   |%d  |\n",menu[2],prices[2],stock[2]);
    printf("----------------------------------------------------\n");
    printf("|  4. |%s  |%d    |%d  |\n",menu[3],prices[3],stock[3]);
    printf("----------------------------------------------------\n");
    printf("|  5. |%s     |%d    |%d  |\n",menu[4],prices[4],stock[4]);
    printf("----------------------------------------------------\n");
}
int takeOrder(){
    int input;
    char quantity[20];
    scanf("%d",&input);
    if(input==0){
        return 0;
    }
    else
    {
        scanf("%s",quantity);
        totalPrice += prices[input-1] * atoi(quantity);
        strcpy(order[j],menu[input-1]);
        j++;
        strcpy(order[j],quantity);
        j++;
        printf("item = %s, quantity = %s\n",order[j-2],order[j-1]);
        stock[input-1] = stock[input-1] - atoi(quantity);
        takeOrder();
    }
}
int displayOrder(){
    int i=0;
    printf("\n     Your Final Order     \n");
    while(strlen(order[i])!=0){
        printf("item = %s, quantity = %s\n",order[i],order[i+1]);
        i = i+2;
    }
    printf("Total Price = %d",totalPrice);
    printf("\n\n\nThank you for visiting our cafe");
    return 0;
}
void refreshOrderlist(){
    int i=0;
    while(strlen(order[i])!=0){
        strcpy(order[i],"xyz");
        i++;
    }
    j = 0;
    totalPrice = 0;
}