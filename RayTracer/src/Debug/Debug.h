#pragma once
#include <cassert>
#include <iostream>


#ifdef RDEBUG
#define ERROR_MSG(x) std::cout << x << std::endl;
#define ASSERT(value, message) if(value) ERROR_MSG(message)
#else
#define ERROR_MESSAGE(x)
#define ASSERT(x) 
#endif // RDEBUG
