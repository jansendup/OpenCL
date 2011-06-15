#pragma once
#include <CL/cl.h>

class OCL
{
public:
	OCL(void);
	~OCL(void);
	bool InitializeContext();
private:
	cl_platform_id platformId;
	cl_device_id deviceId;
	cl_context context;

	bool initialized;
};

