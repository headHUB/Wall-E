#include <Servo.h>  // Librería de servos

// Definición de servos
// 1, 2 servos de la base
// 3, 4 servos distintos de cada brazo
// 5, 6 servos de la pinza
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;
Servo servo_5;
Servo servo_6;

// Variables para definir la posicion del servo en cada momento
int posicion_servo_1;
int posicion_servo_2;
int posicion_servo_3;
int posicion_servo_4;
int posicion_servo_5;
int posicion_servo_6;

// Definir numero de pin para cada pulsador
const int pulsador_servos_base_izq = 22;
const int pulsador_servos_base_der = 24;
const int pulsador_servo_3_arr = 2;
const int pulsador_servo_3_abj = 3;
const int pulsador_servo_4_arr = 4;
const int pulsador_servo_4_abj = 5;
const int pulsador_servos_pinza_abr = 6;
const int pulsador_servos_pinza_cer = 7;

// Variables para poder leer el estado del pulsador
int estado_pulsador_servos_base_izq = 0;
int estado_pulsador_servos_base_der = 0;
int estado_pulsador_servo_3_arr = 0;
int estado_pulsador_servo_3_abj = 0;
int estado_pulsador_servo_4_arr = 0;
int estado_pulsador_servo_4_abj = 0;
int estado_pulsador_servos_pinza_abr = 0;
int estado_pulsador_servos_pinza_cer = 0;

// Incremento del angulo cada vez que pulsemos
int incremento_angulo = 2;


// Configuración de pines
void setup()
{
    // Definir el pin de salida de cada servo, tipo PWM
    servo_1.attach(8);
    servo_2.attach(9);
    servo_3.attach(10);
    servo_4.attach(11);
    servo_5.attach(12);
    servo_6.attach(13);

    // Definir los pines para la señal de los pulsadores como señal de entrada
    pinMode(pulsador_servos_base_izq, INPUT);
    pinMode(pulsador_servos_base_der, INPUT);
    pinMode(pulsador_servo_3_arr, INPUT);
    pinMode(pulsador_servo_3_abj, INPUT);
    pinMode(pulsador_servo_4_arr, INPUT);
    pinMode(pulsador_servo_4_abj, INPUT);
    pinMode(pulsador_servos_pinza_abr, INPUT);
    pinMode(pulsador_servos_pinza_cer, INPUT);
}

// Condiciones de funcionamiento
void loop()
{
    // Leemos el estado de cada pulsador
    estado_pulsador_servos_base_izq = digitalRead(pulsador_servos_base_izq);
    estado_pulsador_servos_base_der = digitalRead(pulsador_servos_base_der);
    estado_pulsador_servo_3_arr = digitalRead(pulsador_servo_3_arr);
    estado_pulsador_servo_3_abj = digitalRead(pulsador_servo_3_abj);
    estado_pulsador_servo_4_arr = digitalRead(pulsador_servo_4_arr);
    estado_pulsador_servo_4_abj = digitalRead(pulsador_servo_4_abj);
    estado_pulsador_servos_pinza_abr = digitalRead(pulsador_servos_pinza_abr);
    estado_pulsador_servos_pinza_cer = digitalRead(pulsador_servos_pinza_cer);

    // Funciones para el movimiento del brazo mediante los pulsadores
    if (estado_pulsador_servos_base_izq == HIGH) {
        posicion_servo_1 = posicion_servo_1 + incremento_angulo;
        posicion_servo_2 = posicion_servo_2 + incremento_angulo;

        servo_1.write(posicion_servo_1);
        servo_2.write(posicion_servo_2);

        delay(100);
    } else if (estado_pulsador_servos_base_der == HIGH) {
        posicion_servo_1 = posicion_servo_1 - incremento_angulo;
        posicion_servo_2 = posicion_servo_2 - incremento_angulo;

        servo_1.write(posicion_servo_1);
        servo_2.write(posicion_servo_2);

        delay(100);
    } else if (estado_pulsador_servo_3_arr == HIGH) {
        posicion_servo_3 = posicion_servo_3 + incremento_angulo;

        servo_3.write(posicion_servo_3);

        delay(100);
    } else if (estado_pulsador_servo_3_abj == HIGH) {
        posicion_servo_3 = posicion_servo_3 - incremento_angulo;

        servo_3.write(posicion_servo_3);

        delay(100);
    } else if (estado_pulsador_servo_4_arr == HIGH) {
        posicion_servo_4 = posicion_servo_4 + incremento_angulo;

        servo_4.write(posicion_servo_4);

        delay(100);
    } else if (estado_pulsador_servo_4_abj == HIGH) {
        posicion_servo_4 = posicion_servo_4 - incremento_angulo;

        servo_4.write(posicion_servo_4);

        delay(100);
    }  else if (estado_pulsador_servos_pinza_abr == HIGH) {
        posicion_servo_5 = posicion_servo_5 + incremento_angulo;
        posicion_servo_6 = posicion_servo_6 + incremento_angulo;

        servo_5.write(posicion_servo_5);
        servo_6.write(posicion_servo_6);

        delay(100);
    } else if (estado_pulsador_servos_pinza_cer == HIGH) {
        posicion_servo_5 = posicion_servo_5 - incremento_angulo;
        posicion_servo_6 = posicion_servo_6 - incremento_angulo;

        servo_5.write(posicion_servo_5);
        servo_6.write(posicion_servo_6);

        delay(100);
    } else {
        delay(100);
    }
}
