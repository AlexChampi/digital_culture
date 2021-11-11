#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define max(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

struct period {
    int counter;
    char request[500];
};

int convertToMonth(char first, char second, char third) {
    switch (first) {
        case 'J':
            switch (second) {
                case 'a':
                    return 0; //jan
                case 'u':
                    switch (third) {
                        case 'n':
                            return 5;
                        case 'l':
                            return 6;
                    }
            }
        case 'F':
            return 1;
        case 'M':
            switch (third) {
                case 'r':
                    return 2;
                case 'y':
                    return 4;
            }
        case 'A':
            switch (second) {
                case 'p':
                    return 3;
                case 'u':
                    return 7;
            }
        case 'S':
            return 8;
        case 'O':
            return 9;
        case 'N':
            return 10;
        case 'D':
            return 11;


    }
}

unsigned long long convert(char *string, int left) {
    unsigned long long result;
    left = left + 2;
    int i = left;
//    while (string[i] != ']'){
//        printf("%c", string[i++]);
//    }

    int days = (string[left++] - '0') * 10 + (string[left++] - '0');
    left++;

    char monthFirstLetter = string[left++];
    char monthSecondLetter = string[left++];
    char monthThirdLetter = string[left++];
    left++;
    int monthInInt = convertToMonth(monthFirstLetter, monthSecondLetter, monthThirdLetter);

    int year = ((string[left++] - '0') * 1000 + (string[left++] - '0') * 100 + (string[left++] - '0') * 10 +
                (string[left++] - '0')) % 1900;
    left++;

    int hours = (string[left++] - '0') * 10 + (string[left++] - '0');
    left++;

    int minutes = (string[left++] - '0') * 10 + (string[left++] - '0');
    left++;

    int seconds = ((string[left++] - '0') * 10 + (string[left++] - '0'));
    left++;
    //printf("\n%d, %d, %d, %d\n", days, hours, minutes, seconds);
    result = seconds + minutes * 60 + hours * 3600 + (days - 1) * 86400;
    return result;
}

int main() {
    FILE *inputData, *outputData;
    inputData = fopen("C:\\Games\\access_log_Jul95", "r");
    outputData = fopen("C:\\Games\\result.txt", "w");

    int leftBorder, rightBorder;
    int counter = 0;
    int requestCounter = 0;
    char string[500];

    int time;
    scanf("%d", &time);

    while (fgets(string, 500, inputData) != NULL) {

        requestCounter++;
        leftBorder = 0;
        rightBorder = sizeof(string) / sizeof(string[0]) - 1;

        while (string[rightBorder--] != '"');
        while (string[leftBorder++] != '"');

        if (string[rightBorder + 3] == 53) {
            char result[500];
            char data;
            counter++;


            for (int j = 0; j < 500; ++j) {
                result[j] = 0;
            }

            result[200] = 10;
            for (int j = 0; (j < sizeof(result) / sizeof(result[0])) && (leftBorder <= rightBorder); ++j) {
                result[j] = string[leftBorder++];
            }
        }

    }

    int *queue = (long *) (long) malloc(sizeof(long) * requestCounter);
    fseek(inputData, 0, SEEK_SET);



}