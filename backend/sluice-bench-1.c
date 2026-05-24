// sluice-bench-1.c – Tier 1: Pattern matching (egg‑sorter)
// Compile: gcc sluice-bench-1.c -o sluice1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_ripe(const char *line) {
    if (strlen(line) < 10) return 0;
    // Add your pattern logic here
    return 1;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long total = 0, accepted = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        total++;
        if (is_ripe(line)) {
            fwrite(line, 1, read, stdout);
            accepted++;
        }
    }
    fprintf(stderr, "Tier1 | Total: %lu | Accepted: %lu | Rejected: %.2f%%\n",
            total, accepted, (1 - (double)accepted/total)*100);
    free(line);
    return 0;
}
