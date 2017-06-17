#!/bin/bash

size=0
max=50000

while [ $size -le $max ]
do
	echo `./algoritmo $size` >> tiempos.dat
	let size+=2000
done

Divide_y_venceras 0 0
Fuerza_bruta 0 0
Divide_y_venceras 2000 0.000377
Fuerza_bruta 2000 0.010128
Divide_y_venceras 4000 0.000692
Fuerza_bruta 4000 0.039353
Divide_y_venceras 6000 0.000998
Fuerza_bruta 6000 0.08974
Divide_y_venceras 8000 0.001221
Fuerza_bruta 8000 0.156809
Divide_y_venceras 10000 0.001592
Fuerza_bruta 10000 0.246398
Divide_y_venceras 12000 0.002063
Fuerza_bruta 12000 0.355005
Divide_y_venceras 14000 0.002241
Fuerza_bruta 14000 0.488334
Divide_y_venceras 16000 0.002574
Fuerza_bruta 16000 0.644747
Divide_y_venceras 18000 0.002932
Fuerza_bruta 18000 0.801037
Divide_y_venceras 20000 0.003262
Fuerza_bruta 20000 0.984537
Divide_y_venceras 22000 0.003785
Fuerza_bruta 22000 1.18825
Divide_y_venceras 24000 0.003973
Fuerza_bruta 24000 1.42095
Divide_y_venceras 26000 0.004387
Fuerza_bruta 26000 1.67764
Divide_y_venceras 28000 0.004731
Fuerza_bruta 28000 1.94297
Divide_y_venceras 30000 0.005302
Fuerza_bruta 30000 2.23754
Divide_y_venceras 32000 0.005553
Fuerza_bruta 32000 2.55412
Divide_y_venceras 34000 0.005864
Fuerza_bruta 34000 2.84264
Divide_y_venceras 36000 0.006229
Fuerza_bruta 36000 3.20679
Divide_y_venceras 38000 0.006594
Fuerza_bruta 38000 3.60041
Divide_y_venceras 40000 0.006991
Fuerza_bruta 40000 3.97861
Divide_y_venceras 42000 0.007314
Fuerza_bruta 42000 4.38967
Divide_y_venceras 44000 0.007736
Fuerza_bruta 44000 4.76052
Divide_y_venceras 46000 0.008158
Fuerza_bruta 46000 5.23586
Divide_y_venceras 48000 0.0105
Fuerza_bruta 48000 5.71135
Divide_y_venceras 50000 0.009038
Fuerza_bruta 50000 6.30106
