//sum.cpp 
#include "sum.h"

uint32_t ntohl(uint32_t n){
	uint32_t n1 = (n & 0x000000FF) << 24;
	uint32_t n2 = (n & 0x0000FF00) << 8;
	uint32_t n3 = (n & 0x00FF0000) >> 8;
	uint32_t n4 = (n & 0xFF000000) >> 24; 
	return n1 | n2 | n3 | n4;
}
