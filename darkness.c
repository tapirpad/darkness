#include <stdio.h>
#include <stdlib.h>

#define BRIGHTNESS_MIN 0
#define BRIGHTNESS_MAX 1060
#define BRIGHTNESS_FILE "/sys/class/backlight/intel_backlight/brightness"

int main(int argc, char **argv) {

    // Check if argument is given
    if (argc < 2) {
        fputs("ERROR: No argument is given\n", stderr);
    }

    FILE *fp = fopen(BRIGHTNESS_FILE, "r");

    // Validate file open for reading
    if (!fp) {
        perror("ERROR");
        exit(EXIT_FAILURE);
    }

    // Read and validate int
    int bright_val;
    if (fscanf(fp, "%d", &bright_val) != 1) {
        fputs("ERROR: Invalid file format, integer not first\n", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    // Compute new brightness value and check bound
    bright_val -= atoi(argv[1]);
    if (bright_val < BRIGHTNESS_MIN) {
        bright_val = BRIGHTNESS_MIN;
    }
    if (bright_val > BRIGHTNESS_MAX) {
        bright_val = BRIGHTNESS_MAX;
    }

    // Apply changes
    fp = fopen(BRIGHTNESS_FILE, "w");
    fprintf(fp, "%d", bright_val);
    fclose(fp);

    return 0;
}
