#include "OCL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	OCL ocl;
	if ( !ocl.InitializeContext() )
		printf("Failed to initialize cl device context\n");
	system("pause");
	return 0;
}