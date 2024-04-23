c -----------Cells
1 3 -19.05 (-4 2 -3) imp:n=1 $ Uranium in cylinder
2 2 -1 (-1 2 -3 4) imp:n=1 $ Water in cylindr 
3 like 1 but trcl=(5 0 0)
4 like 1 but trcl=(2.5 4.3301 0)
5 like 2 but trcl=(5 0 0)
6 like 2 but trcl=(2.5 4.3301 0)
99 0 99 imp:n=0 $ otside of vac sphere
98 1 -0.012 -99 #1 #2 #3 #4 #5 #6 imp:n=1 $ inside of vac sphere

c ----------------Geometry------------
c --------Cylinder
1 cz 2
2 pz -5
3 pz 5
c ---------Uranium
4 cz 1
c --------Void cell
99 s 2.5 2.16505 0 15

c ---------Sources--------------------
sdef par=1 erg=d1 rad=d5 pos=d7 ext=d6 axs=0 0 1 $
sp1 -3 0.988 2.249
si5 0 1
sp5 -21 1
si6 -5 5
sp6 0 1
si7 L 0 0 0 5 0 0 2.5 4.3301 0
sp7 1 1 1  
c -----------------------Materials
m1 1001 -0.00064 6012 -0.00014 7014 -0.75086 &
   8016 -0.24836 $ air
m2 1001 -0.11112 8016 -0.88888 $ H2O
m3 92235 1 $ U-235
c 
c -------------Tallies--
c Enegry bins: 0 1e-7 1e-6 1e-3 1 10
F2:N 1 T $ on Uran
E2 1e-8 1e-7 1e-6 1e-3 1 10
F12:N (2 3) T $ Torec
E12 1e-8 1e-7 1e-6 1e-3 1 10
c ----------translations
drxs
MODE N
NPS 1e7
lost 20  10
ptrac file=asc event=src type=n max=3000 write=pos
prdmp 2j -1 $ 20000 20000 
print 10 40 50 110 161 170