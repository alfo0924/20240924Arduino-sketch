

## 程式碼解析  sketch_sep24a.ino

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

- 
- ----------------------------------------

以下是您提供的Arduino程式碼的解析，以Markdown格式呈現：

## Arduino LED控制程式解析

### setup() 函數

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
}
```

這個函數在Arduino啟動時執行一次：

1. 初始化串口通信，設定波特率為9600。
2. 將內建LED引腳設置為輸出模式。
3. 初始狀態將LED設置為關閉。

### loop() 函數

```cpp
void loop() {
  char command = Serial.read();
  if(command == 'O'){
    Serial.println("LED ON");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else if(command == 'X'){
    Serial.println("LED OFF");
    digitalWrite(LED_BUILTIN, LOW);
  }

  int x = Serial.parseInt();
  
  for (int i = 0; i < x; i++) {
    Serial.println("LED ON");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED OFF");
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
```

## 程式碼解析  sketch_sep24b.ino

1. **字符控制部分**：
   - 讀取串口接收到的字符。
   - 如果接收到'O'，輸出"LED ON"並點亮LED。
   - 如果接收到'X'，輸出"LED OFF"並關閉LED。

2. **數字控制部分**：
   - 使用`Serial.parseInt()`讀取一個整數值。
   - 根據讀取到的數值`x`，執行`x`次LED閃爍循環。
   - 每次循環中，LED會亮0.5秒，然後滅0.5秒。
   - 每次狀態改變時都會輸出相應的信息。

## 功能說明

這個程式提供了兩種控制LED的方式：

1. **字符控制**：
   - 輸入'O'可以打開LED。
   - 輸入'X'可以關閉LED。

2. **數字控制**：
   - 輸入一個數字`n`，LED將閃爍`n`次。
   - 每次閃爍包括0.5秒亮和0.5秒滅。

## 注意事項

1. 字符控制和數字控制功能是獨立的，但在同一個`loop()`函數中執行。
2. 數字控制部分會在每次`loop()`循環中執行，可能會干擾字符控制功能。
3. 最後兩行`digitalWrite(LED_BUILTIN, HIGH);`和`digitalWrite(LED_BUILTIN, LOW);`會立即執行，可能看不到效果。


