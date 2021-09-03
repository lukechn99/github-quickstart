# Signals
Signals are asynchronous IPC, it is a software interrupt typically used for unusual events  
They are usually sent from OS to process but can also be sent from process to process  
```kill -s <signal name> <pid>``` kill does not mean to kill, but to send the signal, if you want to kill, you can send ```kill -s SIGKILL 1234```  
For example, ^C sends a SIGINT to the process and stops it. The CPU is running the process, but will check for signals every now and then. The OS turns the hardware signal into a software signal, the OS sends a software interrupt
SIGABRT: process abort  
SIGINT: Ctrl+c
etc.
### Handling Signals
4 ways: default action, ignore, (un)block signals, take specific action/handle

Ignore Ctrl+c
```
/*
* Recitation Section Number: 9
* Breakout Number:
* Luke Chen: chen5216
* Sam Williams: will6673
* Nadya Postolaki: posto018
* Abdikarim Fareh - fareh002
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void infinitePrint() {

	static int count = 0;
	printf("%ld: Count = %d\n", time(NULL), ++count);
	sleep(1);
}

int main() {

	// ------------------sol1.c-----------------
	// initialize new sigset - sigset_t, sigemptyset
	sigset_t st;
	if ((sigemptyset(&st) == -1) || (sigaddset(&st, SIGINT) == -1)) {
		perror("failed");
		return 1;
	}
	// block SIGINT - sigprocmask
	if (sigprocmask(SIG_BLOCK, &st, NULL)) {
		perror("block error");
		return -1;
	}
	// Do not modify the while loop and infinitePrint()
	// -----------------------------------------

	/* Print infinitely. */
	while (1) infinitePrint();
}
```

Ctrl+C pauses and resumes
```
/*
* Recitation Section Number: 9
* Breakout Number:
* Luke Chen: chen5216
* Sam Williams: will6673
* Nadya Postolaki: posto018
* Abdikarim Fareh - fareh002
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Remember the usage of sig_atomic_t in the recitation example
// First solution will ignore SIGINT (Ctrl-C) 
// when it is delivered (sol2.c) -use sigprocmask

static volatile sig_atomic_t pauseflag = 0;

static void setpauseflag(int signo) {
   	pauseflag = !pauseflag;
}

void infinitePrint() {
	static int count = 0;
	printf("%ld: Count = %d\n", time(NULL), ++count);
	sleep(1);
}

int main() {
	// ------------------sol2.c-----------------
	// setup signal handler - sigaction struct, sigemptyset, 
	struct sigaction act;

	act.sa_handler = setpauseflag;
	act.sa_flags = 0;
	if ((sigemptyset(&act.sa_mask) == -1) || (sigaction(SIGINT, &act, NULL) == -1)) {
		perror("failed in sigemptyset or sigaction");
		return 1;
	}

	// specify action associated with SIGNT - sigaction()
	
	// You are free to modify the while loop but not the infinitePrint()
	// -----------------------------------------

	// infinite loop
	while (1) {
		if (!pauseflag) {
			infinitePrint();
		}
	}
}
```
