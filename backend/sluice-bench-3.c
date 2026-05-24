// sluice-bench-3.c – Tier 3: Total isolation mode
// Compile: gcc sluice-bench-3.c -o sluice3

#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long total = 0;

    while ((read = getline(&line, &len, stdin)) != -1) {
        total++;
        // Isolation: block everything
        continue;
    }
    fprintf(stderr, "Tier3 | Total: %lu | Accepted: 0 | Rejected: 100.00%%\n", total);
    free(line);
    return 0;
}
