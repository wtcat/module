#include <stdint.h>

char buffer[300] = {"xxxxxxxxxxxxyxxxxxxxxxxxxxxxxxxxxxxxx0xxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};

int app_entry(int (*dbgfmt)(const char *fmt, ...)) {
    if (dbgfmt) {
        // dbgfmt("dynamic load successful!\n");
        buffer[0] = buffer[1] ^ buffer[50] ^ buffer[32];
        dbgfmt("%s", buffer);
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
