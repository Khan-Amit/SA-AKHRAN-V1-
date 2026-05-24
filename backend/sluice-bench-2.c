// sluice-bench-2.c – Tier 2: Stateful inspection (rate limiting)
// Compile: gcc sluice-bench-2.c -o sluice2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define RATE_LIMIT 100

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned long total = 0, accepted = 0;
    time_t start = time(NULL);

    while ((read = getline(&line, &len, stdin)) != -1) {
        total++;
        time_t now = time(NULL);
        if (now - start < 1 && total > RATE_LIMIT) {
            continue;
        }
        fwrite(line, 1, read, stdout);
        accepted++;
        if (now - start >= 1) {
            start = now;
            total = 0;
        }
    }
    fprintf(stderr, "Tier2 | Total: %lu | Accepted: %lu | Rejected: %.2f%%\n",
            total, accepted, (1 - (double)accepted/total)*100);
    free(line);
    return 0;
}
