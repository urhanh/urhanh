#include <SoftwareSerial.h>

SoftwareSerial bluetoothModulu(0, 1);
const int ROLE = 13;
 
void setup()
{
  bluetoothModulu.begin(9600); /* Bluetooth haberleşmesi */
  pinMode(ROLE, OUTPUT);
}
 
char okunanKarakter; /* okunan verilerin kaydedileceği değişken */
void loop()
{
 while (bluetoothModulu.available() > 0) { /* Yeni veri var mı */
    okunanKarakter = bluetoothModulu.read(); /* Yeni veriyi okunanKarakter degiskenine kaydet */
    switch (okunanKarakter) { /* Okunan karaktere göre işlem yap */
      case 'a': /* gelen karakterin işlem karşılığı */
        digitalWrite(ROLE, HIGH);
        break;
      case 'b':
        digitalWrite(ROLE, LOW);
        break;
    } /* Switch sonu */
  }/* While sonu*/
}/* Loop sonu */
