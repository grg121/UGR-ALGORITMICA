#!/usr/bin/env python
# coding: utf-8
# autor: grg121 (Fco Navarro)

import sys
import subprocess
import time
import os
import os.path

print("...Midiendo tiempos...")

153600



size = 0 # size representa el chunck
max = 100
while size <= max:
    os.system("export OMP_SCHEDULE='static,%d'" %(size))
    os.system("./pmtvOMP %d > static.dat" % (size))
    print("Tamaño:"+str(size)+" finalizado.\n")
    size += 1
    print("procesado: " + str(size) + " of " + str(max)+"\n")

size = 0
max = 100
while size <= max:
    os.system("export OMP_SCHEDULE='dynamic,%d'" %(size))
    os.system("./pmtvOMP %d > dynamic.dat" % (size))
    print("Tamaño:"+str(size)+" finalizado.\n")
    size += 1
    print("procesado: " + str(size) + " of " + str(max)+"\n")

size = 0
max = 100
while size <= max:
    os.system("export OMP_SCHEDULE='guided,%d'"%(size))
    os.system("./pmtvOMP %d > guided.dat" % (size))
    print("Tamaño:"+str(size)+" finalizado.\n")
    size += 1
    print("procesado: " + str(size) + " of " + str(max)+"\n")
