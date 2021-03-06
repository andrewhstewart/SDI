#include<math.h>
#include<stdio.h>
#include "fit.h"

double sigma(x,y,z,ndeg,ndata,coeff)
double    *x,*y,*z,*coeff;
int       ndata,ndeg;
{
	double  sig,sg;
	int     i;
	
	sig = 0.0;
	
	for(i=0;i<ndata;i++)
	{
	     sg    = z[i] - poly(x[i],y[i],ndeg,coeff);
	     sg   *= sg;
	     sig += sg;	      
	}

	sig = sqrt(sig/(double)(ndata-1));
	
	return sig;
}
