#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

const int buttonPins[10] = {2, 4, 5};  // 10 個按鍵對應 GPIO
//2, 4, 5, 18, 19, 21, 22, 23, 25, 26
void setup() {
    Serial.begin(115200);
    bleKeyboard.begin();  // 初始化 BLE 鍵盤
    for (int i = 0; i < 3; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);  // 按鍵為 INPUT_PULLUP 模式
    }
}

void loop() {
    if (bleKeyboard.isConnected()) {  // 確認連線狀態
                for (int i = 0; i < 3; i++) {
            if (digitalRead(buttonPins[i]) == LOW) {  // 檢測按鍵是否按下
                bleKeyboard.print(String(i));  // 傳送對應數字
                delay(500);  // 避免重複輸入
            }
        }
    }
    else
    {
        Serial.println("not connected");
    }
}