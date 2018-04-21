#include <pthread.h>
#include <stdio.h>
#include "getenv1.c"

void * thr_fn(void * arg)
{
  char * name = "PATH";
  for(;;) {
    char * env_name = getenv(name);  
    printf("%s\n", env_name);
  }
  return (void *) NULL;
}
int main()
{
  pthread_t tid;
  int err;
  int count = 0;
  for(; count < 100; count++) {
    err = pthread_create(&tid,NULL, thr_fn, (void *)NULL);  
    if (err != 0 ) {
      printf("error!%d", err);
    }
  }
  sleep(3);
}
