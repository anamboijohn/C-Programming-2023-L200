#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStar();
int main()
{
    int order=0, time=0, toppings=0;
    float cost = 0;
    char *flavours[] = {"Vanilla", "Strawberry", "Chocolate", "Mango"};
    char *toppings_str[] = {"Sprinkles", "Whipped Cream", "Chopped Nuts", "Coconut Shavings"};
    char *sizes[] = {"Small", "Large"};
    int topping_prices[] ={2, 3, 4, 5};
    int small_prices[] = {5, 5, 6, 7};
    int large_prices[] = {8, 8, 9, 10};
   printf("\n\n\tWELCOME TO FIIFI\'S ICE CREAM SHOP\n\tWhat would you like to order?\n\n");

   do{
    int flavour, size;

    printStar();
    printf("\nFLAVOURS MENU\n");
    printStar();
    printf("\n\n1 - Vanilla\n2 - Strawberry\n3 - Chocolate\n4 - Mango\n5 -Enquiries\n");
    printf("Please Select Flavour: ");
    scanf("%d", &flavour); flavour--;
    printf("\n");

    if(flavour == 4) printf("A customer service agent will be with you soon\n");
    else if(flavour>4){
        printf("\nInvalid Flavour Entry\n");
    }else{
    printStar();
    printf("\nSIZES MENU\n");
    printStar();
    printf("\n\n1 - Small\n2 - Large\nSelect Size: ");
    scanf("%d", &size); size--;
    }

    if(flavour < 4){
        if(size < 2){
            printf("\nYour Selected flavour: %s\n\n", flavours[flavour]);
            printf("Your Selected size: %s\n\n", sizes[size]);

            if(size == 0){ cost += small_prices[flavour]; time += 2;};
            if(size == 1){ cost += large_prices[flavour]; time += 3;};


        } else{
            printf("Invalid Size Entry\n"); break;
        }
    }

    do{
            int topping;
            printStar();
            printf("\nTOPPINGS MENU\n");
            printStar();
            printf("\n1 - Sprinkles\n2 - Whipped Cream\n3 - Chopped Nuts\n4 - Coconut Shavings\n5 - Exit Topping Menu");
            printf("\nPlease Select Topping: ");
            scanf("%d", &topping); topping--;

            if(topping > 4) printf("Invalid Topping Entered\n");

            else if(topping < 4){
                printf("\nYour selected topping is: %s\n", toppings_str[topping]);


                cost += topping_prices[topping];

                //Lets Assume that the waiting time is the same as the price but in minutes;

                time += topping_prices[topping];
                toppings++;
            }else if(topping == 4) toppings = 0;
    }while(toppings > 0 );

    printStar();
    printf("\nFurther Enquiries Menu\n");
    printStar();

    printf("\nWould you like anything else?\n1 - Yes\n2 - No\n");
    printf("Slect: ");
    int more;
    scanf("%d", &more);
    if(more == 1) order++;
    else if(more==2){
            order = 0;
            printStar();
            printf("\nYour Total Cost is GHC%.2f\n This will take %dmin to prepare\n", cost, time);
            printStar();
    } else {printf("\nInvalid!");};


   }while(order>0);

   printf("\n Kindly Wait for Your Order.\n\n");

   //We are Just assuming that a minute is 10s seconds;
   int timeS = 10*time;

   for(timeS; timeS>0; timeS--){
    printf("Your order will be ready in %ds\n", timeS);
    for(int j = 0; j<100000000; j++){
    }
   }

    char msg[] = "\nTime Up!\nHolala!!! Order Coming Right Up!\n";
    printStar();
    for(int i=0; msg[i] != NULL; i++){
        printf("%c", msg[i]);
        for(int j=0; j<10000000; j++){
        }
    }
    printStar();
    return 0;
}

void printStar(void){
            for(int i=0; i<10; i++){
                printf("****");
                for(int j=0; j<10000000; j++){

                }
            }
            return 0;
}
