//heuristic function
//greedy best-first search:
//Expand the node that has the lowest value of the heuristic function h(n)
//a* search:
//f(n) estimates the total cost of the path from the initial state through node n to the goal
//g(n) cost from initial state to n
//h(n) cost from n to goal(heuristic value)
//f(n)=g(n)+h(n)

//multiple threads
//basic utilization in CPU
//int main()-> main thread
//scanf-> idle
//bubble sort()/swap()-> worker threads

//try adding more threads(should reduce the time)

#include <stdio.h>
#include <pthread.h>

//function that each thread will run.
//the thread function should return pointer to a void and accept arguments also pointed to a void 
void *computation(void *num){

}

int main(){

    long value1=1; value2=2;

    computation((void*)&value1);
    computation((void*)&value2);

    pthread_t thread1;
    pthread_t thread2;

    //to create threads, we use pthread_create();
    //pthread_create(pthread_t *thread, pthread_args_t *args, void *thread_function, void *thread_function_args);

    pthread_create(&thread1, NULL, computation, (void*)&value1);
    pthread_create(&thread2, NULL, computation, (void*)&value2);

    //join the threads
    //pause the main thread until the worker threads finish execution.
}

void *computation(void *num){
    long *mynum = (long *)num;
    long sum;
    for(int i=0; i<1000000000; i++){
        sum+=*mynum;
    }
}

//thread function for each thread to run and display it's thread id
void *helloworld(void *id){
    long *myid = (long *)id;
    printf("Im thread %ld \n", *myid);
    return NULL;
}

//create a more dynamic way to create threads
int main(int argc, char *argv[]){
    //nthreads = number of threads
    long nthreads = strtol(argv[1], NULL, 10);

    //creating thread arrays
    pthread_t *thread_array;
    thread_array = malloc(nthreads * sizeof(pthread_t));

    //creating thread ids
    long *thread_ids;
    thread_ids = malloc(nthreads * sizeof(long));

    //create the worker threads
    for (int i=0; i<nthreads; i++){

        thread_ids[i]=i;
        pthread_create(&thread_array[i], NULL, helloworld, &thread_ids[i]);

    } 

    //join the threads
     for (int i=0; i<nthreads; i++){

        pthread_join(thread_array[i], NULL);

    } 

}

//scalar multiplication
long *array, length, s, nthreads;

//thread function
void *scalar(void *id){
    long *myid = (long *)id;

    //calculate the chunk of array that each thread is responsible to run
    long chunk = length/nthreads;

    long start = (*myid) * chunk;

    long end - start + chunk;

    //perform the scalar multiplication
    for(in i=start; i<end; i++){
        array[i] *= s;
    }


}

int main(int argc, char *argv[]){
        pthread_t *thread_array;
        long *thread_ids;

        //parsing tbe commandline args for nthreads, length, s
        nthreads = strtol(argv[1], NULL, 10);
        length = strtol(argv[2], NULL, 10);
        s = strtol(argv[3], NULL, 10);


        //allocate memory for array, thread_array, thread_ids
        array = (long *)malloc(length * sizeof(long));
        thread_array = malloc(nthreads * sizeof(pthread_t));
        thread_ids = malloc(nthreads * sizeof(long));

        //initialize the array
        for(int i=0; i<length; i++){
            array[i] = i;

        }


        //create threads
        for(int i=0; i<nthreads; i++){
            pthread_create(&thread_array[i], NULL, scalar, &thread_ids[i]);
        
        }

        //join the threads
        for(int i=0; i<nthreads; i++){
            pthread_join(thread_array[i], NULL);
        
        }

        //print the values
        for(int i=0; i<length; i++){
            printf("%4ld", array[i]);
        }


        //free memory
        free(array);
        free(thread_array);
        free(thread_ids);
}