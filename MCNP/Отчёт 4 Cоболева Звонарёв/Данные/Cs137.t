c Spectrometer c  cells                                                   
1  1 -3.667   -1   imp:e=1 imp:p=1  $ crystal NaJ                         
2  2 -2.7      1 -2    imp:e=1 imp:p=1 $ dural box                        
3  3 -.0012   -3  2  imp:e=1 imp:p=1 $ air box                            
4  4  -7.6     3 -4  imp:e=1 imp:p=1 $ Fe cladding                        
5  5  -11      4 -5  imp:e=1 imp:p=1 $ Pb cladding                        
6  4   -7.6    5 -6  imp:e=1 imp:p=1 $ Fe cladding                        
7  4  -7.6     -7 8   imp:e=1 imp:p=1 $ Fe up cover 1                     
8  3  0.0012   -8  imp:e=1 imp:p=1 $ air hole 1                           
9  4 -7.6  10 -9  imp:e=1 imp:p=1 $ Fe cover 2                            
10 2 -2.7  -10 11       imp:e=1 imp:p=1 $ Al part of cover 2              
11 5 -11   17 12  -16 #16     imp:e=1 imp:p=1 $ Led part of cover 2       
12 3  -.0012   -12          imp:e=1 imp:p=1 $ air part of cover 2         
13 4 -7.6  -13 14   imp:e=1 imp:p=1 $ Fe botton cover                     
14 2 -2.7   15 -14    imp:e=1 imp:p=1 $ Al botton cover                   
15 6 -2.4   -15       imp:e=1 imp:p=1 $ FMT botton  cover                 
16 2 -2.7 12 -18      imp:e=1 imp:p=1 $ Al cover                          
18 4 -7.6   16 -11 #16  imp:e=1 imp:p=1 $ cover                           
17 4 -7.6   -17  imp:e=1 imp:p=1 $ cover                                  
99 0 #1 #2 #3 #4 #5 #6 #7 #8 #9 #10 #11 #12 #13 #14 #15 &                 
 #16 #17 #18 imp:e=0 imp:p=0                                              
                                                                          
1 rcc 0 0 0  0 0 5.15 1.5075 $ center                                     
2 rcc 0 0 0  0 0 5.4  1.7                                                 
3 rcc 0 0 0  0 0 9.0  5.3                                                 
4 rcc 0 0 0  0 0 9.0  5.6                                                 
5 rcc 0 0 0  0 0 9.0  6.6                                                 
6 rcc 0 0 0  0 0 9.0  6.9                                                 
7 rcc 0 0 9 0 0 1.2  6.9 $ up                                             
8 rcc 0 0 9 0 0 1.2  0.6                                                  
9 rcc  0 0 10.2   0 0 2  6.9                                              
10 trc 0 0 10.2   0 0 2  2.7 4.7                                          
11 rcc 0 0 10.2   0 0 2  2.7   $ ??? -dz 2.7                              
12 rcc 0 0 10.2   0 0 1.5  1.3  $ ???                                     
16 rcc 0 0 10.2   0 0 2  2.4   $ ??? -dz 2.7                              
17 rcc 0 0 11.9   0 0 0.3  2.4   $ ??? -dz 2.7                            
18 rcc 0 0 10.2   0 0 0.2  2.5                                            
c botton                                                                  
13 rcc 0 0 0  0 0 -1.5  6.9                                               
14 rcc 0 0 0  0 0 -1.5  2.7                                               
15 rcc 0 0 0  0 0 -1.5  1.5075                                            
                                                                          
MODE P E                                                                  
c Cs137                                                                    
sdef erg 0.6671 par=2 pos 0 0 10.67                                       
f8:e 1                                                                    
ft8 geb -0.00555213 0.0695618 0.146606 $ sample parameters                 
e8 0 .00025 7998I 2.                                                     
m1 11000 0.5 53000 0.5 $ NaI rho=3.667 $ NaI medium                       
m2 13027 1.0 $ Al medium                                                  
m3 1001 -0.00064 6012 -0.00014 7014 -.75086 8016 -.24836 $ air medium     
m4 26000 1.0 $ Fe medium                                                  
m5 82000 1.0 $ Pb medium                                                  
m6 8000 -0.459 11000 -0.098 14000 -0.336 20000 -0.107 $ FMT glass rho=2.4 
CUT:P 1j 0.02 0 0 $ cutoffs                                               
CUT:E 1j 0.02 0 0                                                         
NPS 1e7                                                                   
lost 20 10                                                                
ctme 8640000                                                              
prdmp 2j -1 $20000 20000                                                  
print 10 40 50 128 161 170                                                
