#include "OCL.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** args)
{
	OCL ocl;
	if ( !ocl.InitializeContext() )
	{
		printf("Failed to initialize cl device context\n");
		goto END;
	}
	if( !ocl.LoadProgram("Test.cl") )
	{
		printf("Failed to Load Program.\n");
		goto END;
	}
	if( !ocl.Run() )
	{
		printf("Failed to Run Program.\n");
		goto END;
	}
END:
	system("pause");
	return 0;
}