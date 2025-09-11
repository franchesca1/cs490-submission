#include <stdio.h>
#include <ctype.h>
#include <stdint.h>  // For uintptr_t

// Function to display memory in hex and ASCII
void dump_memory(unsigned char *start, size_t length) {
    size_t offset, byte;

    for (offset = 0; offset < length; offset += 8) {
        printf("%p | ", (void *)(start + offset));

        // Print hex values
        for (byte = 0; byte < 8; byte++) {
            if (offset + byte < length) {
                printf("%02x ", start[offset + byte]);
            } else {
                printf("   ");
            }
        }

        printf("| ");

        // Print printable characters or placeholders
        for (byte = 0; byte < 8; byte++) {
            if (offset + byte < length) {
                unsigned char ch = start[offset + byte];
                if (isprint(ch)) {
                    printf("%c", ch);
                } else if (ch == '\0') {
                    printf("\\0");
                } else {
                    printf(".");
                }
            }
        }

        printf("\n");
    }
}

int main(int arg_count, char *arg_values[]) {
    int index;
    unsigned char *mem_start;

    // Print address of arg_values (i.e., argv)
    printf("arg_values   | %p\n", (void *)&arg_values);

    // Show individual argument addresses
    printf("\nPointer List:\n");
    for (index = 0; index < arg_count; index++) {
        printf("arg_values[%d] | %p\n", index, (void *)arg_values[index]);
    }

    // Starting from the first argument
    printf("\nMemory Dump of Arguments:\n");
    mem_start = (unsigned char *)arg_values[0];

    // Align to 8-byte boundary before start
    while ((uintptr_t)mem_start % 8 != 0) {
        mem_start--;
    }

    // Calculate end pointer after last argument
    unsigned char *mem_end = (unsigned char *)arg_values[arg_count - 1];
    while (*mem_end != '\0') {
        mem_end++;
    }
    mem_end++; // Include final null terminator

    while ((uintptr_t)mem_end % 8 != 0) {
        mem_end++;
    }

    // Dump the memory content
    dump_memory(mem_start, mem_end - mem_start);

    return 0;
}

