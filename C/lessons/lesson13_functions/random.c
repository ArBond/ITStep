#include "random.h"

#include <time.h>

int const maxRandNubmer = 10;

int rand10()
{
	srand(time(0));
	return rand() % (maxRandNubmer + 1);
}