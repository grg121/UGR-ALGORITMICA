 int inversiones = 0;
 clock_t ini, fin;
ini = clock();
for (int k = 0; k < 10000; k++) {
 for (int i = 0; i < n; i++) {
   for (int j = i + 1; j < n; j++) {
     if (T[j] > T[i]) {
      inversiones++;
   }
 }
 }
 }
