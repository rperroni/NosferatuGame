---------- CORRER ----------

- La parte visual por consola, está diseñada en Linux.

- Antes de ejecutar el programa, se deberá poner la consola en pantalla completa
y ajustar el zoom en caso de errores visuales, hasta que se vea correctamente. Puede que se necesite
volver a correr el programa.


---------- CAMINOS MÍNIMOS ----------

- Los costos de los caminos es el costo de INGRESAR al casillero (no cuenta el costo de donde sale).
De esta forma el costo de ir de A a B es el costo de ingresar a B,
mientras que el costo de ir de B a A es el costo de ingresar al casillero A.

- Al realizar el camino mínimo de un punto A a un punto B, el personaje puede pasar por casilleros ocupados,
tanto por elementos como por otros personajes, siempre y cuando el punto B no tenga ningún personaje.
Si el punto B es un casillero ocupado por un elemento no hay problema.
Si el personaje que se está moviendo tiene permiso de agarrar ese elemento lo agarra
y lo guarda en su inventario; si no, queda en el casillero y puede ser agarrado por otro personaje que pase por ahí,
pero al mostrar el tablero mientras se espera una opción el único que se mostrará es el personaje y no el elemento.


---------- INVENTARIO ----------

- Si al mover un personaje este pasa por encima de un elemento y lo puede agarrar,
lo agarra y lo guarda en su inventario (sin preguntar al usuario)

- Si un personaje agarra más de un elemento del mismo tipo, este se sumará al inventario (cantidad de ese elemento),
sin crear un nuevo espacio para el mismo.


---------- TRANSFORMACIONES ----------

- Cuando un humano se transforma en monstruo, sus objetos del inventario quedan inutilizables.

---------- ARCHIVOS ----------

- Las medidas del mapa son tomadas en cuenta desde el archivo de "tablero.txt", las medidas que están en "estado.txt",
no son tomadas en cuenta.

- Los archivos tienen que estar sin saltos de lineas al final de los datos, para evitar errores.

---------- SIMULACIÓN ----------

- Si un personaje no tiene energía para atacar o para defender y se selecciona alguna de las dos opciones,
el personaje perderá el turno y sera contado como un turno pasado.

- Si un jugador ingresa la opción salir durante la simulación, no se guardará la partida.

