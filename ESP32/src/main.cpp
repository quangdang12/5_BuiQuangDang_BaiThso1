
#include <Arduino.h>
#include <DHT.h>

// Cấu hình chân và loại cảm biến
#define DHTPIN 4        // Chân DATA nối GPIO4 ESP32
#define DHTTYPE DHT11   // Nếu bạn dùng DHT22 thì đổi thành DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Bat dau doc DHT11...");
}

void loop() {
  // Đọc nhiệt độ và độ ẩm
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius
  // float f = dht.readTemperature(true); // Fahrenheit (nếu cần)

  // Kiểm tra lỗi đọc
  if (isnan(h) || isnan(t)) {
    Serial.println("Loi khi doc DHT11!");
    delay(2000);
    return;
  }

  // In kết quả ra Serial Monitor
  Serial.print("Do am: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.println(" *C");

  delay(2000); // DHT11 đọc 1 lần/2 giây
}
