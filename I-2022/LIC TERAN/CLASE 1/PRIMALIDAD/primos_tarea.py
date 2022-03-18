# T(n) = 1 + 2 log (log n) + 1
# O(T(n)) = 2 log (log (n))
# O(n) = log (log (n))
def marcar_multiplos_n(criba,n,tamano):         # 1     
  for i in range(n + n,tamano+1,n):           # log log n + 1
    criba[i]=False                  # log log n



# T(n) = 2
# O(T(n)) = 1
# O(n) = 1
def es_primo(criba,n):            # 1  
  return criba[n]           # 1




# T(n) = 1 + 2 * n + n * log (log (sqrt(n)))

# O(n) = n * log (log (sqrt(n)))



def cribar(criba,tamano):               # 1
  raiz = int(tamano**0.5)+1
  # raiz = tamano
  for i in range(2,raiz+1):             # n           
    if es_primo(criba,i):               #n  * 2
      marcar_multiplos_n(criba,i,tamano)      # n  * log ( log  ( sqrt(n) ))



# T(n) = n + 3
# O(T(n)) = n
def crear_criba(tamano):          # 1
  criba = [True] * (tamano+1)           # n     
  criba[0] = criba[1] = False       # 1
  return cribar             # 1

# crear una lista de numeros primos
def crear_list_primos(criba):
  lista_primos=[]
  for x,y in enumerate(criba):
    if y==True:
      lista_primos.append(x)
  return lista_primos


tamano = 100
# creando el vector de criba
criba = crear_criba(tamano)
# genera la criba
cribar(criba,tamano)
primos = crear_list_primos(criba)
print(primos)


