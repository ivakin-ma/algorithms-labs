#include"inputout.h"
#include"mat.h"
#include"line.h"
int main(){
	Mat *mat = calloc(1, sizeof(Mat));
	if(inputmat(mat)==CLOSE){
		return 0;
	}
	Mat *cmat = calloc(1, sizeof(Mat));
	copymat(mat, cmat);
	printmat(mat);
	process(cmat);
	printmat(cmat);
	freemat(cmat);
	freemat(mat);
}
