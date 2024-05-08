// Karen Cruz 2024

//Include LiquidCrystal libreries
#include <LiquidCrystal.h>
#include <Wire.h>

//Crear el objeto lcd  dirección  32 (depende del modelo) y 16 columnas x 2 filas
LiquidCrystal lcd(32,16,2);  //

// Pin definition for LCD screen
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Definition of pins and variables for the temperature sensor and the water pump
const int sensorPin = A0; // Analog pin for temperature sensor
const int bombaPin = 9;    // Digital pin for water pump
int Temperatura;           // Any data type for measured temperature variable

// Definition of the states
enum Estado { 
  SENSOR_ACTIVADO
  ANALISIS_TEMPERATURA
  REMAPEO_VALORES
  ACTIVACION
  DESACTIVACION
  ENVIO_DATOS_NUBE}; 

Estado estado=SENSOR_ACTIVADO; //Initial state

unsigned long tiempoUltimaLectura = 0; // Variable to record the time of the last sensor reading
const unsigned long intervaloLectura = 30 * 60 * 1000; // Reading interval: 30 minutes in milliseconds


void setup() {
	// LCD screen initialization
	lcd.begin(16, 2);
  
	// Water pump pin initialization
  pinMode(bombaPin, OUTPUT);
  }


void loop() {
  // Check if the time has passed to take a new sensor reading
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoUltimaLectura >= intervaloLectura) {
    // Update last reading time
    tiempoUltimaLectura = tiempoActual;
    
    // Change the state to SENSOR_ACTIVADO to start a new sensor reading
    estado = SENSOR_ACTIVADO;
  }


void loop() {
  // Call the function corresponding to the current state
  switch (estado) {
    case SENSOR_ACTIVADO:
      sensorActivado();
      break;
    case ANALISIS_TEMPERATURA:
      analisisTemperatura();
      break;
    case REMAPEO_VALORES:
      remapeoValores();
      break;
    case ACTIVACION:
      activacion();
      break;
    case DESACTIVACION:
      desactivacion();
      break;
    case ENVIO_DATOS_NUBE:
      envioDatosNube();
      break;
  }
}


void sensorActivado() {
  // Show message on LCD screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sensor activado");
  
  // Switch to next state after a while
  delay(2000); // Wait 2 seconds
  estado = ANALISIS_TEMPERATURA;
}


void analisisTemperatura() {
    
  // Switch to next state after a while
  delay(2000); // Wait 2 seconds
  estado = REMAPEO_VALORES;
}


void remapeoValores() {
  // Temperature sensor reading
  int lecturaSensor = analogRead(sensorPin);
  
  // Remapping values to temperature
  float temperatura = map(lecturaSensor, 0, 1023, -80, 150);





}

void loop() {

lcd.clear();
lcd.setCursor (0, 0);
lcd.print("Temperatura");
lcd.setCursor(0, 1);
lcd.print(Termistor);
delay()


}
