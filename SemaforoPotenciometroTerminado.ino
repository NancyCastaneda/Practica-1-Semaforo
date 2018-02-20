int pulsador = 2;      //Pin donde se encuentra el pulsador, entrada
//------------------------SEMAFORO CARROS-----------------------------
int led = 13;          //Pin donde se encuentra el LED Rojo, entrada
int led2 = 12;         //Pin donde se encuentra el LED Amarillo, entrada
int led3 = 8;          //Pin donde se encuentra el LED Verde, entrada
//------------------------SEMAFORO PEATON-----------------------------
int led4 = 7;          //Pin donde se encuentra el LED Rojo, entrada
int led5 = 4;          //Pin donde se encuentra el LED Verde, entrada

int valorP;            //Variable para almacenar el valor del potenciometro

long inicio = 0;       //Variable para almacenar el tiempo de inicio de ejecución de luz verde de semaforo de carro (fin de semaforo peaton)
unsigned long fin;     //Variable para almacenar el tiempo actual
long transcurrido;     //Variable para almacenar el tiempo transcurrido desde el ultimo cambio de semaforo de peaton & tiempo de ejecución actual

void setup() {
  pinMode(pulsador, INPUT); //Configurar el pulsador como una entrada
  //---------------//Configurar los LEDs como una salidas--------------------
  pinMode(led, OUTPUT);     
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {

  fin = millis();          //Tiempo actual

  valorP = analogRead(A0); //Entrada
    
  if (digitalRead(pulsador) == HIGH)    {  //Pulsador oprimido 
    transcurrido = fin - inicio;           //Tiempo transcurrido
    if(transcurrido < 10000)               //Se establece un tiempo minimo de cambio de semaforo de carro a peaton de 10 segundos, si el tiempo transcurrido es menor
      delay(10000 - transcurrido);         //Se calcula y establece un retardo para asegurar los 10 segundos, de modo contrario el flujo continua  


    //------------------------SEMAFORO CARROS-----------------------------
    digitalWrite(led3, LOW);  //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led3, HIGH); //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led3, LOW);  //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led3, HIGH); //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos    
    digitalWrite(led3, LOW);  //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led3, HIGH); //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    
    digitalWrite(led, LOW);   //Apaga el LED Rojo
    digitalWrite(led2, HIGH); //Enciende el LED Amarillo
    digitalWrite(led3, LOW);  //Apaga el LED Verde

    //------------------------SEMAFORO PEATON-----------------------------    
    digitalWrite(led4, HIGH); //Enciende el LED Rojo
    digitalWrite(led5, LOW);  //Apaga el LED Verde
    
    delay(valorP + 1000);     //Retardo de 1 segundo + el valor del potenciometro

    //------------------------SEMAFORO CARROS-----------------------------
    digitalWrite(led, HIGH);  //Enciende el LED Rojo
    digitalWrite(led2, LOW);  //Apaga el LED Amarillo
    digitalWrite(led3, LOW);  //Apaga el LED Verde

    //------------------------SEMAFORO PEATON-----------------------------
    digitalWrite(led4, LOW); //Apaga el LED Rojo
    digitalWrite(led5, HIGH);//Enciende el LED Verde
    delay(valorP + 4000);    //Retardo de 4 segundos + el valor del potenciometro

    digitalWrite(led5, LOW);  //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led5, HIGH); //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led5, LOW);  //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led5, HIGH); //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos    
    digitalWrite(led5, LOW);  //Apaga el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led5, HIGH); //Enciende el LED Verde
    delay(500);               //Retardo de 0.5 segundos
    digitalWrite(led5, LOW);  //Apaga el LED Verde
    
    inicio = millis();        //Se almacena el tiempo de ejecución de inicio de semaforo carro al finalizar semaforo peaton
    
  }    
  else    {      //Pulsador NO oprimido (estado normal)
    //------------------------SEMAFORO CARROS-----------------------------
    digitalWrite(led, LOW);   //Apaga el LED Verde
    digitalWrite(led2, LOW);  //Apaga el LED Amarillo
    digitalWrite(led3, HIGH); //Enciende el LED Verde

    //------------------------SEMAFORO PEATON-----------------------------
    digitalWrite(led4, HIGH); //Enciende el LED Rojo
    digitalWrite(led5, LOW);  //Enciende el LED Verde
    //delay(valorP + 4000);    //Retardo de 4 segundos + el valor del potenciometro
  }
}
