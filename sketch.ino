#define ECHO_PIN 2
#define TRIG_PIN 3
#define LED_RED_PIN 4
#define LED_GREEN_PIN 5
#define BUZZER_PIN 7

float calcDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    float duree = pulseIn(ECHO_PIN, HIGH);
    float dist = (duree * 0.034) / 2;
    
    return dist;
}

void alerte(int mode) {
    if(mode == 1) {
      tone(BUZZER_PIN, 600);
    }else {
      noTone(BUZZER_PIN);
    }
}

void allumerRouge() {
    digitalWrite(LED_RED_PIN, 1);
    alerte(1);
    digitalWrite(LED_GREEN_PIN, 0);
}

void allumerVerte() {
    digitalWrite(LED_RED_PIN, 0);
    digitalWrite(LED_GREEN_PIN, 1);
    alerte(0);
}

void setup() {
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    pinMode(LED_GREEN_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    float distance = calcDistance();
    Serial.print("Distance : ");
    Serial.print(distance);
    Serial.println("cm");

    if (int(distance) <= 20) {
        allumerRouge();
    }else {
      allumerVerte();
    }

    delay(500);
}