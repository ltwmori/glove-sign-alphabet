// Pin connected to voltage divider output
const int flexPin1 = A0; 
const int flexPin2 = A1;
const int flexPin3 = A2;
const int flexPin4 = A3;
const int flexPin5 = A4;

// Change these constants according to your project's design
const float VCC = 5; // voltage at Ardunio 5V line
const float R_DIV = 47000.0; // resistor used to create a voltage divider
const float flatResistance = 22000.0; // resistance when flat
const float bendResistance = 70000.0; // resistance at 90 deg
char temp = '0';

void setup() {
    Serial.begin(9600);
}

String s = "";

void printfun(char cp){
    //to avoid printing repeating symbols
    if(cp!=temp){
        Serial.println(cp);
        temp=cp;
        s+=temp;
    }
    
}
void loop() {
    // Read the ADC, and calculate voltage and resistance from it
    float ADCflex1 = analogRead(flexPin1);
    float ADCflex2 = analogRead(flexPin2);
    float ADCflex3 = analogRead(flexPin3);
    float ADCflex4 = analogRead(flexPin4);
    float ADCflex5 = analogRead(flexPin5);
    //Serial.println(ADCflex1);
    float Vflex1 = ADCflex1 * VCC / 1023.0;
    //Serial.println(Vflex1);
    float Rflex1 = 30000.0 * (VCC / Vflex1 - 1.0);
    //Serial.println(Rflex1);
    float angle1 = map(Rflex1, flatResistance, bendResistance, 0, 90.0);
    
    float Vflex2 = ADCflex2 * VCC / 1023.0;
    float Rflex2 = 30000.0 * (VCC / Vflex2 - 1.0);
    float angle2 = map(Rflex2, flatResistance, bendResistance, 0, 90.0);
    
    float Vflex3 = ADCflex3 * VCC / 1023.0;
    float Rflex3 = R_DIV * (VCC / Vflex3 - 1.0);
    float angle3 = map(Rflex3, flatResistance, bendResistance, 0, 90.0);
    
    float Vflex4 = ADCflex4 * VCC / 1023.0;
    float Rflex4 = R_DIV * (VCC / Vflex4 - 1.0);
    float angle4 = map(Rflex4, flatResistance, bendResistance, 0, 90.0);
    
    float Vflex5 = ADCflex5 * VCC / 1023.0;
    float Rflex5 = R_DIV * (VCC / Vflex5 - 1.0);
    float angle5 = map(Rflex5, flatResistance, bendResistance, 0, 90.0);
   
    if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('A');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('B');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('C');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('D');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('E');
    
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('F');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('G');
    else if (angle1 > -10 && angle1 < 15 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('H');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('I');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('J');
    
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('K');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('L');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('M');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('N');
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('O');
    
    else if (angle1 > -10 && angle1 < 15 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('P');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('Q');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('R');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('S');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > -10 && angle3 < 15 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('T');
    
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('U');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('V');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15) printfun('W');
    else if (angle1 > 30 && angle1 < 150 && angle2 > -10 && angle2 < 15 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun('X');
    else if (angle1 > 30 && angle1 < 150 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > -10 && angle5 < 15) printfun('Y');
    else if (angle1 > 30 && angle1 < 150 && angle2 > 30 && angle2 < 150 && angle3 > -10 && angle3 < 15 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) printfun('Z');

    else if (angle1 > 30 && angle1 < 150 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > 30 && angle5 < 150) printfun(' ');
    else if (angle1 > 30 && angle1 < 150 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > 30 && angle4 < 150 && angle5 > -10 && angle5 < 15){
        String temp = "";
        for(int i=0;i<s.length()-1;i++){
            temp+=s[i];  
        }
        s=temp;
        Serial.println(s);
    }
    else if (angle1 > 30 && angle1 < 150 && angle2 > 30 && angle2 < 150 && angle3 > 30 && angle3 < 150 && angle4 > -10 && angle4 < 15 && angle5 > 30 && angle5 < 150) {
        Serial.println(s);
    }
    delay(1000);
}
