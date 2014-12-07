Wily
====

MiniBot Wily v0.1

Wily minibot. Esta inspirado en el uso de razón básica humana; noción del tiempo, memoria y percepción sobre el entorno, dando le a si  unas características especiales, como saber que dirección a tomado y que tiempo lo ha recorrido, aparte de ir recopilando mas información en la memoria. 

hardware :

Arduino nano v3.0
ultrasonido HC-Sr04
reloj DS1307
control de motores L298N
Tarjeta Sd 
bluetooth H06 
temperatura Lm35
regulador 7805
rectificador puente diodo motores 
2 motores Dc  9v
piezas 3D print los siguiente enlaces se irán actualizando según se termine el diseño 
http://www.thingiverse.com/thing:2820
https://www.youtube.com/watch?v=7bn4RZi4djo&feature=youtu.be*****por actualizar
diagrama montaje link
https://www.facebook.com/newlinerobotic
piezas 3D print http://www.thingiverse.com/thing:582192
software 
programación C

protocolos 

RXTX serial inalámbrico 
protocolo SPI tarjeta Sd
protocolo i2C Ds1307 tiempo real 

funciones 

detector de objetos próximo y calculo de la salida mas factible en un giro de 180 grados, 
recolección de datos; hora, temperatura, dirección y distancia cada vez que para 
creando una cadena  String. 
Ej;

Formato archivo Wily.txt
hora        temp  direc distancia
02:57:21 -28       R     7
02:57:22- 28       R     7
02:57:22- 28       R     7

F= alante
R= derecha
L= izquierda


timestamp : para el homy de vuelta al punto de partida, con el Uso de la memoria EEprom


creador new line robotic

comprobación del programa por puerto serial 

pase izquierda
pase izquierda2
pase ultrasonido
pase izquierda1
pase S toma dato
pase derecha
pase derecha2
pase ultrasonido
pase derecha1
pase S toma dato
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase borrado
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase derecha
pase derecha2
pase ultrasonido
pase derecha1
pase S toma dato
pase izquierda
pase izquierda2
pase ultrasonido
pase izquierda1
pase S toma dato
pase atrás
pase S toma dato
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase derecha
pase derecha2
pase ultrasonido
pase derecha1
pase S toma dato
pase izquierda
pase izquierda2
pase ultrasonido
pase izquierda1
pase S toma dato
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase derecha
pase derecha2
pase ultrasonido
pase derecha1
pase S toma dato
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase izquierda
pase izquierda2
pase ultrasonido
pase izquierda1
pase S toma dato
pase homy vuelta a casa 
pase enfrente
pase enfrente1
pase enfrente2
pase ultrasonido
pase S toma dato
pase derecha
pase derecha2
pase ultrasonido
pase derecha1
pase S toma dato
