#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

#define MAX_VAL 1000

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size, num_values = 0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char filepath[100] = {0};
    int error_flag = 0;
    FILE *file = NULL;
    int *data = NULL;

    
    if (rank == 0) {
        printf("Enter binary file path: ");
        fflush(stdout); // Force prompt to show
        if (scanf("%99s", filepath) != 1) {
            fprintf(stderr, "Error reading input\n");
            error_flag = 1;
        }
    }

    //  Share file path and error flag with all processes
    MPI_Bcast(&error_flag, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (error_flag) {
        MPI_Finalize();
        return 1;
    }

    MPI_Bcast(filepath, 100, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Rank 0 opens file and reads data
    if (rank == 0) {
        file = fopen(filepath, "rb");
        if (!file) {
            perror("Error opening file");
            error_flag = 1;
        }
    }

    // Share open status with everyone
    MPI_Bcast(&error_flag, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (error_flag) {
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);

        num_values = file_size / sizeof(int);
        data = (int *)malloc(file_size);

        if (!data || fread(data, sizeof(int), num_values, file) != num_values) {
            fprintf(stderr, "Error reading file\n");
            fclose(file);
            free(data);
            MPI_Finalize();
            return 1;
        }

        fclose(file);

        // Optional: Validate chunk divisibility
        if (num_values % size != 0) {
            fprintf(stderr, "Number of values (%d) must be divisible by number of processes (%d)\n", num_values, size);
            free(data);
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
    }

    // Share value count
    MPI_Bcast(&num_values, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Distribute data
    int chunk_size = num_values / size;
    int *local_data = (int *)malloc(chunk_size * sizeof(int));
    MPI_Scatter(data, chunk_size, MPI_INT, local_data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Count locally
    int local_count[MAX_VAL] = {0};
    for (int i = 0; i < chunk_size; i++) {
        local_count[local_data[i]]++;
    }

    // Reduce to global count
    int global_count[MAX_VAL] = {0};
    MPI_Reduce(local_count, global_count, MAX_VAL, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Rank 0 writes back sorted data
    if (rank == 0) {
        int index = 0;
        for (int i = 0; i < MAX_VAL; i++) {
            for (int j = 0; j < global_count[i]; j++) {
                data[index++] = i;
            }
        }

        file = fopen(filepath, "wb");
        if (!file) {
            perror("Error writing file");
            free(data);
            MPI_Finalize();
            return 1;
        }

        fwrite(data, sizeof(int), num_values, file);
        fclose(file);
        free(data);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}

