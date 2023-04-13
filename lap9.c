#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
typedef struct
{
    char name[50];
    unsigned long long int phone;
} Shop;

Shop shops[10];

typedef struct
{
    unsigned int code;
    unsigned int year;
    Shop shop;
    struct Price
    {
        char currency[10];
        float amount;
    } price;
    union Size
    {
        int digit;
        char letter;
        char word[50];
    } size;
    int sizetype;
} Clothing;

Clothing clothes[10];
int shopcount = 0, clothesCount = 0;
int main()
{
    Shop shop1 = {"Inteli-J Enterprise", 233549545530};
    Shop shop2 = {"Salim's Enterprise", 233556677889};
    shops[0] = shop1;
    shops[1] = shop2;
    shopcount = 2;
    Clothing clothe1 = {.sizetype = 3, .size.letter = 'L', .size.word = "BLACK JEANS", .shop.phone = shop1.phone, .code = 4356, .year = 2019, .price.currency = "USD", .price.amount = 90};
    Clothing clothe2 = {.sizetype = 3, .size.letter = 'M', .size.word = "SWEAT PANTS", .shop.phone = shop1.phone, .code = 4366, .year = 2020, .price.currency = "EUR", .price.amount = 100};
    Clothing clothe3 = {.sizetype = 3, .size.letter = 'S', .size.word = "LACOSTE TOP", .shop.phone = shop1.phone, .code = 4376, .year = 2021, .price.currency = "BPS", .price.amount = 120};
    Clothing clothe4 = {.sizetype = 3, .size.letter = 'L', .size.word = "ARARE SHIRT", .shop.phone = shop2.phone, .code = 5028, .year = 2021, .price.currency = "CFA", .price.amount = 150};

    clothes[0] = clothe1;
    clothes[1] = clothe2;
    clothes[2] = clothe3;
    clothes[3] = clothe4;
    clothesCount = 4;

    int looping = 0;
    do
    {
        printf("CLOTHING MALL\n1.Visit Shop\t2.Add Clothing\t3.Exit\n");
        int option;
        scanf(" %d", &looping);
        switch (looping)
        {
        case 1:
            showShops();
            scanf(" %d", &option);
            showDetails(option - 1);
            showClothes(option - 1);
            break;
        case 2:
            addClothing();
            break;
        case 3:
            looping = 0;
            printf("Thanks for shopping :)");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (looping > 0);

    return 0;
}

void showShops()
{
    printf("Shops available:\n");
    for (int i = 0; i < shopcount; i++)
    {
        printf("%d. %s\n", i + 1, shops[i].name);
    }
}

void showDetails(int index)
{
    printf("Shop Details:\n");
    printf("Name: %s\n", shops[index].name);
    printf("Phone: %llu\n", shops[index].phone);
}

void showClothes(int index)
{
    printf("Clothes available:\n");
    for (int i = 0; i < clothesCount; i++)
    {
        if (clothes[i].shop.phone == shops[index].phone)
        {
            printf("%d. %s\n", i + 1, clothes[i].size.word);
        }
    }
}

void addClothing()
{
    printf("Enter shop name:\n");
    char shopname[50];
    scanf(" %s", shopname);
    Shop shop;
    strcpy(shop.name, shopname);
    printf("Enter shop phone:\n");
    scanf(" %llu", &shop.phone);
    shops[shopcount] = shop;
    shopcount++;
    printf("Enter clothing code:\n");
    scanf(" %d", &clothes[clothesCount].code);
    printf("Enter clothing year:\n");
    scanf(" %d", &clothes[clothesCount].year);
    printf("Enter clothing price:\n");
    scanf(" %f", &clothes[clothesCount].price.amount);
    printf("Enter clothing currency:\n");
    scanf(" %s", clothes[clothesCount].price.currency);
    printf("Enter clothing size:\n");
    scanf(" %d", &clothes[clothesCount].sizetype);
    if (clothes[clothesCount].sizetype == 1)
    {
        scanf(" %d", &clothes[clothesCount].size.digit);
    }
    else if (clothes[clothesCount].sizetype == 2)
    {
        scanf(" %c", &clothes[clothesCount].size.letter);
    }
    else
    {
        scanf(" %s", clothes[clothesCount].size.word);
    }
    clothes[clothesCount].shop = shop;
    clothesCount++;
}