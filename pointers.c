#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int num = 20;
    char *str[] = {"Store me pls", "And me too", "Yess do it"};
    char str2[] = "this is a str";
    float flt = 3.322;
    
    FILE *fp;
    fp = fopen("mydata.txt", "w");
    fprintf(fp, "num = %d\n", num);
    fprintf(fp, "str[0] = %s\n", str[0]);
    fprintf(fp, "str[1] = %s\n", str[1]);
    fprintf(fp, "str[2] = %s\n", str[2]);
    fprintf(fp, "str = %s\n", str2);
    fprintf(fp, "flt = %f\n", flt);
    fclose(fp);
    
    return 0;
}

// int arraySum(int *arr, const int n);
// void swap(int* x, int* y);
// int main(void){

//     int number = 55;
//     int n2 = 4;
//     const int *const pnumber = &number;

//     n2 = number;

//     printf(" this is a the pointer: %p.\nthis is the value: %d", pnumber, *pnumber);
//     printf("\n pnumber: %d\n number: %d", *pnumber, number);
    
//     int arr[]={1, 2, 3, 4};


//     int sum = arraySum(arr, sizeof(arr)/sizeof(arr[0]));

//     printf(" The sum of the array is: %d", sum);

//     int x = 10, y = 20;

//     printf("Before Swap: x-%d and y-%d\n", x, y);

//     swap(&x, &y);

//     printf("After Swap: x-%d and y=%d", x, y);
//     printf("size of int: %d\n size of char: %d\n size of float: %d\n size of double: %d\n size of long: %d", (int)sizeof(250), (int)sizeof("h"), (int)sizeof(float), (int)sizeof(double), (int)sizeof(long)); 
    
//     char *arr[] = {"this is John", "We are here"};

//     char **parr = arr;

//     printf("address of arr: %s\n address of parr: %s", *(arr+1), *(parr+1));
//     return 0;
// } 

// void swap(int* x, int* y){
//     int temp = *x;
//     *x = *y;
//     y=temp;
// }

// int arraySum(int *arr, const int n){
//     int sum = 0, *arrayEnd=arr + n;

//     for(; arr<arrayEnd; arr++){
//         sum += *arr;
//     }
//     return sum;
// }