#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to compare environment variable names
int env_name_cmp(const void *p1, const void *p2) {
    const char *entry1 = *(const char **)p1;
    const char *entry2 = *(const char **)p2;

    char key1[256], key2[256];
    sscanf(entry1, "%255[^=]", key1);
    sscanf(entry2, "%255[^=]", key2);

    return strcmp(key1, key2);
}

int main(int argc, char *argv[], char *envp[]) {
    int total = 0;

    // Count total environment variables
    while (envp[total]) {
        total++;
    }

    // Allocate buffer to hold the pointers
    char **env_list = malloc(sizeof(char *) * total);
    if (!env_list) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Copy pointers to the environment strings
    for (int j = 0; j < total; j++) {
        env_list[j] = envp[j];
    }

    // Sort based on the variable names
    qsort(env_list, total, sizeof(char *), env_name_cmp);

    // Print sorted environment variables
    for (int k = 0; k < total; k++) {
        puts(env_list[k]);
    }

    // Clean up
    free(env_list);

    return 0;
}


