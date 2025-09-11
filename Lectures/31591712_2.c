#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;

    // Parsing command-line options
    while ((opt = getopt(argc, argv, "cduf:s:")) != -1) {
        switch (opt) {
            case 'c':
                printf("Option -c\n");
                break;
            case 'd':
                printf("Option -d\n");
                break;
            case 'u':
                printf("Option -u\n");
                break;
            case 'f':
                printf("Option -f with argument: %s\n", optarg);
                break;
            case 's':
                printf("Option -s with argument: %s\n", optarg);
                break;
            case '?': // Handling unknown options or missing arguments
                if (optopt == 'f' || optopt == 's') {
                    fprintf(stderr, "Error: Option -%c requires an argument.\n", optopt);
                } else {
                    fprintf(stderr, "Error: Unknown option -%c.\n", optopt);
                }
                fprintf(stderr, "Usage: %s [-c] [-d] [-u] [-f fields] [-s char] input_file output_file\n", argv[0]);
                exit(EXIT_FAILURE);
                break;
            default:
                fprintf(stderr, "Unexpected error while parsing options.\n");
                exit(EXIT_FAILURE);
        }
    }

    // Print non-option arguments (operands)
    if (optind < argc) {
        printf("Operands:\n");
        for (int index = optind; index < argc; index++) {
            printf("  %s\n", argv[index]);
        }
    } else {
        fprintf(stderr, "Error: Missing input_file and/or output_file.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
