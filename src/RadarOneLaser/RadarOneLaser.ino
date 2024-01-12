#include <Servo.h>
#include <math.h>

/** Macro pentru a definii distanța de la radar la limitele proximității pe care dorim să o verificăm. */ 
#define ACCEPTABLE_DISTANCE 30

/** Pinul digital pentru controlul laserului nr.1. */
#define LASER_FIRST 8

/** Pinul digital pentru controlul laserului nr.2. */
#define LASER_SECOND 4

/** Pinul digital pentru declanșarea senzorului cu ultrasunete. */
#define trig 13

/** Pinul digital pentru receptorul senzorului cu ultrasunete. */
#define echo 12

/** Macro pentru a definii înălțimea obiectelor pe care dorim să le lovim */ 
#define H_O 10.0

enum Direction {FORWARD, BACKWARDS};

Servo motorRadar;
Servo motorHorizontal;
Servo motorVertical;
Servo motorHorizontal2;
Servo motorVertical2;

/** Variabilă globală utilizată pentru stocarea versiunii reale a distanței de la radar la obiect. */
float distance = 0;

/** Variabilă globală utilizată pentru stocarea unghiului motorului Radar. */
int angleRadar = 0;

/** Variabilă globală utilizată pentru a reține dacă există obiecte in proximitate. */
bool safeMode = false;

/** Variabilă globală care se schimbă de la FALSE la TRUE când începe detectarea unui obiect
 *  și TRUE -> FALSE când detectarea s-a încheiat.
 */
bool flag;

bool isFirstLaserUsed;

/** Funcție utilizată pentru specificarea pinilor de control pentru motoare, lasere și ultrasunete, precum și tipul lor (INPUT sau OUTPUT) */
void setup() {
  motorRadar.attach(11);
  motorVertical.attach(10);
  motorHorizontal.attach(9);
  motorVertical2.attach(5);
  motorHorizontal2.attach(6);
  Serial.begin(9600);
  pinMode (LASER_FIRST, OUTPUT);
  pinMode (LASER_SECOND, OUTPUT);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
}

void loop() {

  /** Resetăm indicatorul, astfel știm că nu suntem în procesul de detectare repetata a niciunui obiect. */ 
  flag = false;

  /** La început, presupunem că nu sunt detectate obiecte. */  
  safeMode = true;

  isFirstLaserUsed = false;

  /** Radarul urmeaza sa parcurga  150 cu ajutorul motorului căruia îi este atașat. */  
  for(angleRadar = 15; angleRadar <= 165; angleRadar += 1){
    motorRadar.write(angleRadar);
    
    /** Verificam dacă am detectat vreun obiect în proximitatea setată, în caz contrar
    *   resetam indicatorul pentru a marca ca nu suntem in timpul descoperirii
    *   nici unui obiect.
     */
    if(checkRadar() < ACCEPTABLE_DISTANCE){
      
      /** Verificam dacă obiectul descoperit e nou, sau continuăm să descoperim obiectul anterior. 
      *   În caz că e nou, urmează să țintim laserul asupra lui și să îi marcăm apariția.
      */
      if(flag == false) {
        moveLaser(FORWARD);
        moveSecondLaser(FORWARD);
        flag = true;
      } 
    }
    else flag = false;

    Serial.print(angleRadar); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print((int)distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

    /** Aștem ca toate motoarele să ajungă în poziția setată */
    delay(30); 
  }
  delay(500);

  /** Dacă nici un obiect nu a fost detectat în proximitate, oprim ambele lasere */
  if (safeMode == true) {
    digitalWrite(LASER_FIRST, LOW);
    digitalWrite(LASER_SECOND, LOW);
  }

  /** Resetem indicatoarele înainte de a pornii inapoi cu motorul radarului */
  safeMode = true;
  flag = false;

  /** În primul for am parcurs drumul "Dus" cu radarul, urmând să ne întoarcem la poziția inințială*/
  for( angleRadar = 165; angleRadar >= 15; angleRadar -= 1){
    motorRadar.write(angleRadar);

    /** Verificam dacă am detectat vreun obiect în proximitatea setată, în caz contrar
    *   resetam indicatorul pentru a marca ca nu suntem in timpul descoperirii
    *   nici unui obiect.
     */
    if(checkRadar() < ACCEPTABLE_DISTANCE){
      
      /** Verificam dacă obiectul descoperit e nou, sau continuăm să descoperim obiectul anterior. 
      *   În caz că e nou, urmează să țintim laserul asupra lui și să îi marcăm apariția.
      */
      if(flag == false) {
        moveLaser(BACKWARDS);
        moveSecondLaser(BACKWARDS);
        flag = true;
      } 
    } 
    else flag = false;

    Serial.print(angleRadar); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print((int)distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

    /** Aștem ca toate motoarele să ajungă în poziția setată */
    delay(30); 
  }
  delay(500);

  /** Dacă nici un obiect nu a fost detectat în proximitate, oprim ambele lasere */
  if (safeMode == true) {
    digitalWrite(LASER_FIRST, LOW);
    digitalWrite(LASER_SECOND, LOW);
  }
}

/** Funcție care măsoară distanța de la radar la obiect.
*   Returnează conversia distanței din număr real, în număr întreg pentru a ușura verificare.
*/
int checkRadar(){

  /** Pentru declanșa senzorul ultrasonic, trebuie să trimitem un puls HIGH de 10 ms
  *   pentru pin-ul TRIG.
  */
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  /** Senzorul ne va returna prin pin-ul ECHO, un puls HIGH egal cu durata (în μs)
  *   egală cu timpul în care unda sonică trimisăa ajuns înapoi la receiver
  */
  float duration = pulseIn(echo, HIGH);

  /** Pentru a calcula distanța ne folosim de faptul că unda sonică a facut doua drumuri (DUS-ÎNTORS)
  *   cu viteza sunetului (aprox. 343 m/s) până să se întoarcă la receiver. 
  *   d = v * t
  *   viteza sunetului e 343 de m/s, adică 0.034 cm/μs, deci
  *   distanța * 2 = 0.034 * durată
  *   distanță = 0.017  durată.
  */
  distance = 0.017 * duration;

  return distance;
}

/** Macro pentru a definii distanța măsurată la montare, dintre motorul primului laser și motorul radarului */ 
#define DIST_L_R 4.5

/** Macro pentru a definii distanța măsurată la montare, dintre motorul celui de al doilea laser și motorul radarului */ 
#define DIST_L_R2 10.0

/** Macro pentru a definii distanța măsurată la montare, dintre centrul mecanismului de rotire al motorului laserului, și laserul în sine */ 
#define DIST_M_L 3.5

/** Macro pentru a definii înălțimea la care se află primul laser */ 
#define HL1 10.0

/** Macro pentru a definii înălțimea la care se află al doilea laser laser */ 
#define HL2 15.5

/** Funcție care țintește laserul asupra obicetului detectat */
void moveLaser(Direction direction){

  /** Dacă un obiect se află în proximitate, setăm senzorul de proximitate
  *   și pornim laserele.
  */
  safeMode = false;
  digitalWrite(LASER_FIRST, HIGH);
  digitalWrite(LASER_SECOND, HIGH);

  /** În urma testelor am observat că obiectul va fi detectat înainte ca motorul laserului să fie direct pe traictoria obiectului,
  *   iar unghiul aproximativ este cu 20 de grade mai mare decât unghiul actual al motorului radarului.
  */
  float deviated;
  if (direction == FORWARD) deviated = angleRadar + 20;
  else deviated = angleRadar - 15;

  /** Împărțim soluția în trei cazuri, unul pentru fiecare formulă demostrată anterior
  *   Unghiurile noastre sunt măsurate în grade, iar funcția cos primește ca parametru
  *   unghiul măsurat în radiani deci întainte de fieacre cos(), trebuie să facem transformarea.
  *   La fel si DUPĂ fiecare arccos care returnează un unghi măsurat în radiani.
  *   x rad = x * 57.29 grade 
  */
  float b;
  if(deviated == 90) {  
    b = DIST_L_R + distance;  
    float beta = deviated; 
    float d = sqrt(12.25 + b * b - 7 * b * cos ((180 - beta) / 57.29));
    int teta = acos(DIST_M_L/d) * 57.29;
    motorHorizontal.write(teta);
  }
  else if( deviated < 90 ) {
    float a = distance * cos ((deviated)/57.29);
    b = sqrt(DIST_L_R * DIST_L_R - 2 * DIST_L_R * distance * cos ((90+deviated)/57.29) + distance * distance); 
    float beta = acos(a/b) * 57.29;
    float d = sqrt(DIST_M_L * DIST_M_L + b * b - 7 * b * cos ((180 - beta) / 57.29));
    int teta = acos((DIST_M_L+a)/d) * 57.29;
    motorHorizontal.write(teta);
  }
  else
  {
    /** în cazul în care obiectul se află în jumătatea stângă a proximității, unghiul detectării va crește cu ÎNCĂ 10 grade din cauză că
    *   receiverul este mai aproape de obiect.
    */
   //if (direction == FORWARD) deviated += 10;

    b =sqrt(DIST_L_R * DIST_L_R - 2 * DIST_L_R * distance * cos ((270-deviated)/57.29) + distance * distance);
    float beta= acos((b*b + DIST_L_R * DIST_L_R - distance * distance) / (2 * b * DIST_L_R)) * 57.29;
    float d = sqrt(DIST_M_L * DIST_M_L + b * b - 7 * b * cos ((90 - beta) / 57.29));
    int teta = acos((d*d + DIST_M_L * DIST_M_L - b*b) / (2 * d * DIST_M_L)) * 57.29;
    motorHorizontal.write(teta-5);
  }

  float distanceFirstLaserToObject = sqrt(b*b + (HL1 - H_O) * (HL1 - H_O)) ;
  float gama = acos((HL1 - H_O) / distanceFirstLaserToObject) * 57.29;
  motorVertical.write(180-gama);
}

void moveSecondLaser(Direction direction){

  /** Dacă un obiect se află în proximitate, setăm senzorul de proximitate
  *   și pornim laserele.
  */
  safeMode = false;
  digitalWrite(LASER_FIRST, HIGH);
  digitalWrite(LASER_SECOND, HIGH);

  /** În urma testelor am observat că obiectul va fi detectat înainte ca motorul laserului să fie direct pe traictoria obiectului,
  *   iar unghiul aproximativ este cu 20 de grade mai mare decât unghiul actual al motorului radarului.
  */
  float deviated;
  if (direction == FORWARD) deviated = angleRadar + 20;
  else deviated = angleRadar - 30;
  
  float b;
  /** Împărțim soluția în trei cazuri, unul pentru fiecare formulă demostrată anterior
  *   Unghiurile noastre sunt măsurate în grade, iar funcția cos primește ca parametru
  *   unghiul măsurat în radiani deci întainte de fieacre cos(), trebuie să facem transformarea.
  *   La fel si DUPĂ fiecare arccos care returnează un unghi măsurat în radiani.
  *   x rad = x * 57.29 grade 
  */
  if(deviated == 90) {  
     b = DIST_L_R2 + distance;  
    float beta = deviated; 
    float d = sqrt(12.25 + b * b - 7 * b * cos ((180 - beta) / 57.29));
    int teta = acos(DIST_M_L/d) * 57.29;
    motorHorizontal2.write(teta);
  }
  else if( deviated < 90 ) {
    float a = distance * cos ((deviated)/57.29);
     b = sqrt(DIST_L_R2 * DIST_L_R2 - 2 * DIST_L_R2 * distance * cos ((90+deviated)/57.29) + distance * distance); 
    float beta = acos(a/b) * 57.29;
    float d = sqrt(DIST_M_L * DIST_M_L + b * b - 7 * b * cos ((180 - beta) / 57.29));
    int teta = acos((DIST_M_L+a)/d) * 57.29;
    motorHorizontal2.write(teta + 8);
  }
  else
  {
    /** în cazul în care obiectul se află în jumătatea stângă a proximității, unghiul detectării va crește cu ÎNCĂ 10 grade din cauză că
    *   receiverul este mai aproape de obiect.
    */
   if (direction == FORWARD) deviated += 10;

    float a=distance*cos((180-deviated)/57.29);
     b=sqrt(DIST_L_R2 * DIST_L_R2 - 2 * DIST_L_R2 * distance * cos ((270-deviated)/57.29) + distance * distance);
    float beta= acos((b*b + DIST_L_R2 * DIST_L_R2 - distance * distance) / (2 * b * DIST_L_R2)) * 57.29;
    float d = sqrt(DIST_M_L * DIST_M_L + b * b - 7 * b * cos ((90 - beta) / 57.29));
    int teta = acos((d*d + DIST_M_L * DIST_M_L - b*b) / (2 * d * DIST_M_L)) * 57.29;
    motorHorizontal2.write(teta-16);
  }

  float distanceSecondLaserToObject = sqrt(b*b + (HL2 - H_O) * (HL2 - H_O));
  float gama = acos((HL2 - H_O) / distanceSecondLaserToObject) * 57.29 ;
  motorVertical2.write(180-gama);
}
