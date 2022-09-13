#include <stdio.h>
#include <stdlib.h>

char one_to_nineteen_to_text[20][20] = {
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
};

char tens_to_text[10][7] = {
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
};

void remainder_text(long number){
    long number_hundreds = number / 100;
    long number_tens = (number - (number_hundreds*100)) / 10;
    long number_digits = number - (number_hundreds*100) - (number_tens * 10);
    printf("%s", one_to_nineteen_to_text[number_hundreds]);
    if (number_hundreds > 0) printf(" Hundred ");
    if (number_tens > 1) printf("%s", tens_to_text[number_tens]);
    else if (number_tens == 1 && number_digits > 0){
        printf("%s", one_to_nineteen_to_text[number_digits+10]);
    }

    if (number_tens != 1 && number_digits > 0) {
        printf(" ");
        printf("%s", one_to_nineteen_to_text[number_digits]);
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
        printf("%s", one_to_nineteen_to_text[hundred_remainder]);
        printf(" Hundred ");
    }

    long tens_remainder = (num - (billion_remainder*1000000000) - (million_remainder*1000000) - (thousand_remainder*1000) - (hundred_remainder*100)) / 10;
    if(tens_remainder > 1)
    {
        printf("%s", tens_to_text[tens_remainder]);
    }

    long single_digit = (num - (billion_remainder*1000000000) - (million_remainder*1000000) - (thousand_remainder*1000) - (hundred_remainder*100));
    if(single_digit > 0)
    {
        if (single_digit > 19) {
            single_digit = single_digit - (tens_remainder*10);
            printf(" ");
        }
        printf("%s", one_to_nineteen_to_text[single_digit]);
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