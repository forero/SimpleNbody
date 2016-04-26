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
