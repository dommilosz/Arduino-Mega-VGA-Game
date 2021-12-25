#include <VGAX.h>
#include <math.h>
#define FNT_NANOFONT_HEIGHT 6
#define FNT_NANOFONT_SYMBOLS_COUNT 95
#include <VGAXUtils.h>

VGAX vga;
VGAXUtils vgaU;

//data size=570 bytes
const unsigned char fnt_nanofont_data[FNT_NANOFONT_SYMBOLS_COUNT][1 + FNT_NANOFONT_HEIGHT] PROGMEM = {
  { 1, 128, 128, 128, 0, 128, 0, }, //glyph '!' code=0
  { 3, 160, 160, 0, 0, 0, 0, }, //glyph '"' code=1
  //{ 5, 80, 248, 80, 248, 80, 0, },  //glyph '#' code=2-
  { 5, 248, 248, 248, 248, 248, 0, },  //glyph '#' code=2 - full rectangle
  { 5, 120, 160, 112, 40, 240, 0, },  //glyph '$' code=3
  { 5, 136, 16, 32, 64, 136, 0, },  //glyph '%' code=4
  { 5, 96, 144, 104, 144, 104, 0, },  //glyph '&' code=5
  { 2, 128, 64, 0, 0, 0, 0, },  //glyph ''' code=6
  { 2, 64, 128, 128, 128, 64, 0, }, //glyph '(' code=7
  { 2, 128, 64, 64, 64, 128, 0, },  //glyph ')' code=8
  { 3, 0, 160, 64, 160, 0, 0, },  //glyph '*' code=9
  { 3, 0, 64, 224, 64, 0, 0, }, //glyph '+' code=10
  { 2, 0, 0, 0, 0, 128, 64, },  //glyph ',' code=11
  { 3, 0, 0, 224, 0, 0, 0, }, //glyph '-' code=12
  { 1, 0, 0, 0, 0, 128, 0, }, //glyph '.' code=13
  { 5, 8, 16, 32, 64, 128, 0, },  //glyph '/' code=14
  { 4, 96, 144, 144, 144, 96, 0, }, //glyph '0' code=15
  { 3, 64, 192, 64, 64, 224, 0, },  //glyph '1' code=16
  { 4, 224, 16, 96, 128, 240, 0, }, //glyph '2' code=17
  { 4, 224, 16, 96, 16, 224, 0, },  //glyph '3' code=18
  { 4, 144, 144, 240, 16, 16, 0, }, //glyph '4' code=19
  { 4, 240, 128, 224, 16, 224, 0, },  //glyph '5' code=20
  { 4, 96, 128, 224, 144, 96, 0, }, //glyph '6' code=21
  { 4, 240, 16, 32, 64, 64, 0, }, //glyph '7' code=22
  { 4, 96, 144, 96, 144, 96, 0, },  //glyph '8' code=23
  { 4, 96, 144, 112, 16, 96, 0, },  //glyph '9' code=24
  { 1, 0, 128, 0, 128, 0, 0, }, //glyph ':' code=25
  { 2, 0, 128, 0, 0, 128, 64, },  //glyph ';' code=26
  { 3, 32, 64, 128, 64, 32, 0, }, //glyph '<' code=27
  { 3, 0, 224, 0, 224, 0, 0, }, //glyph '=' code=28
  { 3, 128, 64, 32, 64, 128, 0, },  //glyph '>' code=29
  { 4, 224, 16, 96, 0, 64, 0, },  //glyph '?' code=30
  { 4, 96, 144, 176, 128, 112, 0, },  //glyph '@' code=31
  { 4, 96, 144, 240, 144, 144, 0, },  //glyph 'A' code=32
  { 4, 224, 144, 224, 144, 224, 0, }, //glyph 'B' code=33
  { 4, 112, 128, 128, 128, 112, 0, }, //glyph 'C' code=34
  { 4, 224, 144, 144, 144, 224, 0, }, //glyph 'D' code=35
  { 4, 240, 128, 224, 128, 240, 0, }, //glyph 'E' code=36
  { 4, 240, 128, 224, 128, 128, 0, }, //glyph 'F' code=37
  { 4, 112, 128, 176, 144, 112, 0, }, //glyph 'G' code=38
  { 4, 144, 144, 240, 144, 144, 0, }, //glyph 'H' code=39
  { 3, 224, 64, 64, 64, 224, 0, },  //glyph 'I' code=40
  { 4, 240, 16, 16, 144, 96, 0, },  //glyph 'J' code=41
  { 4, 144, 160, 192, 160, 144, 0, }, //glyph 'K' code=42
  { 4, 128, 128, 128, 128, 240, 0, }, //glyph 'L' code=43
  { 5, 136, 216, 168, 136, 136, 0, }, //glyph 'M' code=44
  { 4, 144, 208, 176, 144, 144, 0, }, //glyph 'N' code=45
  { 4, 96, 144, 144, 144, 96, 0, }, //glyph 'O' code=46
  { 4, 224, 144, 224, 128, 128, 0, }, //glyph 'P' code=47
  { 4, 96, 144, 144, 144, 96, 16, },  //glyph 'Q' code=48
  { 4, 224, 144, 224, 160, 144, 0, }, //glyph 'R' code=49
  { 4, 112, 128, 96, 16, 224, 0, }, //glyph 'S' code=50
  { 3, 224, 64, 64, 64, 64, 0, }, //glyph 'T' code=51
  { 4, 144, 144, 144, 144, 96, 0, },  //glyph 'U' code=52
  { 3, 160, 160, 160, 160, 64, 0, },  //glyph 'V' code=53
  { 5, 136, 168, 168, 168, 80, 0, },  //glyph 'W' code=54
  { 4, 144, 144, 96, 144, 144, 0, },  //glyph 'X' code=55
  { 3, 160, 160, 64, 64, 64, 0, },  //glyph 'Y' code=56
  { 4, 240, 16, 96, 128, 240, 0, }, //glyph 'Z' code=57
  { 2, 192, 128, 128, 128, 192, 0, }, //glyph '[' code=58
  { 5, 128, 64, 32, 16, 8, 0, },  //glyph '\' code=59
  { 2, 192, 64, 64, 64, 192, 0, },  //glyph ']' code=60
  { 5, 32, 80, 136, 0, 0, 0, }, //glyph '^' code=61
  { 4, 0, 0, 0, 0, 240, 0, }, //glyph '_' code=62
  { 2, 128, 64, 0, 0, 0, 0, },  //glyph '`' code=63
  { 3, 0, 224, 32, 224, 224, 0, },  //glyph 'a' code=64
  { 3, 128, 224, 160, 160, 224, 0, }, //glyph 'b' code=65
  { 3, 0, 224, 128, 128, 224, 0, }, //glyph 'c' code=66
  { 3, 32, 224, 160, 160, 224, 0, },  //glyph 'd' code=67
  { 3, 0, 224, 224, 128, 224, 0, }, //glyph 'e' code=68
  { 2, 64, 128, 192, 128, 128, 0, },  //glyph 'f' code=69
  { 3, 0, 224, 160, 224, 32, 224, },  //glyph 'g' code=70
  { 3, 128, 224, 160, 160, 160, 0, }, //glyph 'h' code=71
  { 1, 128, 0, 128, 128, 128, 0, }, //glyph 'i' code=72
  { 2, 0, 192, 64, 64, 64, 128, },  //glyph 'j' code=73
  { 3, 128, 160, 192, 160, 160, 0, }, //glyph 'k' code=74
  { 1, 128, 128, 128, 128, 128, 0, }, //glyph 'l' code=75
  { 5, 0, 248, 168, 168, 168, 0, }, //glyph 'm' code=76
  { 3, 0, 224, 160, 160, 160, 0, }, //glyph 'n' code=77
  { 3, 0, 224, 160, 160, 224, 0, }, //glyph 'o' code=78
  { 3, 0, 224, 160, 160, 224, 128, }, //glyph 'p' code=79
  { 3, 0, 224, 160, 160, 224, 32, },  //glyph 'q' code=80
  { 3, 0, 224, 128, 128, 128, 0, }, //glyph 'r' code=81
  { 2, 0, 192, 128, 64, 192, 0, },  //glyph 's' code=82
  { 3, 64, 224, 64, 64, 64, 0, }, //glyph 't' code=83
  { 3, 0, 160, 160, 160, 224, 0, }, //glyph 'u' code=84
  { 3, 0, 160, 160, 160, 64, 0, },  //glyph 'v' code=85
  { 5, 0, 168, 168, 168, 80, 0, },  //glyph 'w' code=86
  { 3, 0, 160, 64, 160, 160, 0, },  //glyph 'x' code=87
  { 3, 0, 160, 160, 224, 32, 224, },  //glyph 'y' code=88
  { 2, 0, 192, 64, 128, 192, 0, },  //glyph 'z' code=89
  { 3, 96, 64, 192, 64, 96, 0, }, //glyph '{' code=90
  { 1, 128, 128, 128, 128, 128, 0, }, //glyph '|' code=91
  { 3, 192, 64, 96, 64, 192, 0, },  //glyph '}' code=92
  { 3, 96, 192, 0, 0, 0, 0, },  //glyph '~' code=93
  { 4, 48, 64, 224, 64, 240, 0, },  //glyph '£' code=94
};

static const char str0[] PROGMEM = "0";
static const char str1[] PROGMEM = "1";
static const char str2[] PROGMEM = "2";
static const char str3[] PROGMEM = "3";
static const char str4[] PROGMEM = "4";
static const char str5[] PROGMEM = "5";
static const char str6[] PROGMEM = "6";
static const char str7[] PROGMEM = "7";
static const char str8[] PROGMEM = "8";
static const char str9[] PROGMEM = "9";
static const char str10[] PROGMEM = "#";
static const char str22[] PROGMEM = "Game Over";
static const char str23[] PROGMEM = "Punkty";
static const char str24[] PROGMEM = "Zycia";
static const char str25[] PROGMEM = "Menu";
static const char str26[] PROGMEM = "START!";
static const char str26A[] PROGMEM = "STARTN'T?";
static const char str27[] PROGMEM = ":";
static const char str28[] PROGMEM = "God Mode";
static const char str29[] PROGMEM = "Speed";
static const char strTrue[] PROGMEM = "TRUE";
static const char strFalse[] PROGMEM = "FALSE";
static const char str30[] PROGMEM = "ATOS";
static const char str31[] PROGMEM = "DIFFICULTY";
static const char str32[] PROGMEM = "FATAL ERROR";
static const char str33[] PROGMEM = "SYSTEM32 NOT FOUND";
static const char str34[] PROGMEM = "BUY NEW POTATO PC";
static const char str35[] PROGMEM = "TO CONTINUE...";

void setup() {
  przeszkodyIni();
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  vga.begin(true);
  randomSeed(analogRead(6));
}

boolean RPrawo = 0;
boolean RLewo = 0;
boolean RGora = 0;
boolean RDol = 0;
boolean RBtn = 0;
boolean button;
boolean buttonX;
boolean buttonY;
boolean invincible = false;
boolean noInputs = true;
boolean startnt = false;
byte przeszkodyX[100];
byte przeszkodyY = 50;
int state = 1;
int score = 0;
int lives = 3;
int livesSett = 3;
byte px = 0;
byte py = 0;
byte delta = 5;
int wleft = 36;
byte x;
byte y;
int kierunek = 3;
int speedDelay = 100;
byte menuSelectedOptn = 0;
byte loopI = 0;
int iniSpeedDelay = 500;
int difficulty = 1;

void przeszkodyIni() {
  przeszkodyX[0] = random(wleft + 1, VGAX_WIDTH - 1);
  for (int i = 0; i < 100; i++) {
    przeszkodyX[i] = przeszkodyX[0];
  }
  for (int i = 0; i < ((20 + score + difficulty ) >= 100 ? 99 : 20 + score + difficulty); i++) {
    przeszkodyX[i] = random(wleft + 1, VGAX_WIDTH - 1);
  }
}

void processInputs() {
  int A1R = analogRead(A2);
  int A2R = analogRead(A1);
  RPrawo = A1R < 300;
  RGora = A2R < 300;
  RLewo = A1R > 700;
  RDol = A2R > 700;
  RBtn = !digitalRead(10);
  //Serial.println(A1R);
  //Serial.println(A2R);
  buttonX = RPrawo | RLewo;
  buttonY = RGora | RDol;
  button = RPrawo | RLewo | RGora | RDol | RBtn;
  if (button) {
    noInputs = false;
  }
}

void drawMenu() {
  if (RDol)menuSelectedOptn++;
  if (RGora) {
    if (menuSelectedOptn <= 0) {
      menuSelectedOptn = 4;
    } else
      menuSelectedOptn--;

  }
  if (menuSelectedOptn > 4)menuSelectedOptn = 0;

  if (RPrawo && !buttonY) {
    if (menuSelectedOptn == 1) {
      if (livesSett < 127)
        livesSett++;
      else livesSett = 1;
    }
    if (menuSelectedOptn == 2) {
      invincible = !invincible;
    }
    if (menuSelectedOptn == 3) {
      if (iniSpeedDelay >= 20)
        iniSpeedDelay -= 10;
      else iniSpeedDelay = 1000;
    }
    if (menuSelectedOptn == 4) {

      if (difficulty < 50)
        difficulty += 1;
      else difficulty = 0;

    }
    if (menuSelectedOptn == 0 && startnt) {
      halt();

    }
  }
  if (RLewo && +!buttonY) {
    if (menuSelectedOptn == 1) {
      if (livesSett > 2)
        livesSett--;
      else livesSett = 127;
    }
    if (menuSelectedOptn == 2) {
      invincible = !invincible;
    }
    if (menuSelectedOptn == 3) {
      if (iniSpeedDelay < 1000)
        iniSpeedDelay += 10;
      else iniSpeedDelay = 10;

    }
    if (menuSelectedOptn == 4) {
      if (difficulty > 0)
        difficulty -= 1;
      else difficulty = 50;

    }
  }

  if (RBtn) {
    if (menuSelectedOptn == 0) {
      startnt = !startnt;
    }
    if (menuSelectedOptn == 1) {
      livesSett = 3;
    }
    if (menuSelectedOptn == 2) {
      invincible = false;
    }
    if (menuSelectedOptn == 3) {
      iniSpeedDelay = 500;

    }
    if (menuSelectedOptn == 4) {
      difficulty = 1;

    }
  }

  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str25, 30, 3, loopI % 3 + 1);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, 30 + 5 * 5, 3, 1);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, 30 + 6 * 5, 3, 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, 30 + 7 * 5, 3, 3);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str26A, 30, 3 + 3 + 6, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, startnt ? str26A : str26, 30, 3 + 3 + 6, menuSelectedOptn == 0 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str24, 30, 3 + 3 + 12,  menuSelectedOptn == 1 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str27, 30 + 5 * 5, 3 + 3 + 12,  menuSelectedOptn == 1 ? 3 : 2);
  drawByte(livesSett, 30 + 6 * 5, 3 + 12 + 3,  menuSelectedOptn == 1 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str28, 30, 3 + 18 + 3,  menuSelectedOptn == 2 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str27, 30 + 8 * 5, 3 + 18 + 3,  menuSelectedOptn == 2 ? 3 : 2);
  drawBoolean(invincible, 30 + 9 * 5, 3 + 18 + 3, menuSelectedOptn == 2 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str29, 30, 3 + 24 + 3,  menuSelectedOptn == 3 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str27, 30 + 5 * 5, 3 + 24 + 3,  menuSelectedOptn == 3 ? 3 : 2);
  drawByte((1000 - iniSpeedDelay) / 10, 30 + 6 * 5, 3 + 24 + 3,  menuSelectedOptn == 3 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str31, 30, 3 + 24 + 6 + 3,  menuSelectedOptn == 4 ? 3 : 2);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str27, 30 + 10 * 5, 3 + 24 + 6 + 3,  menuSelectedOptn == 4 ? 3 : 2);
  drawByte(difficulty, 30 + 11 * 5, 3 + 24 + 6 + 3,  menuSelectedOptn == 4 ? 3 : 2);
  if (buttonY || RBtn)vga.delay(200);
  vga.delay(100);
}

void drawBorder() {
  vgaU.draw_line(wleft, 0, VGAX_WIDTH - 1, 0, 3);
  vgaU.draw_line(wleft, VGAX_HEIGHT - 1, VGAX_WIDTH - 1, VGAX_HEIGHT - 1, 3);
  vgaU.draw_line(wleft, 0, wleft, VGAX_HEIGHT - 1, 3);
  vgaU.draw_line(VGAX_WIDTH - 1, 0, VGAX_WIDTH - 1, VGAX_HEIGHT, 3);
}

void drawScore() {
  byte c = 2;
  if (score >= 20 && noInputs && !invincible) {
    c = loopI % 3 + 1;
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str30, 10, 3 + 12 + 6 + 12 + 6, c);
    drawByte(255, 20, 3 + 12 + 6 + 12 + 6 + 6 + 1, c);
  }

  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str23, 10, 3, c);
  drawByte(score, 20, 3 + 6 + 1, c);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str24, 10, 3 + 12 + 6, c);
  drawByte(lives, 20, 3 + 12 + 6 + 6 + 1, c);
}

void drawByte(byte b, byte x, byte y, byte c) {
  drawDig(b / 100, x, y, c);
  drawDig(b / 10, x + 5, y, c);
  drawDig(b, x + 10, y, c);
}

void drawBoolean(bool b, byte x, byte y, byte c) {
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x, y, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x + 5, y, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x + 10, y, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x + 15, y, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x + 20, y, 0);
  if (b) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, strTrue, x, y,  c);
  } else {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, strFalse, x, y,  c);
  }
}

void drawDig(byte b, byte x, byte y, byte c) {
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str10, x, y, 0);
  if (b % 10 == 0) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str0, x, y, c);
  }
  if (b % 10 == 1) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str1, x, y, c);
  }
  if (b % 10 == 2) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str2, x, y, c);
  }
  if (b % 10 == 3) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str3, x, y, c);
  }
  if (b % 10 == 4) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str4, x, y, c);
  }
  if (b % 10 == 5) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str5, x, y, c);
  }
  if (b % 10 == 6) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str6, x, y, c);
  }
  if (b % 10 == 7) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str7, x, y, c);
  }
  if (b % 10 == 8) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str8, x, y, c);
  }
  if (b % 10 == 9) {
    vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str9, x, y, c);
  }
}

void drawStartScreen() {
  vga.clear(0);
  drawBorder();
  drawScore();
  button = 0;
  vga.delay(200);
}

void newMatch() {
  przeszkodyIni();
  score = 0;
  vga.clear(0);
  lives = livesSett;
  drawBorder();
  drawScore();
  px = 70;
  py = 30;

  kierunek = 1;
  noInputs = true;
}

void loop() {
  loopI++;
  processInputs();

  if (state == 1) {
    drawMenu();
    vga.delay(10);
    processInputs();
    if (RPrawo == 1 && menuSelectedOptn == 0 && !startnt) {
      button = 0;
      vga.clear(0);
      drawStartScreen();
      state = 2;
    }
  }

  if (state == 2) {
    score = 0;
    drawScore();
    button = 0;
    RPrawo = 0;
    RLewo = 0;
    RGora = 0;
    RDol = 0;
    kierunek = 3;
    x = -1;
    y = 0;
    newMatch();
    state = 3;
  }

  if (state == 3) {
    speedDelay = (iniSpeedDelay - (score * 10));
    if (speedDelay < 10)speedDelay = 10;
    processInputs();
    if (przeszkodyY < 5) {
      przeszkodyY = 55;    przeszkodyIni(); score++; drawScore();
    }
    if (score >= 20 && noInputs) {
      drawScore();
    }
    przeszkodyY--;

    for (byte i = 0; i < ((20 + score + difficulty) >= 100 ? 99 : 20 + score + difficulty); i++) {
      vga.putpixel(przeszkodyX[i], przeszkodyY, 2);
      vga.putpixel(przeszkodyX[i], przeszkodyY + 1, 0);
      vga.putpixel(przeszkodyX[i], 4, 0);
    }
    if (RLewo == 1) {
      x = -1;
      y = 0;
      kierunek = 2;
      RDol = 0;
    }
    if (RPrawo == 1) {
      x = +1;
      y = 0;
      kierunek = 1;
      RGora = 0;
    }

    if (vga.getpixel(int(px + x), int(py + y)) == 0 || vga.getpixel(int(px + x), int(py + y)) == 1) {
      px += x;
      py += y;
    }
    if (vga.getpixel(int(px), int(py)) == 2 && !invincible) {
      lives -= 1;
      drawScore();
      vgaTone(200, 150);
    }
    vga.putpixel(px, py, 1);
    if (vga.getpixel(int(px + 1), int(py)) == 1 ) {
      vga.putpixel(px + 1, py, 0);
    }
    if (vga.getpixel(int(px - 1), int(py)) == 1 ) {
      vga.putpixel(px - 1, py, 0);
    }
    if (vga.getpixel(int(px), int(py + 1)) == 1 ) {
      vga.putpixel(px, py + 1, 0);
    }
    if (vga.getpixel(int(px), int(py - 1)) == 1 ) {
      vga.putpixel(px, py - 1, 0);
    }

    if (lives < 1) {
      vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str22, 58, 24, 1);
      vga.delay(300);
      button == 0;
      vgaTone(200, 150);
      vgaTone(250, 150);
      vgaTone(200, 150);
      while (button == 0) {
        processInputs();
      }
      state = 1;
      vga.clear(0);
      return;
    }

    if (RBtn) {
      state = 1;
      vga.clear(0);
      startnt = true;
      return;
    }

    if (!RGora)
      vga.delay(speedDelay);
    if (RGora)vga.delay(10);
  }
}

void vgaTone(int freq, int time) {
  vga.tone(freq);
  vga.delay(time);
  vga.noTone();
}

void halt() {
  vga.clear(1);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str32, 3, 3, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str33, 3, 3 + 6, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str34, 3, 3 + 12, 0);
  vga.printPROGMEM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str35, 3, 3 + 12 + 6, 0);
  while (1)vga.delay(100000000);
}
