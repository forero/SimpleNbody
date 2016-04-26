#include <stdio.h>
#include <stdlib.h>
#include "inicial.h"
#include "evolve.h"
/*
  Un programa sencillo para seguir la evolucion
  dinamica de un conjunto de N masas puntuales.
*/

int main(int argc, char **argv){
  int i=0, N=0;
  double *p=NULL;
  double *v=NULL;
  double *a=NULL;
  double time_step=0, total_time=0, epsilon=0;
  int n_steps=0;

  /*inicializacion*/
  recibe_input(argc, argv, &N, &epsilon);
  p = crea_vector(N);
  v = crea_vector(N);
  a = crea_vector(N);
  posiciones_iniciales(p, N);
  escribe_estado(p,v,N,i);

  
  // tiempos caracteristicos 
  total_time = calcula_tiempo_total(N);
  time_step = calcula_time_step(N, epsilon);
  n_steps = (int)(total_time/time_step);
  fprintf(stderr, "tiempo total: %f time_step: %f n_steps %d\n", 
	  total_time, time_step, n_steps);
  //evolucion temporal
  /*
  for(i=0;i<n_steps;i++){
    calcula_aceleracion(p, v, a, N, epsilon);
    actualiza_timestep(p, v, a, N);
  }
  escribe_estado(p, v,N, i)
  */
  return 0;
}

