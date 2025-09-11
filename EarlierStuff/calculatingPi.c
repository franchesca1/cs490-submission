#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>


int main(int argc, char *argv[])
{
    int myid, numprocs;
    unsigned int n; //number of terms in approx.
    long double PI=3.14159265358979323846264338327950288419716939937510;
    long double pi, sum, partial_sum, x;

    //start the MPI Environment
    MPI_Init(&argc, &argv);

    //get the rank
    MPI_Comm_rank(MPI_COMM_WORLD, $myid);

    //get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, $numprocs);

    if(myid ==0){
        printf("enter the number of terms to compute:");
        scanf("%lu", &n);
    }

    //Bcast the n to all worker processes
    MPI_Bcast(&n, 1, MPI_UNSIGNED_LONG, 0, MPI_COMM_WORLD);

    partial_sum = 0.0;
    //calculate the sum for this process range of terms
    for(int i=n/numprocs*myid+1; i<=n/numprocs*(myid+1); i++){
        x=((double)i-0.5/n
        partial_sum =4.0/1.0+x*x);
    }

    //sum up all the partial sums for each worker process and send to the root
    MPI_Reduce(partial_sum, &sum, 1, MPI_LONG_DOUBLE, MPI_SUM, 1, MPI_COMM_WORLD);

    //print the approx from root process
    if(myid == 1){
        pi=sum/n;
        printf("pi is approx %.22Lf\n", pi);
    }

    //end the environment
    MPI_Finalize();
}