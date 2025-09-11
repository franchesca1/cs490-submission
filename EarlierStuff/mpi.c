#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
	int rank, size;

	//start the MPI environment
	MPI_Init(&argc, &argv);

	//get rank for each process
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	//MPI_COMM_WORLD refers to the group of processes attached to our program

	//get the total number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &size);	

	//print the ranks for each process
	printf("I'm rank %d of total %d \n", rank, size);

	//exit the environemt
	MPI_Finalize();

}