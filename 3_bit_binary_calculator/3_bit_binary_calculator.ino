int A4pin=A5;   //Set all pins as global variables
int A2pin=A3;
int A1pin=A1;

int B4pin=2;
int B2pin=4;
int B1pin=6;

int out8=10;
int out4=11;
int out2=12;
int out1=13;


void setup() {
  Serial.begin(9600); //turn on serial port
  pinMode(A4pin,INPUT);  //set all input pins to input
  pinMode(A2pin,INPUT);
  pinMode(A1pin,INPUT);
  
  pinMode(B4pin,INPUT);
  pinMode(B2pin,INPUT);
  pinMode(B1pin,INPUT);
  

  pinMode(out8,OUTPUT); //set all output pins to output
  pinMode(out4,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out1,OUTPUT);
}

void loop() {
  int A4val=0;   //Set all read values as local variables
  int A2val=0;
  int A1val=0;
  
  int B4val=0;
  int B2val=0;
  int B1val=0;
  
 
  int Aval;  //Set A and B values as local variables
  int Bval;

  int outval; //Set output value as local variable


  A4val = digitalRead(A4pin); //Set the variable of input to read value
  A2val = digitalRead(A2pin);
  A1val = digitalRead(A1pin);
  
  B4val = digitalRead(B4pin);
  B2val = digitalRead(B2pin);
  B1val = digitalRead(B1pin);

  int A4valcal = A4val;   //setting variables for inverting
  int A2valcal = A2val;
  int A1valcal = A1val;

  int B4valcal = B4val;
  int B2valcal = B2val;
  int B1valcal = B1val;
 
  

  if (A4val==0){      //inverting signal
    A4valcal = 1;
  }

  if (A4val==1){
    A4valcal = 0;
  }


  if (A2val==0){
    A2valcal = 1;
  }

  if (A2val==1){
    A2valcal = 0;
  }


  if (A1val==0){
    A1valcal = 1;
  }

  if (A1val==1){
    A1valcal = 0;
  }



  if (B4val==0){
    B4valcal = 1;
  }

  if (B4val==1){
    B4valcal = 0;
  }


  if (B2val==0){
    B2valcal = 1;
  }

  if (B2val==1){
    B2valcal = 0;
  }


  if (B1val==0){
    B1valcal = 1;
  }

  if (B1val==1){
    B1valcal = 0;
  }


  A4val = A4valcal;   //setting A and B value to inverted value
  A2val = A2valcal;
  A1val = A1valcal;

  B4val = B4valcal;
  B2val = B2valcal;
  B1val = B1valcal;
 
  

  Serial.print("A = ");     //printing binary values of A and B
  Serial.print(A4val);
  Serial.print(A2val);
  Serial.println(A1val);
  
  

  Serial.print("B = ");
  Serial.print(B4val);
  Serial.print(B2val);
  Serial.println(B1val);
  

  Aval=(A4val*4)+(A2val*2)+(A1val*1);  //Changing binary value to decimal value
  Bval=(B4val*4)+(B2val*2)+(B1val*1);

  outval=Aval+Bval;    //calculate total value

  Serial.println("total = ");   //printing total value in serial port to check
  Serial.println(outval);
  Serial.println("");
  
  digitalWrite(out8,LOW);     //reseting output LEDs
  digitalWrite(out4,LOW);
  digitalWrite(out2,LOW);
  digitalWrite(out1,LOW);

  if (outval>=8) {                  //converting from decimal to binary then output
    digitalWrite(out8,HIGH);
    outval=outval-8;
  }
  
  if (outval>=4) {              
    digitalWrite(out4,HIGH);
    outval=outval-4;
  }
  
  if (outval>=2) {              
    digitalWrite(out2,HIGH);
    outval=outval-2;
  }
  

  if (outval>=1) {              
    digitalWrite(out1,HIGH);
    outval=outval-1;
  }
 
  
  
  
 
}
