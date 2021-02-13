#include <stdio.h>
#include <tempuration_conversion.h>
#include <generic_ext.h>

#define PRINTLNF(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINTLNF_PLUS(format, ...) printf("("__FILE__":%d) %s : "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define PRINT_INT(value) printf(#value": %d\n", value)

// __FILE__
// __LINE__
// __FUNCTION__

int main() {
    DebugPrint("start ..");
    Printlnf("%s", "print by function .");
    PRINTLNF("%s", "print by macro .");
    PRINTLNF_PLUS("print %d", 5);

    // PrintFahr2CelsiusMappingTable();

    PRINT_INT(3 + 4);

    DebugPrint("end ..");

    int int_array[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        Printlnf("%d", int_array[i]);
    }
    return 0;
}


