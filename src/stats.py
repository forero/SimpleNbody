import numpy as np
import matplotlib.pyplot as plt
import glob

files = glob.glob("output*.dat")
n_files = len(files)
def energy(data):
    E = data[:,6].sum() + data[:,7].sum()    
    return E

def radius(data):
    E_pot = data[:,6]
    min_pot = np.argmin(E_pot)
    print "min_pot", min_pot
    x = data[:,0] - data[min_pot, 0]
    y = data[:,1] - data[min_pot, 1]
    z = data[:,2] - data[min_pot, 2]
    r = np.sqrt(x**2 + y**2 +z**2)
    r = np.sort(r)
    return r[1:]



i_snap = 0
data_init = np.loadtxt("output_{}.dat".format(i_snap))
E_init = energy(data_init)
r_init = radius(data_init)
print(E_init)


# time ./a.out 450 0.1
i_snap = 3354
data_init = np.loadtxt("output_{}.dat".format(i_snap))
E_final = energy(data_init)
r_final = radius(data_init)
r_final = np.sort(r_final)
log_r_final = np.log10(r_final)

h, c = np.histogram(log_r_final)
print(E_final)

plt.figure()
log_r_center = 0.5 * (c[1:]+c[:-1])
plt.plot(log_r_center, np.log10(h)-2.0*log_r_center)
plt.show()
