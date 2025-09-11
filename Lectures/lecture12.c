//Semaphores, Mutexes, Count Sort with Multi-Threads

//Example
//Consider an array A[] = {4, 2, 2, 8, 3, 3, 1}
//Step 1: Get the max value and number of elements
//0-8 range
//k=8; max
//n=7; number of elements
//step 2: create a new array like count to store the frequency ->intialize the count array with all zeros
//int* count = (int *)calloc(k+1, sizeof(int))
//count = {0,0,0,0,0,0,0}
//count sort(non-comparison)->sort the values according to keys 
//for a given array, we find the frequency/occurence of each element and enumerate the frequency
//step 3:enumerate the frequency

//single threaded version of count sort
//void count_elements(int *array, int *count, length){
 //   for(int i=0; i<length; i++){
  //      int index = array[i];
   //     count[index] = count[index] + 1;
    //}
//}

//to create a multi-threaded version of count sort:
long *array, *count; //shared across all the threads
p_thread_mutex_t mymutex;
void *count_elems(void *id){
    long *myid = (long *)id;
    long *local_count[length]; //private to each thread

    long chunk = length/nthreads
    long start = *myid * chunk;
    long end = start + chunk;

    if(*myid == nthreads -1){
        end = length;
    
    }

    //find the frequency:
    //this version of the code is still serial, there is no speed up in the program
    //the computation is serial
    pthread_mutex_lock(&mymutex);
    for(int i=start; i<end; i++){
        int index = array[i];
        local_array[index]++;
    }
    pthread_mutex_unlock(&mymutex);

    //write the frequency back to global count from the local
    for(int i=0; i<length; i++){
        pthread_mutex_lock(&mymutex);
        count[i] = local_count[i];
        pthread_mutex_unlock(&mymutex);
    }

    //this version, the maximum computation is done in parallel
    
}