#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "rec_lemin.h"

singletonLemin *singletonLemin_getInstance()
{
	static long long addr = (long long) NULL;
	static int call = 0;
	singletonLemin *singleton = NULL;

	if (call == 0) {
		call = 1;
		singleton = (singletonLemin *) malloc(sizeof(singletonLemin));
		addr = (long long) singleton;
		return ((singletonLemin *) addr);
	} else
		return ((singletonLemin *) addr);
}

int main(int argc, char **argv)
{
	
}
