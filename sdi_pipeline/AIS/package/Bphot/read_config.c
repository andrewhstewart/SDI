#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

#include "types.h"

void read_config(char *filename)
{
 FILE *file;
 double df;
 char   s[256],s2[256];


if(!(file=fopen(filename,"r"))) 
     {printf("Oops...cannot find any configuration file...Goodbye !\n"); exit(0)
;}

while(feof(file) == 0)
 {
   fgets(s,256,file);
   sscanf(s,"%s",s2);
   if(!(strncmp(s2,"sub_x",5)))
   {
    sscanf(s,"%s %i",s2,&nload_x);
   }
   if(!(strncmp(s2,"sub_y",5)))
   {
    sscanf(s,"%s %i",s2,&nload_y);
   }
   if(!(strncmp(s2,"rad1_bg",7)))
   {
    sscanf(s,"%s %lf",s2,&df);
    rad1bg=df; 
   }
   if(!(strncmp(s2,"rad2_bg",7)))
   {
    sscanf(s,"%s %lf",s2,&df);
    rad2bg=df; 
   }
   if(!(strncmp(s2,"nstars",6)))
   {
    sscanf(s,"%s %i",s2,&NSTARS);
   }
   if(!(strncmp(s2,"mesh",4)))
   {
    sscanf(s,"%s %i",s2,&mesh2);
   }
   if(!(strncmp(s2,"saturation",10)))
   {
    sscanf(s,"%s %lf",s2,&df);
    saturation=df; 
   }
   if(!(strncmp(s2,"radphot",7)))
   {
    sscanf(s,"%s %lf",s2,&df);
    radphot=df; 
   }
   if(!(strncmp(s2,"psf_width",9)))
   {
    sscanf(s,"%s %i",s2,&stack_width);
   }
   if(!(strncmp(s2,"nstar_max",9)))
   {
    sscanf(s,"%s %i",s2,&NSTARS_MAX);
   }
    if(!(strncmp(s2,"rad_aper",8)))
   {
    sscanf(s,"%s %lf",s2,&df);
    rad_aper=df; 
   }

 }
fclose(file);
 return;
}
