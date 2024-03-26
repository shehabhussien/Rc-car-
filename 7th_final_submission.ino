// Sensors
#define left 6
#define center 7
#define right 8

//motor one
#define ENA 9
#define IN1 2
#define IN2 3

//motor two
#define ENB 10
#define IN3 4
#define IN4 5

//Ultra sonic
const int trigPin = 12;
const int echoPin = 11;

int Speed = 120;

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  long duration, distance;
  bool leftV = digitalRead(left);
  bool centerV = digitalRead(center);
  bool rightV = digitalRead(right);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Serial.println(rightV);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance >= 30) {
   if (leftV == 1 && centerV == 0 && rightV == 1) {
    carforward();
    Serial.println("forward");
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carlafalafa();
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnright();
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnright();
  }
}
else{   
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
  }
  delay(20);
}
void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carlafalafa() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}