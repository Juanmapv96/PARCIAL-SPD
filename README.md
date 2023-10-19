# PARCIAL-SPD

Conecciones "fisicas" del arduino:
**Primera Parte:**
Conecciones hacia los displays de 7 al 13, cada una con una resistencia de 220 ohm.
♦Arduino conecciones a Display 7 segmentos:

De pin 13 a puerto B 
De pin 12 a puerto A
De pin 11 a puerto F
De pin 10 a puerto G
De pin 9 a puerto  E
De pin 8 a puerto  D
De pin 8 a puerto  C
♦Multiplexado hacia el otro Display 7 segmentos con sus pares de letras: 
ej B con B, A con A
El primer display en su catodo comun se encuentra conectado A0
El segundo display en su catodo comun se encuentra conecatdo A1
♦Botones:
Boton Aumento en pin 4 a terminal 1a
Boton Reset en pin 2  a terminal 1a
Boton Restar en pin 3 a terminal 1a
Los 3 se encuentran dirijidos a tierra concatenados.
por su terminal 2b

**Segunda Parte**
Respetando las primeras conecciones haremos unos cambios.
Botones Modificados:
Botono Restar en el pin 3, se cambiara por un interruptor desliznate.
♦Interruptro delizante: 
Conectado al pin 3 
Concantenado a GND con los otros botones
Conecatdo a 5Volt
Nuevas adquisiciones:
♦Agregamos un Sensor de Temperatura, denominado TMP36
El mismo se encuentra conecatdo a A5 por su pata del medio
Conecatado a 5 volt por la potencia
Concatenado por otro interruptor delizante a GND(tierra) por su pata denomidad "TIERRA" o "GND"
♦Boton delizante o Interruptro Delizante
Conecatdo a 5 volt por pata denominada Por Terminal 1 o 2 es indistinto
Concatenado a GND con TMP 36 Por terminal 1 o 2, distinto al de 5 VOLT
Conecatdo al Arduino por su pin A3 por el "COMUN"
