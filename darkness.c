#include <stdio.h>
#include <stdlib.h>

#define BRIGHTNESS_FILE "/sys/class/backlight/intel_backlight/brightness"
// #define BRIGHTNESS_FILE "./brightness"

int main(int argc, char **argv) {

    // Check if argument is given
    if (argc < 2) {
        fputs("[ERROR]: no argument is given.\n", stderr);
    }

    FILE *fp = fopen(BRIGHTNESS_FILE, "r");

    // Validate file open for reading
    if (!fp) {
        perror("[ERROR]: fopen-file");
        exit(EXIT_FAILURE);
    }

    // Read and validate int
    int bright_val;
    if (fscanf(fp, "%d", &bright_val) != 1) {
        fputs("[ERROR]: invalid file format, integer not first.\n", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    // printf("============================================\n");
    // printf("original brightness =  %d\n", bright_val);
    // printf("argc =  %d\n", argc);
    // printf("argv =  %s\n", argv[1]);
    // printf("argv int =  %d\n", atoi(argv[1]));
    // printf("current brightness =  %d\n", bright_val+atoi(argv[1]));
    // printf("============================================\n");

    fp = fopen(BRIGHTNESS_FILE, "w");
    fprintf(fp, "%d", bright_val + atoi(argv[1]));
    fclose(fp);

    return 0;
}
