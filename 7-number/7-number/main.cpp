//
//  main.cpp
//  7-number
//
//  Created by FlyElephant on 2019/1/3.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Search.cpp"

#define maxsize 100
int *convertToBinary(int num) {
    int *arr = (int *)malloc(sizeof(int) * maxsize);
    int p = num;
    int i = 0;
    while (p > 0) {
        int t = p % 2;
        *(arr+i) = t;
        p = p / 2;
        i++;
    }
    return arr;
}

int countBinaryNum(int num) {
    int count = 0;
    int p = num;
    while (p > 0) {
        int mod = p % 2;
        if (mod == 1) {
            count++;
        }
        p = p / 2;
    }
    return count;
}

int numof1(int num) {
    int flag = 1;
    int count = 0;
    int n = num;
    while (flag) {
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int numof1_2(int num) {
    int count = 0;
    int n = num;
    while (n) {
        if (n & 1) { //  位运算
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int numof1_3(int num) {
    int n = num;
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

bool isEvenNumber(int num) {
    return num & (num - 1) ? false : true;
}

// change from num1 to num2
int numOfPositions(int num1,int num2) {
    int res = num1 ^ num2;
    int count = 0;
    while (res) {
        res = res & (res - 1);
        count++;
    }
    return count;
}

//  打印1到最大的n位数

bool increasecharNumber(char *number) {
    bool isOverflow = false; // 判断是否越界
    int carry = 0; // 进位
    int len = (int)strlen(number);
    for (int i = len - 1; i >=0; i--) {
        int cur = *(number+i) - '0' + carry;
        if (i == len - 1) {
            cur = cur + 1;
        }
        if (cur == 10) {
            if (i == 0) {
                isOverflow = true; // 已经达到最大值
            } else {
                carry = 1;
                *(number+i) = cur % 10 + '0';
            }
        } else {
            carry = 0;
            *(number+i) = cur + '0';
        }
    }
    return isOverflow;
}

void printNumber(char *number) {
    int len = (int)strlen(number);
    int isBegin = false;
    for (int i = 0; i < len; i++) {
        char cur = *(number+i);
        if (cur != '0' && !isBegin) {
            isBegin = true;
        }
        if (isBegin) {
            printf("%c",cur);
        }
    }
    printf("\n");
}

void printMaxOfDigits(int n) {
    char *number = (char *)malloc(sizeof(char) * (n+1));
    for (int i = 0; i < n; i++) {
        *(number+i) = '0';
    }
    *(number+n) = '\0';
    while (!increasecharNumber(number)) {
        printNumber(number);
    }
}


int main() {
    int num = 9;
    int *res = convertToBinary(num);
    for (int i = 0; i < 10; i++) {
        int t = *(res+i);
        printf("current value:%d\n",t);
    }
    int p = 9;
    int count = countBinaryNum(p);
    printf("%d中1的个数:%d\n",p,count);
    int num1 = numof1(0x1001);
    printf("1--%d中1的个数:%d\n",p,num1);
    int num2 = numof1_2(p);
    printf("1--%d中1的个数:%d\n",p,num2);
    int num3 = numof1_3(p);
    printf("1--%d中1的个数:%d\n",p,num3);
    bool isEven = isEvenNumber(9);
    if (isEven) {
        printf("even number\n");
    } else {
        printf("is not even number\n");
    }
    int positions = numOfPositions(10, 13);
    printf("change from 10 to 13 need chage %d position\n",positions);
    printMaxOfDigits(3);
    Search search;
    search.test();
    return 0;
}
