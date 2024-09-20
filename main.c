/*
 * Copyright 2024 wtcat
 */
#define MODULE_LOADABLE
#include "basework/module.h"

static int test_init(const struct module_class *mod) {
    (void) mod;
    return 0;
}

static int test_exit(const struct module_class *mod) {
    (void) mod;
    return 0;
}

module_install(test_init, test_exit);
