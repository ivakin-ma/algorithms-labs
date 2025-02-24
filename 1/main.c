#include"head.h"
int main(){
	Mat *mat = calloc(1, sizeof(Mat));
	if(inputmat(&mat)==CLOSE){
		return 0;
	}
	process(mat);
	printmat(mat);
	freemat(mat);
	free(mat);
}
