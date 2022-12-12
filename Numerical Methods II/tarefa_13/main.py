import math
import numpy as np




def f(Si, ti):
	return -g - (k/m * Si)


def metodoForwardEuller(Si, ti, delta, tf):
	Si_1 = 0.0
	tcorrente = ti

	while(tcorrente < tf):
		Si_1 = Si + delta*f(Si, tcorrente)
		tcorrente += delta
		Si = Si_1
		print("S: ", Si)
	return Si_1


# def RungeKutta3(Si, ti, delta, tf):
# 	Si_1 = Si_2 = ti_2 = ti_1 = Si_1_barra = 0.0
# 	tcorrente = ti

# 	while(tcorrente < tf):
# 		Si_1_barra = Si + delta * f(Si, tcorrente)
# 		ti_1 = tcorrente + delta

# 		Si_2 = Si + (delta/2)*f(Si, tcorrente)
# 		ti_2 = tcorrente + delta/2

# 		Si_1 = Si + (delta/3) * (f(Si, tcorrente) + 2*f(Si_2, ti_2) + f(Si_1_barra, ti_1))

# 		Si = Si_1
# 		tcorrente += delta
# 		print("S: ", Si)
	

# 	return Si_1

def rungeKutta(t_0, v_0, y_0, k, m, g, dt):
	s_0 = np.array([v_0, y_0])
	i = 1
	y_max = y_0
	t_max = t_0
	v_final = 0

	while(s_0[1] >= 0):
		v_meio = v_0 + (dt/2) * (-g - (k/m * v_0))
		y_meio = y_0 + (dt/2) * v_0

		v_1 = v_0 + dt * (-g - (k/m * v_0))
		y_1 = y_0 + dt * v_0

		s_1 = s_0 + dt * ((1/6) * (np.array([-g-v_0, v_0])) + (4/6) * (np.array([-g-v_meio, v_meio])) + (1/6)*(np.array([-g-v_1, v_1])))

		t_0 += dt

		i += 1
		v_final = v_0
		v_0 = s_1[0]
		y_0 = s_1[1]
		s_0 = s_1

		if y_0 > y_max:
			y_max = y_0
			t_max = t_0
		
	print(f"delta = {dt}")
	print(f"y_max = {y_max}")
	print(f"t_max = {t_max}")
	print(f"t_total = {t_0 -dt}")
	print(f"v_final = {abs(v_final)}")
	
def PrevisorCorretor4(Si, ti, delta, tf):
	Si_1 = Si_2 = Si_3 = Si_3_preditor = Si_3_corretor = ti_1 = ti_2 = ti_3 = 0.0
	tcorrente = ti
	while(tcorrente < tf):

		ti_1 = tcorrente + delta
		ti_2 = ti_1 + delta
		ti_3 = ti_2 + delta

		Si_1 = metodoForwardEuller(Si, tcorrente, delta, ti_1)
		Si_2 = metodoForwardEuller(Si, tcorrente, delta, ti_2)
		Si_3 = metodoForwardEuller(Si, tcorrente, delta, ti_3)
		
		Si_3_preditor = Si_2 + (delta/ 24.0) * (-9.0 * f(Si, tcorrente) + 37.0 * f(Si_1, ti_1) - 59.0*f(Si_2, ti_2) + 55.0*f(Si_3, ti_3))
		
	
		Si_3_corretor = Si_3 + (delta / 24.0)*(f(Si_1, ti_1) - 5.0*f(Si_2, ti_2) + 19.0* f(Si_3,ti_3) + 9.0 * f(Si_3_preditor, ti_3 + delta))
		tcorrente = ti_3
		Si = Si_3
		print("Preditor: ", Si_3_preditor)
		print("Corretor: ", Si_3_corretor)

	
	
	return Si_3_corretor



def main():
	t_0 = 0
	v_0 = 5
	y_0 = 200
	k = 0.5
	m = 2
	g = 10
	dts = [0.1, 0.01, 0.001, 0.1]

	# for dt in dts:
	# 	print("\n")
	# 	rungeKutta(t_0, v_0, y_0, k, m, g, dt)

	rungeKutta(t_0, v_0, y_0, k, m, g, 0.1)

main()