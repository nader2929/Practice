#include <stdio.h>
#include <stdlib.h>

void one_to_nineteen_to_text(long number){
    switch (number)
    {
        case 1:
            printf("One");
            break;
        case 2:
            printf("Two");
            break;
        case 3:
            printf("Three");
            break;
        case 4:
            printf("Four");
            break;
        case 5:
            printf("Five");
            break;
        case 6:
            printf("Six");
            break;
        case 7:
            printf("Seven");
            break;
        case 8:
            printf("Eight");
            break;
        case 9:
            printf("Nine");
            break;
        case 10:
            printf("Ten");
            break;
        case 11:
            printf("Eleven");
            break;
        case 12:
            printf("Twelve");
            break;
        case 13:
            printf("Thirteen");
            break;
        case 14:
            printf("Fourteen");
            break;
        case 15:
            printf("Fifteen");
            break;
        case 16:
            printf("Sixteen");
            break;
        case 17:
            printf("Seventeen");
            break;
        case 18:
            printf("Eighteen");
            break;
        case 19:
            printf("Nineteen");
            break;
        default:
            break;
    }
}

void tens_to_text(long number){
    switch (number)
    {
        case 2:
            printf("Twenty");
            break;
        case 3:
            printf("Thirty");
            break;
        case 4:
            printf("Forty");
            break;
        case 5:
            printf("Fifty");
            break;
        case 6:
            printf("Sixty");
            break;
        case 7:
            printf("Seventy");
            break;
        case 8:
            printf("Eighty");
            break;
        case 9:
            printf("Ninety");
            break;
        default:
            break;
    }
}

void remainder_text(long number){
    long number_hundreds = number / 100;
    long number_tens = (number - (number_hundreds*100)) / 10;
    long number_digits = number - (number_hundreds*100) - (number_tens * 10);
    one_to_nineteen_to_text(number_hundreds);
    if (number_hundreds > 0) printf(" Hundred ");
    if (number_tens > 1) tens_to_text(number_tens);
    else if (number_tens == 1 && number_digits > 0){
        one_to_nineteen_to_text(number_digits+10);
    }

    if (number_tens != 1 && number_digits > 0) {
        printf(" ");
        one_to_nineteen_to_text(number_digits);
    }
}

void convert_number(long num){
    printf("Number: %ld\n", num);
    if (num == 0){
        printf("Zero");
    }
    else if (num < 0){
        num = num * -1;
        printf("Minus ");
    }

    long billion_remainder = num / 1000000000;
    if(billion_remainder > 0)
    {
        remainder_text(billion_remainder);
        printf(" Billion ");
    }

    long million_remainder = (num - (billion_remainder*1000000000)) / 1000000;
    if(million_remainder > 0)
    {
        remainder_text(million_remainder);
        printf(" Million ");
    }

    long thousand_remainder = (num - (billion_remainder*1000000000) - (million_remainder*1000000)) / 1000;
    if(thousand_remainder > 0)
    {
        remainder_text(thousand_remainder);
        printf(" Thousand ");
    }

    long hundred_remainder = (num - (billion_remainder*1000000000) - (million_remainder*1000000) - (thousand_remainder*1000)) / 100;
    if(hundred_remainder > 0)
    {
        one_to_nineteen_to_text(hundred_remainder);
        printf(" Hundred ");
    }

    long tens_remainder = (num - (billion_remainder*1000000000) - (million_remainder*1000000) - (thousand_remainder*1000) - (hundred_remainder*100)) / 10;
    if(tens_remainder > 1)
    {
        tens_to_text(tens_remainder);        
    }

    long single_digit = (num - (billion_remainder*1000000000) - (million_remainder*1000000) - (thousand_remainder*1000) - (hundred_remainder*100));
    if(single_digit > 0)
    {
        if (single_digit > 19) {
            single_digit = single_digit - (tens_remainder*10);
            printf(" ");
        }
        one_to_nineteen_to_text(single_digit);        
    }

    if(tens_remainder == 1 && single_digit == 0){
        printf(" Ten");
    }
}

int main(int argc, char **argv){
    int c;
    long num;
    char *temp;
    if(argc != 2){
        printf("Please give a number from -2 billion up to 2 billion\n");
        return 1;
    }

    num = strtol(argv[1], &temp, 10);

    convert_number(num);

    printf("\n");

}