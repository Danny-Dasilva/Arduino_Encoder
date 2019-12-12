// Danny Dasilva 

// pins for the encoder inputs
#define RH_ENCODER_A 3
#define RH_ENCODER_B 5
#define LH_ENCODER_A 2
#define LH_ENCODER_B 4
 
// variables to store the number of encoder pulses
// for each motor
volatile long leftCount = 0;
volatile long rightCount = 0;
 
void setup() {
  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
 
  // initialize hardware interrupts
  attachInterrupt(digitalPinToInterrupt(2), leftEncoderEvent, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), rightEncoderEvent, CHANGE);
 
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("a");
  Serial.print(rightCount);
  Serial.print("b");
  Serial.print(leftCount);
}
 
// encoder event for the interrupt call
void leftEncoderEvent() {
  if (digitalRead(LH_ENCODER_A) == HIGH) {
    if (digitalRead(LH_ENCODER_B) == LOW) {
      leftCount++;
    } else {
      leftCount--;
    }
  } else {
    if (digitalRead(LH_ENCODER_B) == LOW) {
      leftCount--;
    } else {
      leftCount++;
    }
  }
}

// encoder event for the interrupt call
void rightEncoderEvent() {
  if (digitalRead(RH_ENCODER_A) == HIGH) {
    if (digitalRead(RH_ENCODER_B) == LOW) {
      rightCount++;
    } else {
      rightCount--;
    }
  } else {
    if (digitalRead(RH_ENCODER_B) == LOW) {
      rightCount--;
    } else {
      rightCount++;
    }
  }
}

