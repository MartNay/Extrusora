// Definição dos pinos
#define stepPinX 2   // Passo eixo X
#define dirPinX 5    // Direção eixo X
#define stepPinZ 4   // Z.STEP
#define dirPinZ 7    // Z.DIR

// Definição de velocidades para cada motor
int speedX = 3760;  // Ajuste a velocidade do motor X conforme necessário
int speedZ = 11600;   // Ajuste a velocidade do motor Z conforme necessário

void setup() {
  Serial.begin(9600);
  Serial.println("Inicializando...");

  pinMode(8, OUTPUT);  // MS1
  pinMode(9, OUTPUT);  // MS2
  pinMode(10, OUTPUT); // MS3

  digitalWrite(8, LOW);  // MS1
  digitalWrite(9, LOW);  // MS2
  digitalWrite(10, LOW); // MS3

  Serial.println("Pronto para começar!");
}

void moveMotor(int stepPin, int speed) {
  unsigned long currentMicros = micros();

  // Move o motor
  for (int x = 0; x < 1600; x++) {
    if (micros() - currentMicros >= speed) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(1);
      digitalWrite(stepPin, LOW);
      currentMicros = micros();
    }
  }
}

void loop() {
  // Habilita os motores para que se movimentem em um sentido particular
  digitalWrite(dirPinX, HIGH);
  digitalWrite(dirPinZ, HIGH);

  // Move ambos os motores
  moveMotor(stepPinX, speedX);
  moveMotor(stepPinZ, speedZ);
}
