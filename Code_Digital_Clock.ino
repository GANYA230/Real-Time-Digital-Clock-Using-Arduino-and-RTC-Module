#include <TM1637Display.h>
#include <Wire.h>
#include <RTClib.h>

#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

RTC_DS3231 rtc;

void setup() {
  display.setBrightness(0x0f); 
  Wire.begin();
  rtc.begin();

  // -------------------------------
  // Set waktu & tanggal secara manual (aktifkan hanya sekali!)
  // Format: DateTime(Tahun, Bulan, Tanggal, Jam, Menit, Detik)
  // -------------------------------
  // HANYA AKTIFKAN BARIS DI BAWAH INI SEKALI SAJA UNTUK SET WAKTU:
  rtc.adjust(DateTime(2025, 6, 8, 14, 30, 0)); // 8 Juni 2025 pukul 14:30:00
  // Setelah waktu sudah benar, KOMENTARI  baris ini!
}

void loop() {
  DateTime now = rtc.now();
  int hour = now.hour();
  int minute = now.minute();

  int timeToDisplay = hour * 100 + minute;

  display.showNumberDecEx(timeToDisplay, 0b11100000, true);
  delay(1000);
}
