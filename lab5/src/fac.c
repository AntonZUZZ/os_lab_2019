/********************************************************
 * An example source module to accompany...
 *
 * "Using POSIX Threads: Programming with Pthreads"
 *     by Brad nichols, Dick Buttlar, Jackie Farrell
 *     O'Reilly & Associates, Inc.
 *  Modified by A.Kostin
 ********************************************************
 * mutex.c
 *
 * Simple multi-threaded example with a mutex lock.
 */
#include <getopt.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_fac(int *);
void do_wrap_up(int);
int result = 1;
int *r;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char **argv) {
    pthread_t *threads;
    int k=-1, pnum=-1, mod=-1;

while (1) {
    int current_optind = optind ? optind : 1;

    static struct option options[] = {{"k", required_argument, 0, 0},
                                      {"pnum", required_argument, 0, 0},
                                      {"mod", required_argument, 0, 0},
                                      {0, 0, 0, 0}};

    int option_index = 0;
    
    int c = getopt_long(argc, argv, "kpm", options, &option_index);

    if (c == -1) break;
    switch (c) {
        case 0: 
        switch (option_index) {
            case 0:
                k = strtol(optarg, NULL,0);
                if (k < 0) {
                    printf("k is a positive number\n");
                    return 1;
                }
                break;
            case 1:      
                pnum = atoi(optarg);
                if (pnum <= 0) {
                    printf("pnum is a positive number\n");
                    return 1;
                }
                break;
            case 2:
                mod = atoi(optarg);
                if (mod < 2) {
                    printf("mod should be positive\n");
                    return 1;
                }
                break;    
        }
         case '?':
                break;

        default:
        printf("!d\n");
            printf("getopt returned character code 0%o?\n", c);
    }
      
  }
  if (optind < argc) {
    printf("Has at least one no option argument\n");
    return 1;
  }

  if (k == -1 || pnum == -1 || mod == -1) {
    printf("Usage: %s -k \"num\" --pnum \"num\" --mod \"num\" %d %d %d\n",
           argv[0], k, pnum, mod);
    return 1;
  }
   printf("%d\n", mod);
  


/*
  if (pthread_create(&thread1, NULL, (void *)do_one_thing,
			  (void *)&common) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread2, NULL, (void *)do_another_thing,
                     (void *)&common) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_join(thread1, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  if (pthread_join(thread2, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  do_wrap_up(common);
*/
  return 0;
}

/*
void do_one_thing(int *pnum_times) {
  int i, j, x;
  unsigned long k;
  int work;
  for (i = 0; i < 50; i++) {
    pthread_mutex_lock(&mut);
    printf("doing one thing\n");
    work = *pnum_times;
    printf("counter = %d\n", work);
    work++; 
    for (k = 0; k < 500000; k++)
      ;                 
    *pnum_times = work; 
	pthread_mutex_unlock(&mut);
  }
}*/

