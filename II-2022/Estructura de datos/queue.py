from queue import Queue 
#insertar es O(1)
datos = Queue() 
datos.put(10)
datos.put(3) 
datos.put(5) 
datos.put(1) 
 
# 10, 3, 5, 1
#obtiene el primer elemento
x = datos.get()  # devuelve el 10 y lo borra
print(x)
x = datos.get()  # devuelve el 3 y lo borra
print(x)
 
 
print(" Mostrando con listas")
print(list(datos.queue))
 
print(" Elementos de la Cola")
while datos.qsize() > 0:
    x = datos.get()
    print(x)
 
#insertar O(1)
#eliminar O(1)
 
 
#print(’Longitud:_’,datos.qsize()) 
#x=datos.get() 
#print(’Primer_valor:_’,x) 
#print(’Datos:’,list(datos.queue)) 
 
 
#Grafos 
#Breath First Search
