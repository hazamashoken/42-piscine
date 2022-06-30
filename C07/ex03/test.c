#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex03/ft_strjoin.c"

char *ft_strjoin(int size, char **strs, char *sep);

int func_done = 0;
int timer_done = 0;

void *timer(void *var)
{
	var = 0x00;
	sleep(10);
	timer_done = 1;
	return (0);
}

void *execute(void *var)
{
	var = 0x00;
	
	char *strings[10] = {"a","\t","a\a","a","a","AbuDhabi","42","Amazing","Piscine","here"};	
	char *seperator = "-";
	char *str;
	int size = 10;
	int i = 0;
	
	printf("size = %d | sep = %s | strings = ",size,seperator);
	for (i=0;i<size;i++)
		printf("\"%s\" ",strings[i]);
	str = ft_strjoin(size, strings, seperator);
	printf("\nReturn = %s",str);

	func_done = 1;
	return (0);
}
int main(void)
{
	pthread_t threadId;
	pthread_t timerId;
	int	threadId_Sig;
	
	threadId_Sig = pthread_create(&threadId, NULL, execute,  NULL);
	pthread_create(&timerId, NULL, timer, NULL);

	while (1) {
		if (timer_done) {
			pthread_cancel(threadId);
			printf("*** TIMEOUT ***\n");
			return (1);
		}
		if (func_done)
		{
			pthread_cancel(timerId);
			return (0);
		}
	}
	return (0);
}
