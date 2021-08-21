/*Secuencia ascendente exclusiva
 * 
 * Orden ascendente 30 segundos
 * Orden descendente 30 segundos 
 * Tiempo total de cada ejecución 1 minuto
 * Utilizar incrementales para encender cada LED
 */
//Funciones
void apagarLeds(); // Poner todos los LED en bajo

//Variables
int paro_global = 0; //El programa solo debe repetirse 4 veces
int n_led; //Numero de led que encenderemos. Incremental
//Variables de estado de los LED
bool state_1, state_2, state_3, state_4;
//Variables de tiempo
unsigned long tiempo_inicial = 0;
unsigned long tiempo_final;

//LEDS
const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;


void setup() {
  // Todos los pines de los LED como salida
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
}

void loop() {
    apagarLeds(); //Todos los LED empiezan apagados.
    n_led = 8; //Empezamos en el pin 8
    if(paro_global < 4){
      unsigned long tiempo_final = millis(); //Actualizamos el valor del tiempo en cada iteracion
      // INICIA SECUENCIA ADITIVA EXCLUSIVA
      if (tiempo_final - tiempo_inicial >= 200 && state_1 == false){
        state_1 = true;
        digitalWrite(n_led, state_1);
      }
      if (tiempo_final - tiempo_inicial >= 400 && state_2 == false){
        n_led++;
        state_2 = true;
        digitalWrite(n_led, state_2);
      }
      if (tiempo_final - tiempo_inicial >= 600 && state_3 == false){
        n_led++;
        state_3 = true;
        digitalWrite(n_led, state_3);
      }
      if (tiempo_final - tiempo_inicial >= 800 && state_4 == false){
        n_led++;
        state_4 = true;
        digitalWrite(n_led, state_4);
      }
      if (tiempo_final - tiempo_inicial >= 1000){//Si ya se ejecutó la secuencia
        tiempo_inicial = tiempo_final; //actualiza el tiempo
        n_led = 8; //Regresa al pin 8
        apagarLeds(); //Apaga los LED
        paro_global++;  //Aumenta una ejecucion terminada
      }
    }   
}

void apagarLeds(){
  state_1 = false;
  state_2 = false;
  state_3 = false;
  state_4 = false;
  digitalWrite(LED1, state_1);
  digitalWrite(LED2, state_2);
  digitalWrite(LED3, state_3);
  digitalWrite(LED4, state_4);
}
