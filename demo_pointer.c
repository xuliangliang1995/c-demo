//
// Created by 许良 on 2021/2/13.
//
#include <generic_ext.h>
#include <stdio.h>

int main() {
    // 左值（内存空间） = 右值 （赋给内存空间的值）
    int int_val = 10;
    int *p = &int_val;
    int **pp = &p;

    Printlnf("int_val 的值 ： %d", int_val);
    Printlnf("int_val 地址 ： %x", &int_val);
    Printlnf("*p 指向地址 ：%x", p);
    Printlnf("*p 指向地址的值 ： %d", *p);
    Printlnf("**pp 指向地址 ： %x", pp);
    Printlnf("**pp 指向地址的值 ：%x", *pp);
    Printlnf("**pp 指向的地址的指针指向的地址的值 ： %d", **pp);
    Printlnf("**pp[%x] ==> *p[%x] ==> int_val[%x] : %d", pp, p, &int_val, int_val);

    int *const p_int_val = &int_val; // const 修饰的是指针 而非指针指向地址的变量
    // cp = 0x6; // Error
    *p_int_val = 6; // OK，
    Printlnf("int_val 的值 ： %d", int_val);

    int const *const p_mock = 0x5; // const 既修饰了指针，也修饰了指针指向的变量
    // cp2 = 0x6; // Error
    // *cp2 = 7; // Error

    int *p_null = NULL; // NULL 为 0， 0 指针有特殊的含义
    // *p_null = 6; // Error

    // !!! 野指针无意义时要置为 NULL

    return 0;
}

