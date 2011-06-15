#include "OCL.h"
#include <CL/cl.h>
#include "util.h"
#include <stdio.h>

OCL::OCL(void)
{
	initialized = false;
}


OCL::~OCL(void)
{
	if(initialized)
	{
		clReleaseContext(context);
	}
}

bool OCL::InitializeContext()
{
	printf("Initializing OpenCL context.\n");

	if( !oclGetNVIDIAPlatform(&platformId) )
	{
		printf("Failed to get a platform\n");
		return false;
	}
	printf("Got platform...\n");
	oclPrintPlatformInfo(platformId);

	if( !oclGetSomeGPUDevice(&deviceId, platformId, true) )
	{
		printf("Failed to get a GPU device\n");
		return false;
	}
	printf("Got GPU device...\n");
	oclPrintDeviceInfo(deviceId);

	if( !oclCreateSomeContext(&context, deviceId, platformId, true) )
	{
		printf("Failed to create cl context\n");
		return false;
	}
	printf("Created cl context\n");

	initialized = true;
	return true;
}
