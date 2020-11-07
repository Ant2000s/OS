#include <iostream>
#include <signal.h>
int main() {
//int sig;
pid_t n;
scanf("%d",&n);
kill(n,SIGABRT);
}
