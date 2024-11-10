    // Grupo Oceano
    // Antonia Salazar, Beatriz Toledo, Benjamín Sanchez y Constanza Torres

#define REMOTEXY_MODE__WIFI_POINT
#include <ESP8266WiFi.h>
#include <RemoteXY.h>

    // Nombre del WIFI y contraseña
const char* ssid = "bulbasaur";
const char* password = "pikachu12";
WiFiServer server(80);

    // Pins 
const int PWMA = 15;
const int AIN1 = 14;
const int AIN2 = 12;
const int PWMB = 13;
const int BIN1 = 4;
const int BIN2 = 5;

    // RemoteXY GUI config
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 1604 bytes
  { 255,16,0,0,0,61,6,19,0,0,0,0,16,2,106,200,200,80,7,1,
  0,0,0,0,0,0,20,0,5,6,15,150,150,127,12,52,52,32,186,198,
  31,1,26,18,60,60,46,41,21,21,0,197,244,83,84,79,80,0,1,21,
  23,60,60,27,22,25,9,2,129,244,0,1,239,13,60,60,14,38,14,27,
  1,187,31,0,129,248,105,73,30,26,14,26,8,64,244,84,85,82,66,79,
  0,129,249,103,73,30,41,44,6,15,0,129,40,0,129,47,130,13,38,67,
  44,6,15,0,129,41,0,129,3,95,73,30,116,33,8,12,64,127,226,134,
  186,0,129,2,90,73,30,180,33,8,12,64,127,226,134,187,0,129,0,105,
  73,30,148,6,13,13,64,244,226,140,131,0,129,75,50,24,33,149,58,9,
  14,64,244,226,140,132,0,129,248,148,73,30,54,18,4,12,64,244,33,0,
  129,19,33,8,30,21,16,3,12,64,244,194,161,0,129,255,80,73,30,16,
  43,11,18,64,196,226,134,165,0,129,248,130,40,20,30,38,5,8,64,199,
  70,0,129,21,110,12,20,30,45,5,8,64,199,76,0,129,23,115,11,20,
  30,52,3,8,64,199,73,0,129,26,120,6,20,30,59,6,8,64,199,80,
  0,131,29,30,21,35,87,2,13,12,2,16,2,31,226,154,153,239,184,143,
  0,154,42,131,40,15,8,38,102,2,12,12,2,16,16,244,63,0,106,42,
  20,0,5,20,35,130,130,16,14,52,52,32,186,198,31,1,29,125,60,60,
  131,40,21,21,0,197,244,83,84,79,80,0,1,12,52,13,23,145,21,25,
  9,2,129,244,0,1,14,102,7,68,165,38,14,27,1,187,31,0,129,243,
  33,64,20,144,13,26,8,64,244,84,85,82,66,79,0,129,45,137,13,38,
  126,43,6,15,0,129,40,0,129,60,137,14,38,152,43,6,15,0,129,41,
  0,129,93,88,19,30,6,34,8,12,64,127,226,134,186,0,129,59,88,19,
  30,69,34,8,12,64,127,226,134,187,0,129,71,20,31,33,37,8,13,13,
  64,244,226,140,131,0,129,75,150,22,35,38,60,9,14,64,244,226,140,132,
  0,129,24,43,8,30,172,17,4,12,64,244,33,0,129,6,38,8,30,140,
  15,3,12,64,244,194,161,0,129,4,115,28,45,167,43,11,18,64,196,226,
  134,165,0,129,18,103,12,20,181,38,5,8,64,199,70,0,129,18,120,11,
  20,181,45,5,8,64,199,76,0,129,20,138,6,20,181,52,3,8,64,199,
  73,0,129,17,155,13,20,180,58,6,8,64,199,80,0,131,47,10,7,30,
  87,2,13,12,2,16,2,31,226,154,153,239,184,143,0,154,42,131,55,10,
  6,30,102,2,12,12,2,16,16,244,63,0,106,42,3,0,131,27,108,21,
  35,49,39,48,16,2,254,244,31,105,122,113,117,105,101,114,100,97,0,166,
  42,131,49,80,21,35,102,39,45,16,2,114,104,31,100,101,114,101,99,104,
  97,0,169,42,129,18,43,73,30,66,25,60,12,64,27,109,97,110,111,32,
  104,195,161,98,105,108,0,5,0,131,35,88,21,35,81,24,40,14,2,115,
  90,31,106,111,121,115,116,105,99,107,0,170,41,129,11,28,73,30,78,10,
  46,12,64,187,72,79,87,32,84,79,0,131,44,50,21,35,81,40,40,14,
  2,198,213,31,115,116,111,112,0,170,38,131,44,93,21,35,81,56,40,14,
  2,254,255,31,116,117,114,98,111,0,170,26,131,9,35,21,35,4,4,14,
  13,2,243,254,31,226,156,150,0,154,0,11,0,5,233,18,150,150,44,28,
  38,38,0,244,26,31,129,73,20,19,33,59,23,13,13,64,244,226,140,131,
  0,129,72,150,21,35,59,58,9,14,64,244,226,140,132,0,129,53,65,73,
  30,25,10,77,4,0,228,77,111,118,105,109,105,101,110,116,111,115,32,101,
  110,32,101,108,32,101,106,101,32,121,32,101,115,116,195,161,110,32,114,101,
  108,97,99,105,111,110,97,100,111,115,0,129,215,18,191,10,32,15,62,4,
  0,228,99,111,110,32,101,108,32,97,118,97,110,99,101,32,121,32,114,101,
  116,114,111,99,101,115,111,32,100,101,108,32,114,111,98,111,116,0,5,255,
  50,110,110,120,28,38,38,0,115,26,31,129,57,88,25,30,159,40,8,12,
  64,127,226,134,187,0,129,25,88,25,30,110,40,8,12,64,127,226,134,186,
  0,129,200,30,191,10,105,10,68,4,0,88,80,111,114,32,111,116,114,111,
  32,108,97,100,111,44,32,99,111,110,32,101,108,32,101,106,101,32,120,32,
  115,101,32,99,111,110,116,114,111,108,97,110,0,129,247,30,169,10,109,15,
  60,4,0,88,108,111,115,32,109,111,118,105,109,105,101,110,116,111,115,32,
  100,101,32,103,105,114,111,32,100,101,108,32,114,111,98,111,116,0,131,4,
  17,7,33,4,4,14,13,2,243,254,31,226,172,133,0,106,42,8,0,131,
  3,10,7,33,4,4,14,13,2,243,254,31,226,172,133,0,106,42,1,5,
  107,53,53,90,39,27,27,0,197,244,83,84,79,80,0,129,18,115,13,38,
  85,44,7,18,0,129,40,0,129,31,115,14,38,116,44,7,18,0,129,41,
  0,129,18,33,73,30,46,14,112,6,0,174,69,108,32,98,111,116,195,179,
  110,32,100,101,32,83,84,79,80,32,102,117,110,99,105,111,110,97,32,115,
  111,108,111,32,99,117,97,110,100,111,32,108,111,0,129,200,40,255,15,30,
  21,29,6,64,244,109,97,110,116,105,101,110,101,115,0,129,253,53,71,15,
  60,21,114,6,0,174,97,112,114,101,116,97,100,111,44,32,100,101,32,101,
  115,116,97,32,109,97,110,101,114,97,32,108,111,115,32,109,111,118,105,109,
  105,101,110,116,111,115,0,129,200,50,255,15,34,28,134,6,0,174,100,101,
  108,32,106,111,121,115,116,105,99,107,32,115,101,32,118,101,114,195,161,110,
  32,97,110,117,108,97,100,111,115,32,109,105,101,110,116,114,97,115,32,108,
  111,32,97,112,114,105,101,116,101,115,0,8,0,1,15,60,13,23,87,52,
  28,10,2,129,244,0,129,246,40,64,20,86,42,29,9,64,244,84,85,82,
  66,79,0,129,27,50,8,30,117,46,4,14,64,244,33,0,129,9,45,8,
  30,81,43,4,14,64,244,194,161,0,131,3,15,7,33,4,4,14,13,2,
  243,254,31,226,172,133,0,106,42,129,200,40,255,15,33,16,138,6,0,89,
  69,108,32,98,111,116,195,179,110,32,100,101,32,84,85,82,66,79,32,102,
  117,110,99,105,111,110,97,32,97,108,32,109,97,110,116,101,110,101,114,32,
  97,112,114,101,116,97,100,111,32,121,0,129,200,43,255,15,33,23,141,6,
  0,89,115,111,108,111,32,115,105,32,115,101,32,101,115,116,97,32,117,115,
  97,110,100,111,32,101,108,32,106,111,121,115,116,105,99,107,44,32,121,97,
  32,113,117,101,32,97,109,112,108,105,102,105,99,97,114,97,32,0,129,200,
  58,255,15,54,30,96,6,0,89,108,97,32,118,101,108,111,99,105,100,97,
  100,32,100,101,32,100,105,99,104,111,115,32,109,111,118,105,109,105,101,110,
  116,111,115,0 };
  

    // Variables provenientes de remoteXY
struct {

  int8_t joystick_x; // desde -100 a 100
  int8_t joystick_y; // desde -100 a 100
  uint8_t STOP; // =1 mientras se aprieta el boton, else =0
  uint8_t TURBO; // =1 mientras se aprieta el boton, else =0
  uint8_t FLIP; // =1 mientras se aprieta el boton, else =0
  int8_t zjoystick_x; // desde -100 a 100
  int8_t zjoystick_y; // desde -100 a 100
  uint8_t zSTOP; // =1 mientras se aprieta el boton, else =0
  uint8_t zTURBO; // =1 mientras se aprieta el boton, else =0
  uint8_t zFLIP; // =1 mientras se aprieta el boton, else =0

} RemoteXY;   

    // Función que permite controlar el PWM entregado a las ruedas según la velocidad entregada por el joystick de la app
void Wheel(unsigned char *motor, int pwrPin, int v) {
  // Limitar el valor de v entre -100 y 100
  if (v > 100) v = 100;
  if (v < -100) v = -100;

  int speed = abs(v) * 2.55; // Convertir el rango de -100 a 100 a 0-255 para PWM

  if (v > 10) { 
    digitalWrite(motor[0], HIGH);   // Adelante
    digitalWrite(motor[1], LOW);
    analogWrite(pwrPin, speed);     // Controlar la velocidad con PWM 
  } 
  else if (v < -10) { 
    digitalWrite(motor[0], LOW);    // Atrás
    digitalWrite(motor[1], HIGH);
    analogWrite(pwrPin, speed);     // Controlar la velocidad con PWM
  } 
  else {
    digitalWrite(motor[0], LOW);    // Parar
    digitalWrite(motor[1], LOW);
    analogWrite(pwrPin, 0);         // Detener el motor
  }
}

unsigned char RightMotor[2] = 
  {AIN1, AIN2};
unsigned char LeftMotor[2] = 
  {BIN1, BIN2};



void ControlMotors(int x, int y) {
  int forward = y;          
  int turn = x;             
  
    // Rango para la sensibilidad de los giros
  if (abs(turn) < 10) {
    turn = 0;                
  } else {
    turn = -0.5 * turn; // bajandole la sensibilidad a los giros 
  }

    // Para aplicar turbo
  float applyturbo = (RemoteXY.TURBO > 0 || RemoteXY.zTURBO > 0) ? 1 : 0.5;

    // Motor derecho
  Wheel(RightMotor, PWMA, applyturbo * (turn/3 - forward));

    // Motor izquierdo
  Wheel(LeftMotor, PWMB, applyturbo * (turn/3 + forward));
}




#pragma pack(pop)
 
void setup() {
  // put your setup code here, to run once:
  {
  remotexy = new CRemoteXY (
    RemoteXY_CONF_PROGMEM, 
    &RemoteXY, 
    new CRemoteXYConnectionServer (
      new CRemoteXYComm_WiFiPoint (
        "bulbasaur",       // REMOTEXY_WIFI_SSID
        "pikachu12"),        // REMOTEXY_WIFI_PASSWORD
      6388                  // REMOTEXY_SERVER_PORT
    )
  ); 
  } 
  
  Serial.begin(115200); // serial monitor
  delay(20);

  // Inicializando pins
  pinMode (AIN1, OUTPUT);
  pinMode (AIN2, OUTPUT);
  pinMode (BIN1, OUTPUT);
  pinMode (BIN2, OUTPUT);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  
  
}

void loop() {
  RemoteXY_Handler();

    // Chequea el boton de STOP previo a hacer funcionar las ruedas
  if (RemoteXY.STOP > 0 || RemoteXY.zSTOP > 0) { 
    Serial.println("STOP");
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
    return;
  }


    // Solo se usará el joystick para zurdos si el para diestros no esta en uso (con un margen de error)
  if (abs(RemoteXY.joystick_x) > 10 || abs(RemoteXY.joystick_y) > 10) {
    ControlMotors(RemoteXY.joystick_x, RemoteXY.joystick_y);
  } else {
    ControlMotors(RemoteXY.zjoystick_x, RemoteXY.zjoystick_y);
  }

  }
