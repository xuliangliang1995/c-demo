#include <stdio.h>

/**
 * 打印华氏温度与摄氏温度对照表  ℃ = （5 / 9）(℉ - 32)
 * @return
 */
int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("\tfahr\tcelsius\n");
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("\t%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

}