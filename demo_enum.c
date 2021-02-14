//
// Created by 许良 on 2021/2/14.
//
#include <generic_ext.h>

int main() {
    enum PicFormat {PNG, JPEG, BMP};
    Printlnf("%d", PNG);
    Printlnf("%d", JPEG);
    Printlnf("%d", BMP);

    enum PicFormat format = PNG;
    enum PicFormat format_2 = 5; // C  语言没有限制枚举的赋值（相信程序员）

    return 0;
}

