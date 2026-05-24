// main_coordinator.c – Pipes data through sluice1, sluice2, sluice3
// Compile: gcc main_coordinator.c -o coordinator

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *pipe1, *pipe2;
    char buffer[1024];
    size_t bytes;

    // Open pipe to sluice1 (pattern matching)
    pipe1 = popen("./backend/sluice1", "w");
    if (!pipe1) {
        fprintf(stderr, "Failed to start sluice1\n");
        return 1;
    }

    // Read stdin and send to sluice1
    while ((bytes = fread(buffer, 1, sizeof(buffer), stdin)) > 0) {
        fwrite(buffer, 1, bytes, pipe1);
    }
    pclose(pipe1);

    // Now pipe through sluice2 and sluice3 (simplified – in real use chain them)
    pipe2 = popen("./backend/sluice2 | ./backend/sluice3", "r");
    if (!pipe2) {
        fprintf(stderr, "Failed to start sluice2/sluice3\n");
        return 1;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), pipe2)) > 0) {
        fwrite(buffer, 1, bytes, stdout);
    }
    pclose(pipe2);

    return 0;
}
