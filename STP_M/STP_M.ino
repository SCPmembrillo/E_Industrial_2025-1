// CONEXIONES
const int BUTTON = 2; //pin del botón
const int LED = 3; //pin del motor
// VARIABLES
int BUTTON_state_ant = LOW; //estado anterior del botón
int pulsos = 50; // 400/8 pulsos para 6 posiciones de medición 
void setup() {
  // Configuración de pines 
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Leyendo el estado del botón 
  int BUTTON_state_current = digitalRead(BUTTON);
  // Botón presionado
  if (BUTTON_state_current == HIGH && BUTTON_state_ant == LOW) {
    int contador = 0; // contador de pulsos 
    // Enviar la cantidad de pulsos especificada 
    while (contador < pulsos) {
      digitalWrite(LED, HIGH); // Subida pulso
      delay(5); // Duracion del pulso
      digitalWrite(LED, LOW); // Bajada pulso
      delay(5); // Intervalo entre pulsos
      contador = contador + 1; // Un pulso completado 
    }
  }
  // Se actualiza el estado del botón 
  BUTTON_state_ant = BUTTON_state_current;
}