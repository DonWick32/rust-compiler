0 n = 10
1 t0 = low < high
2 if t1 != t0 goto 38
3 pivot = 0
4 t2 = low
5 t3 = arr[t2] 
6 pivot = t3
7 i = low
8 t4 = low + 1
9 j = t4
10 t5 = j < high
11 if t5 != j goto 10
12 t7 = j
13 t8 = arr[t7] 
14 t9 = t8 < pivot
15 if t9 goto 28
16 t10 = i + 1
17 i = t10
18 t11 = i
19 t12 = arr[t11] 
20 t1 = t12
21 t13 = j
22 t14 = arr[t13] 
23 t2 = t14
24 t12 = t2
25 t14 = t1
26 j = j + 1
27 goto 10
28 t15 = i
29 t16 = arr[t15] 
30 t1 = t16
31 t17 = low
32 t18 = arr[t17] 
33 t2 = t18
34 t16 = t2
35 t17 = t1
36 t19 = i + 1
37 i = t19
38