#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("i have been interrupted how rude!\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  //endless loop
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
