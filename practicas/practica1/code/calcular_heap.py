#!/usr/bin/env python
# coding: utf-8

import sys
import subprocess
import time
import os
import os.path

if len(sys.argv) < 5:
    print("[ERROR] formato:\n <nombre_del_ejecutable> <nombre_del_algoritmo>"+
    "<pc> <optimización> <salida>")
    sys.exit(0)

file = sys.argv[1]
name = sys.argv[2]
computer = sys.argv[3]
opt = sys.argv[4]
out = "out/"+sys.argv[5]


if not os.path.exists(out):
    f = open(out,'w')
    f.write("tamaño\ttiempo\talgoritmo\tpc\toptimización\n")
    f.close()

f = open(out,"a")


print("...Midiendo tiempos...")

size = 200
max = 10000

while size <= max:
   start_time = time.time()
   i = 1
   while i <= 100:
       os.system("./"+file+" %d > /dev/null" % (size))
       i += 1
   tiempo = ( (time.time() - start_time)/100)
   f.write("\n"+str(size)+"\t"+str(tiempo)+"\t"+name+"\t"+computer+"\t"+str(opt)+"\n")
   size += 200
   print("procesado: "+str(size)+" of "+str(max)+"\n")
