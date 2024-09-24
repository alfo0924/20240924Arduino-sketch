

## 程式碼解析

### setup() 函數

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}
```

這個函數在Arduino啟動時只執行一次：

1. `Serial.begin(9600)`: 初始化串口通信，設定波特率為9600。
2. `pinMode(LED_BUILTIN, OUTPUT)`: 將內建LED引腳設置為輸出模式。
3. `digitalWrite(LED_BUILTIN, LOW)`: 初始狀態將LED設置為關閉。

### loop() 函數

```cpp
void loop() {
  char command = Serial.read();
  if(command == 'N'){
    Serial.println("LED ON");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
```

這個函數會不斷重複執行：

1. `char command = Serial.read()`: 讀取串口接收到的字符。
2. `if(command == 'N')`: 檢查接收到的字符是否為'N'。
   - 如果是'N'，則：
     - 輸出"LED ON"到串口
     - 點亮LED
     - 等待1秒（1000毫秒）
   - 如果不是'N'，則關閉LED。

## 功能說明

這個程式的主要功能是：

- 通過串口監控LED的狀態
- 當接收到字符'N'時，LED會亮起1秒鐘
- 其他情況下，LED保持關閉狀態

## 注意事項

- 程式中的註釋提到如果接收到包含'N'的單詞也會點亮LED，但實際代碼只檢查單個字符'N'。
- `Serial.read()`每次只讀取一個字符，如果要檢測包含'N'的單詞，需要修改代碼邏輯。
