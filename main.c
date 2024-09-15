#include <stdint.h>

char buffer[300] = {"xxxxxxxxxxxxyxxxxxxxxxxxxxxxxxxxxxxxx0xxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};
static int test_array[] = {
    0x1234,
    0x4567,
    0xabcd,
    0xdeef,
    0xbc36,
    0x9678
};

int app_entry(int (*dbgfmt)(const char *fmt, ...)) {
    if (dbgfmt) {
        int temp = 0;
        // dbgfmt("dynamic load successful!\n");
        buffer[0] = buffer[1] ^ buffer[50] ^ buffer[32];
        for (int i = 0; i < sizeof(test_array)/sizeof(test_array[0]); i++) {
            temp ^= test_array[i];
            test_array[i] += temp;
        }
        dbgfmt("%s :%d", buffer, temp);
    }
    return 0;
}

struct module {
    uintptr_t magic;
    uintptr_t module_size;
    uintptr_t code_start;
    uintptr_t code_size;
    uintptr_t bss_start;
    uintptr_t bss_size;
};

extern char _module_end[];
extern char _stext[];
extern char _etext[];

struct module this_module __attribute__((section(".vectors")))= {
    .magic = 0x12345678,
    .module_size = (uintptr_t)_module_end,
    .code_start = (uintptr_t)_stext,
    .code_size = (uintptr_t)_etext
};
