#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
    Serial.begin(115200);
    bleKeyboard.begin();  // 初始化 BLE 鍵盤
    Serial.println("BLE Keyboard Initialized");
}

void loop() {
    if (bleKeyboard.isConnected()) {  // 確認是否連接到主機
        Serial.println("Sending 'Hello World'");
        bleKeyboard.print("Hello World!");  // 傳送字串到主機
        delay(1000);  // 每秒傳送一次
    }
}
