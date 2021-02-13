//
// Created by 许良 on 2021/2/12.
//
#include <stdio.h>
#include <tempuration_conversion.h>

/**
 * 华氏 => 摄氏
 * @return
 */
int Fahr2Celsius(int fahr) {
    return 5 * (fahr - 32) / 9;
}

/**
 * 打印 华氏 => 摄氏对照表
 * @return
 */
int PrintFahr2CelsiusMappingTable(void) {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("\tfahr\tcelsius\n");
    while (fahr <= upper) {
        celsius = Fahr2Celsius(fahr);
        printf("\t%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
