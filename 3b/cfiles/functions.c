#include"functions.h"
Err is_prost(size_t a){
	if(a<2){
		return ERROR;
	}
	double b = (double) a;
	b = sqrt(b);
	if(b==DBL_MAX){
		printf("Overflow.\n");
		return ERROR;
	}
	for(size_t i = 2; i<(size_t)b; i++){
		if(a%i==0){
			return ERROR;
		}
	}
	return OK;
}
size_t next_prost(size_t a){
	size_t candidate = (a%2==0) ? a+1 : a+2;
	while(1){
		bool is_prost = true;
		if(candidate % 2 == 0|| candidate % 3 == 0){
			is_prost = false;
		}else{
			for(size_t i = 5; i*i<=candidate; i+=6){
				if(candidate%i==0||candidate%(i+2)==0){
					is_prost = false;
					break;
				}
			}
		}
		if(is_prost&&candidate>1){
			return candidate;
		}
		candidate += (candidate %2==0) ? 1 : 2;
	}
}
