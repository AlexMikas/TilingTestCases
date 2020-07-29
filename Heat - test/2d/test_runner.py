#!/usr/bin/env python3
import os
import subprocess
import struct
import pandas as pd
import numpy as np
import csv
import math

def FindAllDivisors(x):
    divList = []
    y = 1
    sqrt = math.sqrt(x)
    while y <= sqrt:
     if x % y == 0:
      divList.append(y)
      divList.append(int(x/y))
     y += 1
    return divList

src_program = r'src.exe'
mod_program = r'mod.exe'

omp = True
thread_count = 12
count = 5
sum = 0
result = 0

os.system("gcc -O3 -o src Heat-2d.c")
if omp:
    os.system("gcc -O3 -fopenmp -o mod Heat-2d-st+wf.c")
else:
    os.system("gcc -O3 -o mod Heat-2d-st+wf.c")
    thread_count = 0

# Запуск исходной программы.
print(">>> Running original program.")
for i in range(count):
    process = subprocess.Popen(src_program, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False)
    outs, errs = process.communicate()
    var = (float(outs))
    sum += var
src_result = sum/count
print(src_result)
# Структура таблицы
# [N,M; time; %]
df = pd.DataFrame(np.array([[u'src', str(src_result).replace('.', ','), '']]),
                  columns=['d1, d2, d3', 'time', 'seq/res'])

# Запуск модифицированной программы.
for th_c in range(6, thread_count+1, 6):
    print(">>> Running modified program. Thread count = " + str(th_c))
    for d1 in [4, 8, 16, 32]:
        for dn in [4, 8, 16, 20, 25, 40, 50, 80,  100,  125,  200,  250,  400]:#sorted(FindAllDivisors(10000)): #list(range(2, 30 + 1, 1)): #(200,5000,50)
            print('>>> Running with variables: d1='+str(d1)+', dn='+str(dn))
            sum = 0
            for i in range(count):
                process = subprocess.Popen([mod_program, str(d1), str(dn), str(th_c)], stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False)
                outs, errs = process.communicate()
                var = (float(outs))
                sum += var
            result = sum / count
            print(result)
            df1 = pd.DataFrame(np.array([[u'd1='+str(d1)+u', d2='+str(dn)+u', d3='+str(dn), str(result).replace('.', ','), str(src_result/result).replace('.',',')]]),
                              columns=['d1, d2, d3', 'time', 'seq/res']) #(src_result - result)/src_result
            df = pd.concat([df, df1], ignore_index=True)

print(">>> Preparing the report.")
from time import gmtime, strftime
df.to_csv("./time_result_"+strftime("%Y-%m-%d_%H-%M-%S", gmtime())+".csv", sep=';', index=False)

print(">>> Finish.")
