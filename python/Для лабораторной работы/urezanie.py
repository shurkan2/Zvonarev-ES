name = input('Название файла? = ')
a = open(r'#.dat'.replace('#',name),'r')
b = open(r'Урезанные_спектры_по_256/#_256.dat'.replace('#',name),'w')
print('Maked files')
mas = []
done_mas = []
for i in a.read().split('\n'):
    if i!='': mas.append(int(i))
for i in range(256):
    done_mas.append(str(mas[4*i+1]+mas[4*i+2]+mas[4*i+3]+mas[4*i])) 
print(len(done_mas))
a.close()
for i in done_mas:
    b.write(i+'\n')
b.close()
print('done')