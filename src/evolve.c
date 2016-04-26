#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592653589793238462643383
#define G_GRAV 4.49E-3

double calcula_tiempo_total(int n){
  double t_dyn;
  double rho;
  double R;
  R = pow(n, 1.0/3.0);
  rho = n / (4.0/3.0) / (PI * pow(R,3));
  t_dyn = 1.0/sqrt(G_GRAV * rho);
  return 10* t_dyn;
}

double calcula_time_step(int n, double epsilon){
  double t_dyn; 
  double rho;
  double R;
  rho = n / (4.0/3.0) / (PI * pow(epsilon, 3));
  t_dyn = 1.0/sqrt(G_GRAV * rho);
  return t_dyn;
}

void calcula_aceleracion(double *p, double *v, double *a, int n, double epsilon){
  int i,j,k;
  double delta, delta_total;
  for(i=0;i<n;i++){
    for(k=0;k<3;k++){
      a[i*3 + k] = 0.0;
    }
    for(j=0;j<n;j++){
      if(i!=j){
	delta_total = 0.0;
	for(k=0;k<3;k++){
	  delta_total += pow((p[i*3 + k] - p[j*3 + k]),2);
	}
	for(k=0;k<3;k++){
	  delta = p[i*3 + k] - p[j*3 + k]; 
	  a[i*3 + k] += -G_GRAV * delta 
	    / pow((delta_total + pow(epsilon,2)), 3.0/2.0);
	}
      }
    }
  }
}

