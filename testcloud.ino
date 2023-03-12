
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#include <addons/TokenHelper.h>

#include <addons/RTDBHelper.h>
#include <inttypes.h>
#include <Wire.h>
#include <lm75.h>

#define WIFI_SSID "Monsz"
#define WIFI_PASSWORD "00000000"

#define API_KEY "AIzaSyAw-OBCIjtfHSiRAMwaF9KcZsjPjp1oYUE"

#define DATABASE_URL "esp32-ee793-default-rtdb.asia-southeast1.firebasedatabase.app"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

#define USER_EMAIL "supsathit.y@kkumail.com"
#define USER_PASSWORD "monsz0928896834"

FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

TempI2C_LM75 termo = TempI2C_LM75(0x48, TempI2C_LM75::nine_bits);

void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  config.database_url = DATABASE_URL;

  config.token_status_callback = tokenStatusCallback;

  Firebase.begin(&config, &auth);

  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);
}
void loop() {
  if(termo.getTemp( )= 1){
    char Type_IngraFirebase.getInt(fbdo, "Ture_Skeler_Read");
  }
  else{}
  Serial.print("Temperature in Celsius   : ");
  Serial.print(termo.getTemp() - 4);
  delay(5000);
}
