#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 128×64 SPI 接口定义（按你原来的引脚）
#define OLED_MOSI   11
#define OLED_CLK    13
#define OLED_DC     9
#define OLED_CS     10
#define OLED_RESET  8
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* ---------- 工具：任意图形居中 ---------- */
void showCentered(void (*drawFunc)(int16_t, int16_t, int16_t, uint16_t),
                  int16_t size, uint16_t color, uint16_t delay_ms = 2000)
{
  display.clearDisplay();
  int16_t cx = display.width()  / 2;
  int16_t cy = display.height() / 2;
  drawFunc(cx, cy, size, color);   // 以屏幕中心为原点画
  display.display();
  delay(delay_ms);
}

/* ----------  setup  ---------- */
/* ----------  setup  ---------- */
/* ----------  setup  ---------- */
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.showBootScreen();
  display.display();
  delay(2000);

  // 逐个居中显示 2 s，手写 lambda，无 auto、无模板
  showCentered([](int16_t x,int16_t y,int16_t z,uint16_t c){ display.drawPentagram(x,y,z,c); }, 15, SSD1306_WHITE);
  showCentered([](int16_t x,int16_t y,int16_t z,uint16_t c){ display.drawStar6    (x,y,z,7,c); }, 15, SSD1306_WHITE);
  showCentered([](int16_t x,int16_t y,int16_t z,uint16_t c){ display.drawHeart    (x,y,z,c); }, 9,  SSD1306_WHITE);
  showCentered([](int16_t x,int16_t y,int16_t z,uint16_t c){ display.drawSpiral   (x,y,z,3,c); }, 18, SSD1306_WHITE);
}

void loop() {}