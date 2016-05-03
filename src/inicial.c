#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653589793238462643383

void recibe_input(int argc, char **argv, int *n, double *e){
  if(argc!=3){
    fprintf(stderr, "USAGE: ./nbody N_particles epsilon\n");
    exit(1);
  }
  *n = atoi(argv[1]);
  *e = atof(argv[2]);
}


double *crea_vector(int n){
  double *v;
  int i;
  if(!(v = malloc(n * sizeof(double)))){
    fprintf(stderr, "Problem with memory allocation\n");
    exit(1);
  }

  for(i=0;i < n;i++){
    v[i] = 0.0;
  }
  return v;
}

void posiciones_iniciales(double *p, int n){
  double phi, theta, r, costheta;
  double R;
  int i;
  R = pow(n, 1.0/3.0);
  for(i=0 ; i<n ; i++){
    phi = 2.0 * PI * drand48();
    costheta = 2.0*(drand48() - 0.5);
    theta  = acos(costheta);
    r = R * pow(drand48(), 1.0/3.0);

    p[i*3 + 0] = r * cos(phi) * sin(theta);
    p[i*3 + 1] = r * sin(phi) * sin(theta);
    p[i*3 + 2] = r * cos(theta);
  }
}

void escribe_estado(double *x, double *y, double *U, double *K, int n, int id){
  FILE *out;
  char filename[512];
  int i;
  sprintf(filename, "output_%d.dat", id);
  if(!(out=fopen(filename, "w"))){
    fprintf(stderr, "Problem opening file %s\n", filename);
    exit(0);
  }
  for (i=0; i<n ; i++){
    fprintf(out, "%e %e %e %e %e %e %e %e\n", 
	    x[3*i +0], x[3*i +1], x[3*i +2],
	    y[3*i +0], y[3*i +1], y[3*i +2], U[i], K[i]);	    
  }

  fclose(out);
}


