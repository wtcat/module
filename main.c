
int app_entry(int (*dbgfmt)(const char *fmt, ...)) {
    if (dbgfmt)
        dbgfmt("dynamic load successful!\n");
    return 0;
}