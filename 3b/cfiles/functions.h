#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<stddef.h>
#include<math.h>
#include<float.h>
#include <stdio.h>
#include<stdbool.h>
typedef enum Err {
	OK,
	ERROR
} Err;
Err is_prost(size_t);
size_t next_prost(size_t);
#endif
