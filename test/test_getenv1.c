#include <pthread.h>
#include <stdio.h>

extern char * getenv_v1(char *);

void * thr_fn(void * arg)
{
  char * name = (char *) (arg);
  int i = 0;
  for(;;) {
    char * env_name = getenv_v1(name);  
    printf("%s\n", env_name);
    i++;
    if (i > 100000) {
      break;
    }
  }
  return (void *) NULL;
}
int main()
{
  pthread_t tid;
  int err;
  int count = 0;
  const char * envname;
  for(; count < 20; count++) {
    envname = count % 2 == 0? "PATH" :"CMAKE_CXX_COMPILER";
    err = pthread_create(&tid,NULL, thr_fn, (void *)envname);  
    if (err != 0 ) {
      printf("error!%d", err);
    }
  }
  sleep(3);
}
