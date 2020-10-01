//To run a bot in a straight line using incremental rotary encoders

//pins declarations for LEFT and RIGHT wheels

int leftmotor = 12; 
int pullup_left = 4; 

int rightmotor = 11; 
int pullup_right = 5;

int encoder_pin = 7;  //pin for rotary encoder

volatile int left_counter = 0; //counter variable for left motor
volatile int right_counter = 0; //counter variable for right motor

void setup() 
{
  pinMode(leftmotor, OUTPUT);
  pinMode(rightmotor, OUTPUT);

  pinMode(encoder_pin, OUTPUT);
  digitalWrite(encoder_pin, HIGH);

  pinMode(4, INPUT_PULLUP); //for LEFT wheel 
  attachInterrupt(2, blinkleft, CHANGE); //interrupt for LEFT wheel

  pinMode(5, INPUT_PULLUP); //for RIGHT wheel
  attachInterrupt(3, blinkright, CHANGE); //interrupt for RIGHT wheel

  digitalWrite(leftmotor, HIGH);
  digitalWrite(rightmotor, HIGH);
}

void loop() 
{
  if ((left_counter - right_counter) > 10) //if the LEFT wheel moves in a greater speed than that of RIGHT wheel
  {
    while (left_counter != right_counter) // then the LEFT motor will stop till both the counter variables becomes equal
    {
      digitalWrite(leftmotor, LOW);
    }
    digitalWrite(leftmotor, HIGH);
  } 
  else if ((right_counter - left_counter) > 10)//if the RIGHT wheel moves in a greater speed than that of LEFT wheel 
  {
    while (right_counter != left_counter) //then the RIGHT motor will stop till both the counter variables becomes equal
    {
      digitalWrite(rightmotor, LOW);
    }
    digitalWrite(rightmotor, HIGH);
  }
  else //Everything seems good and bot is moving pseudo-straight
  {
    digitalWrite(rightmotor, HIGH);
    digitalWrite(leftmotor, HIGH);
  }

}

void blinkleft() 
{
  left_counter++; // left_counter is incremented by 1 when interrupt occurs in LEFT motor
}

void blinkright() 
{
  right_counter++; // right_counter is incremented by 1 when interrupt occurs in RIGHT motor
}
