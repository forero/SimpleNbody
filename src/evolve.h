double calcula_tiempo_total(int n);
double calcula_time_step(int n, double epsilon);
void calcula_aceleracion(double *p, double *v, double *a, int n, double epsilon);
void  kick(double *p, double *v, double *a, int n, double delta_t);
void  drift(double *p, double *v, double *a, int n, double delta_t);
