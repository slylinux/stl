#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
#include <signal.h>  
#include <string.h>  
#include <unistd.h>
#include <stdint.h>
#include <sched.h>

#define CLOCKS_PER_USECOND 1730

uint64_t end=0;

uint64_t rdtsc()
{
	uint32_t lo,hi;
	__asm__ __volatile__ ("rdtsc":"=a"(lo),"=d"(hi));
	return (uint64_t)hi<<32|lo;
}

void handler (int sig, siginfo_t * extra, void *cruft)
{
	uint64_t start=rdtsc();
	printf("%ld\n",(start-end)/CLOCKS_PER_USECOND);	
	end = start;
}

void handler1 (union sigval v)
{
	uint64_t start=rdtsc();
	printf("%d\n",(start-end)/CLOCKS_PER_USECOND);	
	end = start;
}

int main ()
{
	int i=0;
	sigset_t sigset;
	timer_t tt;

	struct sched_param param;
	int maxpri;
	maxpri = sched_get_priority_max(SCHED_FIFO);
	param.sched_priority = maxpri;
	if (sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1) //设置优先级
	{
		perror("sched_setscheduler() failed");
		exit(-1);
	} 
	
	sigfillset (&sigset);
	sigdelset (&sigset, SIGRTMIN);
	sigprocmask (SIG_SETMASK, &sigset, NULL);

	struct sigaction sa;
	sigfillset (&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;

	if (sigaction (SIGRTMIN, &sa, NULL) < 0)
	{
		perror ("sigaction failed ");
		exit (-1);
	}

	struct sigevent timer_event;
	struct itimerspec timer;

	memset(&timer_event, 0, sizeof(struct sigevent));

	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_nsec = 250000;
	timer.it_value = timer.it_interval;

	timer_event.sigev_notify = SIGEV_SIGNAL;
//	timer_event.sigev_notify_function=handler1;
	timer_event.sigev_signo = SIGRTMIN;
	timer_event.sigev_value.sival_ptr = (void *) &tt;

	if (timer_create (CLOCK_REALTIME, &timer_event, &tt) < 0)
	{
		perror ("timer_create failed");
		exit (-1);
	}

	if (timer_settime (tt, 0, &timer, NULL) < 0)
	{
		perror ("timer_settime failed");
		exit (-1);
	}

	while (true)
	{
		pause ();
	}

	return 0;
}


