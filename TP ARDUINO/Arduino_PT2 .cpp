//defino los pines
#define B 13
#define A 12
#define F 11
#define G 10
#define E 9
#define D 8
#define C 7

//defino los botones
#define BOTON_A 4
#define BOTON_B 3
#define BOTON_C 2 

int contador = 0;

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(BOTON_A, INPUT_PULLUP);
    pinMode(BOTON_B, INPUT_PULLUP);
    pinMode(BOTON_C, INPUT_PULLUP); //habilito una resistencia interna 
}
//Maneja la funciona de los botones en bucle
void loop() {
if (digitalRead(DESLIZANTE_TMP)== HIGH){
    if (digitalRead(INTERRUPTOR_DESLIZANTE)== 1) {
        elegir_display(primos);}
    if (digitalRead(INTERRUPTOR_DESLIZANTE) == 0){
        elegir_display(contador);}
    
        if ((digitalRead(BOTON_A) == LOW) && contador < 99){
            contador++;
            primos = cambiarPrimos(primos);
            delay(100);} 
        else if (digitalRead(BOTON_C) == LOW) {
            contador = 0;
            delay(60);}
    }else if (digitalRead(DESLIZANTE_TMP) == LOW){
        int temperatura = medirTemperatura();
        elegir_display(temperatura);
    
    }
}
//Establece un orden de prendido y apagado
void eleccion_numero(int numero)
{
switch(numero){
    case 0:
        encender_luces(1, 1, 1, 1, 1, 1, 0); 
    //le paso como parametro actual un bool que va a ser True o False dependiendo de lo que necesite prender o apagar
        break;
    case 1:
        encender_luces(0, 1, 1, 0, 0, 0, 0);
        break;
    case 2:
        encender_luces(1, 1, 0, 1, 1, 0, 1);
        break;
    case 3:
        encender_luces(1, 1, 1, 1, 0, 0, 1);
        break;
    case 4:
        encender_luces(0, 1, 1, 0, 0, 1, 1);
        break;
    case 5:
        encender_luces(1, 0, 1, 1, 0, 1, 1);
        break;
    case 6:
        encender_luces(1, 0, 1, 1, 1, 1, 1);
        break;
    case 7:
        encender_luces(1, 1, 1, 0, 0, 0, 0);
        break;
    case 8:
        encender_luces(1, 1, 1, 1, 1, 1, 1);
        break;
    case 9:
        encender_luces(1, 1, 1, 1, 0, 1, 1);
        break;
}
}

//esta función permite encender o apagar segmentos específicos en el display 
void encender_luces(int a, int b, int c, int d, int e, int f, int g)
{
    digitalWrite(13, b);
    digitalWrite(12, a);
    digitalWrite(11, f);
    digitalWrite(10, g);
    digitalWrite(9, e);
    digitalWrite(8, d);
    digitalWrite(7, c);
}

//esta funcion separa unidades y las decenas del contador y las muestra en los display
void elegir_display(int contador)
{
//Segun la Salida A1 o A2 buscara decenas o unidades en el contador

    int unidad = contador % 10;
    digitalWrite(A1, LOW);
    eleccion_numero(unidad);
    delay(50);
    digitalWrite(A1, HIGH);
    int decena = contador/10;
    digitalWrite(A0, LOW);
    eleccion_numero(decena);
    delay(50);
    digitalWrite(A0, HIGH);
}