
#include "stdio.h"
// ============================================================================
// ============================================================================
//                              .h File
// ============================================================================
// ============================================================================
// --------------------------------------------------------------
//                          type.h
// --------------------------------------------------------------
typedef unsigned char uint8;
typedef unsigned short u16;
typedef unsigned int u32;

// --------------------------------------------------------------
//                          kernel.h
// --------------------------------------------------------------
#define NULL 0

//uint8 inb(u16 port);
//void outb(u16 port, uint8 data);
uint8 get_input_keycode();
void wait_for_io(u32 timer_count);
void sleep1(u32 timer_count);

// --------------------------------------------------------------
//                          vga.h
// --------------------------------------------------------------
#define VGA_ADDRESS 0xA0000
#define VGA_MAX 0xF9FF
#define VGA_MAX_WIDTH 320
#define VGA_MAX_HEIGHT 200
uint8* vga_buffer;
PORTDATA* argport=NULL;
PIXEL* p=NULL;


enum vga_color {
  BLACK1,
  BLUE1,
  GREEN1,
  CYAN,
  RED1,
  MAGENTA,
  BROWN,
  GREY,
  DARK_GREY,
  BRIGHT_BLUE,
  BRIGHT_GREEN,
  BRIGHT_CYAN,
  BRIGHT_RED,
  BRIGHT_MAGENTA,
  YELLOW,
  WHITE1,
};
/* Attribute Controller Registers */
#define	VGA_AC_INDEX 0x3C0
#define	VGA_AC_READ 0x3C1
#define	VGA_AC_WRITE 0x3C0

/*
Miscellaneous Output
*/
#define	VGA_MISC_READ 0x3CC
#define	VGA_MISC_WRITE 0x3C2

/* Sequencer Registers */
#define VGA_SEQ_INDEX 0x3C4
#define VGA_SEQ_DATA 0x3C5

/* VGA Color Palette Registers */
#define	VGA_DAC_READ_INDEX 0x3C7
#define	VGA_DAC_WRITE_INDEX 0x3C8
#define	VGA_DAC_DATA 0x3C9

/* Graphics Controller Registers */
#define VGA_GC_INDEX 0x3CE
#define VGA_GC_DATA 0x3CF

/* CRT Controller Registers */
#define VGA_CRTC_INDEX 0x3D4
#define VGA_CRTC_DATA 0x3D5

/* General Control and Status Registers */
#define	VGA_INSTAT_READ 0x3DA

void init_vga();
void clear_screen();
void clear_color(uint8 color);
//void putpixel(u16 x, u16 y, uint8 color);
void draw_line(u16 x1, u16 y1, u16 x2, u16 y2, uint8 color);
void draw_rect(u16 x, u16 y, u16 width, u16 height, uint8 color);
void fill_rect(u16 x, u16 y, u16 width, u16 height, uint8 color);
void draw_circle(u16 x, u16 y, u16 radius, uint8 color);
void draw_diamond(u16 x, u16 y, u16 radius, uint8 color);

// --------------------------------------------------------------
//                          keyboard.h
// --------------------------------------------------------------
#define KEYBOARD_PORT 0x60

#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2E
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1F
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2F
#define KEY_W 0x11
#define KEY_X 0x2D
#define KEY_Y 0x15
#define KEY_Z 0x2C
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0A
#define KEY_0 0x0B
#define KEY_MINUS 0x0C
#define KEY_EQUAL 0x0D
#define KEY_SQUARE_OPEN_BRACKET 0x1A
#define KEY_SQUARE_CLOSE_BRACKET 0x1B
#define KEY_SEMICOLON 0x27
#define KEY_BACKSLASH 0x2B
#define KEY_COMMA 0x33
#define KEY_DOT 0x34
#define KEY_FORESLHASH 0x35
#define KEY_F1 0x3B
#define KEY_F2 0x3C
#define KEY_F3 0x3D
#define KEY_F4 0x3E
#define KEY_F5 0x3F
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_F11 0x85
#define KEY_F12 0x86
#define KEY_BACKSPACE 0x0E
#define KEY_DELETE 0x53
#define KEY_DOWN 0x50
#define KEY_END 0x4F
#define KEY_ENTER 0x1C
#define KEY_ESC 0x01
#define KEY_HOME 0x47
#define KEY_INSERT 0x52
#define KEY_KEYPAD_5 0x4C
#define KEY_KEYPAD_MUL 0x37
#define KEY_KEYPAD_Minus 0x4A
#define KEY_KEYPAD_PLUS 0x4E
#define KEY_KEYPAD_DIV 0x35
#define KEY_LEFT 0x4B
#define KEY_PAGE_DOWN 0x51
#define KEY_PAGE_UP 0x49
#define KEY_PRINT_SCREEN 0x37
#define KEY_RIGHT 0x4D
#define KEY_SPACE 0x39
#define KEY_TAB 0x0F
#define KEY_UP 0x48

// --------------------------------------------------------------
//                          utils.h
// --------------------------------------------------------------
#define TRUE  1
#define FALSE 0

extern u32 strlen1(const char*);
extern u32 digit_count(int);
extern void itoa(int, char *);


// --------------------------------------------------------------
//                          bitmap.h
// --------------------------------------------------------------
#define BITMAP_SIZE 8

void draw_char(u16 x, u16 y, uint8 color, char ch);
void draw_string(u16 x, u16 y, uint8 color, char *str);

// --------------------------------------------------------------
//                          pong.h
// --------------------------------------------------------------

#define VIRTUALBOX


// size of bounced rectangle
#define RECT_SIZE      6

// speed of rectangle on qemu
#define RECT_SPEED_X   6
#define RECT_SPEED_Y   6

// speed of rectangle on virtualbox
#define RECT_SPEED_X   2
#define RECT_SPEED_Y   2
// pad position, size & pads speeds
#define PAD_POS_X    VGA_MAX_WIDTH - PAD_WIDTH - 1
#define PAD_WIDTH    6
#define PAD_HEIGHT   50

// pads speed on qemu
#define PAD_SPEED    20

// pads speed on virtualbox
#define PAD_SPEED    6



void pong_game();

// ============================================================================
// ============================================================================
//                              C File
// ============================================================================
// ============================================================================


// --------------------------------------------------------------
//                          pong.c
// --------------------------------------------------------------
// pads position y, will change on keys
u16 pad_pos_y = 2;
// score counnt
u32 score_count = 0;

// initialize game with into
static void init_game(){
    uint8 b = 0;

    draw_string(120, 13, BRIGHT_CYAN, "PONG GAME");
    draw_rect(100, 4, 120, 25, BLUE1);
    draw_string(10, 50, BRIGHT_MAGENTA, "HOW TO PLAY");
    draw_rect(2, 40, 235, 80, BROWN);
    draw_string(10, 70, BRIGHT_RED, "ARROW KEY UP");
    draw_string(30, 80, WHITE1, "TO MOVE BOTH PADS UP");
    draw_string(10, 90, BRIGHT_RED, "ARROW KEY DOWN");
    draw_string(30, 100, WHITE1, "TO MOVE BOTH PADS DOWN");
    draw_string(60, 160, BRIGHT_GREEN, "PRESS ENTER TO START");

    sleep1(10);

    while (1)
    {
        b = get_input_keycode();
        sleep1(5);
        if (b == KEY_ENTER)
            break;
        b = 0;
    }
    clear_screen();
}

// update score count text
static void update_score_count()
{
    char str[32];

    itoa(score_count, str);
    draw_string(150, 2, WHITE1, str);
}

// if lose then display final score & restart game
static void lose()
{
    uint8 b = 0;
    char str[32];

    itoa(score_count, str);
    clear_screen();
    draw_string(120, 15, BRIGHT_GREEN, "NICE PLAY");
    draw_string(125, 45, WHITE1, "SCORE");
    draw_string(180, 45, WHITE1, str);
    draw_string(45, 130, YELLOW, "PRESS ENTER TO PLAY AGAIN");

    sleep1(10);

    while (1)
    {
        b = get_input_keycode();
        sleep1(5);
        if (b == KEY_ENTER)
            break;
        b = 0;
    }
    score_count = 0;
    clear_screen();
    pong_game();
}


// move both pads simultaneously on pressed keys
void move_pads()
{
    uint8 b;

    // draw both pads
    fill_rect(0, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);
    fill_rect(PAD_POS_X, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);

    b = get_input_keycode();
    // if down key pressed, move both pads down
    if (b == KEY_DOWN)
    {
        if (pad_pos_y < VGA_MAX_HEIGHT - PAD_HEIGHT)
            pad_pos_y = pad_pos_y + PAD_SPEED;
        fill_rect(0, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);
        fill_rect(PAD_POS_X, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);
    }
    // if up key pressed, move both pads up
    else if (b == KEY_UP)
    {
        if (pad_pos_y >= PAD_WIDTH)
            pad_pos_y = pad_pos_y - PAD_SPEED;
        fill_rect(0, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);
        fill_rect(PAD_POS_X, pad_pos_y, PAD_WIDTH, PAD_HEIGHT, YELLOW);
    }
    sleep1(1);
}

void pong_game()
{
    u16 rect_pos_x = RECT_SIZE + 20;
    u16 rect_pos_y = RECT_SIZE;
    u16 rect_speed_x = RECT_SPEED_X;
    u16 rect_speed_y = RECT_SPEED_Y;

    init_game();

    while (1)
    {
        // add speed values to positions
        rect_pos_x += rect_speed_x;
        rect_pos_y += rect_speed_y;

        // check if position x < left pad position x
        if (rect_pos_x - RECT_SIZE <= PAD_WIDTH + 1)
        {
            // if position of rect is not between left pad position,
            // then lose, bounced rect is not in y range of pad
            if ((rect_pos_y > 0 && rect_pos_y < pad_pos_y) || 
                (rect_pos_y <= VGA_MAX_HEIGHT && rect_pos_y > pad_pos_y + PAD_HEIGHT))
            {
                lose();
            }
            else
            {
                // set speed x to negative, means move opposite direction
                rect_speed_x = -rect_speed_x;
                // set position x to rect size
                rect_pos_x = PAD_WIDTH + RECT_SIZE;
                // increase score
                score_count++;
            }
        }
        // check if position x >= right pad position x
        else if (rect_pos_x + RECT_SIZE >= PAD_POS_X + RECT_SIZE - 1)
        {
            // in range of y pad position
            if ((rect_pos_y > 0 && rect_pos_y < pad_pos_y) || 
                (rect_pos_y <= VGA_MAX_HEIGHT && rect_pos_y > pad_pos_y + PAD_HEIGHT) || 
                (rect_pos_y + RECT_SIZE > 0 && rect_pos_y + RECT_SIZE < pad_pos_y))
            {
                lose();
            }
            else
            {
                // set speed x to negative, means move opposite direction
                rect_speed_x = -rect_speed_x;
                // set position x to minimum of pad position x - rect size
                rect_pos_x = PAD_POS_X - RECT_SIZE;
                // increase score
                score_count++;
            }
        }

        // change rect y position by checking boundries
        if (rect_pos_y - RECT_SIZE <= 0)
        {
            rect_speed_y = -rect_speed_y;
            rect_pos_y = RECT_SIZE;
        }
        else if(rect_pos_y + RECT_SIZE > VGA_MAX_HEIGHT + RECT_SIZE)
        {
            rect_speed_y = -rect_speed_y;
            rect_pos_y = VGA_MAX_HEIGHT - RECT_SIZE;
        }

        // clear screen for repaint
        clear_screen();
        // move pads on keys
        move_pads();
        // update score count
        update_score_count();
        // fill bounced rect
        fill_rect(rect_pos_x - RECT_SIZE, rect_pos_y - RECT_SIZE, RECT_SIZE, RECT_SIZE, WHITE1);
        // change sleep1 value if running in VirtualBox or on bare metal
        sleep1(1);
    }
}

// --------------------------------------------------------------
//                          vga.c
// --------------------------------------------------------------
/*
See Intel® OpenSource HD Graphics PRM pdf file
for following defined data for each vga register
and its explaination
*/
// ---------------------------王翊堃修改-------------------------------
// static uint8 seq_data[5] = {0x03, 0x00, 0x03, 0x00, 0x02};
// static uint8 crtc_data[25] = {0x5F, 0x4F, 0x50, 0x82, 0x55, 0x81, 0xBF, 0x1F,
// 	0x00, 0x4F, 0x0D, 0x0E, 0x00, 0x00, 0x00, 0x50,
// 	0x9C, 0x0E, 0x8F, 0x28, 0x1F, 0x96, 0xB9, 0xA3,
// 	0xFF};
// static uint8 gc_data[9] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x0E, 0x00,
// 	0xFF};
// static uint8 ac_data[21] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x14, 0x07,
// 	0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
// 	0x0C, 0x00, 0x0F, 0x08, 0x00};
//--------------------------------------------------------------------
static uint8 seq_data[5] = {0x03, 0x01, 0x0F, 0x00, 0x0E};
static uint8 crtc_data[25] = {0x5F, 0x4F, 0x50, 0x82, 
                              0x54, 0x80, 0xBF, 0x1F,
                              0x00, 0x41, 0x00, 0x00, 
                              0x00, 0x00, 0x00, 0x00,
                              0x9C, 0x0E, 0x8F, 0x28,	
                              0x40, 0x96, 0xB9, 0xA3,
                              0xFF};

static uint8 gc_data[9] = {0x00, 0x00, 0x00, 0x00, 
                          0x00, 0x40, 0x05, 0x0F,
                          0xFF};

static uint8 ac_data[21] = {0x00, 0x01, 0x02, 0x03,
                            0x04, 0x05, 0x06, 0x07,
                            0x08, 0x09, 0x0A, 0x0B,
                            0x0C, 0x0D, 0x0E, 0x0F,
                            0x41, 0x00, 0x0F, 0x00,
                            0x00};



                        
void set_misc()
{
  //udisp_str("?????");
  argport->port=VGA_MISC_WRITE;
  argport->data=0x63;
  outb(argport);
  //udisp_str("!!!!!!");
}

void set_seq()
{
  // write sequence data to index of 0-4
  for(uint8 index = 0; index < 5; index++){
    // first set index
    argport->port=VGA_SEQ_INDEX;
    argport->data=index;
    outb(argport);
    
    // write data at that index
    argport->port=VGA_SEQ_DATA;
    argport->data=seq_data[index];
    // udisp_str("before outb\n");
    outb(argport);
    udisp_str("after outb\n");
  }
}

void set_crtc()
{
    //---------------------------------------------------------
    // outportb(VGA_CRTC_INDEX, 0x03);
    // outportb(VGA_CRTC_DATA, inportb(VGA_CRTC_DATA) | 0x80);
    // outportb(VGA_CRTC_INDEX, 0x11);
    // outportb(VGA_CRTC_DATA, inportb(VGA_CRTC_DATA) & ~0x80);
    //---------------------------------------------------------
  // write crtc data to index of 0-24
  for(uint8 index = 0; index < 25; index++){
    argport->port=VGA_CRTC_INDEX;
    argport->data=index;
    outb(argport);

    argport->port=VGA_CRTC_DATA;
    argport->data=crtc_data[index];
    outb(argport);
  }
}

void set_gc()
{
  // write gc data to index of 0-8
  for(uint8 index = 0; index < 9; index++){
    argport->port=VGA_GC_INDEX;
    argport->data=index;
    outb(argport);

    argport->port=VGA_GC_DATA;
    argport->data=gc_data[index];
    outb(argport);
  }
}

void set_ac()
{
  uint8 d;
  // write ac data to index of 0-20
  for(uint8 index = 0; index < 21; index++){
    argport->port=VGA_AC_INDEX;
    argport->data=index;
    outb(argport);

    argport->port=VGA_AC_WRITE;
    argport->data=ac_data[index];
    outb(argport);
    //outb(VGA_AC_WRITE, ac_data[index]);
  }
  d = inb(VGA_INSTAT_READ);

  argport->port=VGA_AC_INDEX;
  argport->data=d | 0x20;
  outb(argport);
  //outb(VGA_AC_INDEX, d | 0x20);
}

void clear_screen()
{  
  udisp_str("wahahahahahahhaha");
  // for(u32 index = 0; index < VGA_MAX; index++)
  //   vga_buffer[index] = 0;
  // for(u32 index = 0; index < VGA_MAX; index++){
  //   p->x=index / 320;
  //   p->y=index % 320;
  //   p->color = 0x6c;
  //   putpixel(p);  
  // }
  p->x=-1;
  p->y=-1;
  putpixel(p);  
}

void clear_color(uint8 color)
{
  for(u32 index = 0; index < VGA_MAX; index++)
    vga_buffer[index] = color;
}

void init_vga()
{
  udisp_str("111111111\n");
  set_misc();
  udisp_str("222222222\n");
  set_seq();
  udisp_str("333333333\n");
  set_crtc();
  udisp_str("444444444\n");
  set_gc();
  udisp_str("555555555\n");
  set_ac();

 // vga_buffer = (uint8*)VGA_ADDRESS;
  udisp_str("?????");
  // clear_screen();
  udisp_str("!!!!!");
  
}

// void putpixel(u16 x, u16 y, uint8 color)
// {
//   u32 index = 0;
//   index = 320 * y + x;
//   if(index < VGA_MAX)
//     vga_buffer[index] = color;
// }

void draw_line(u16 x1, u16 y1, u16 x2, u16 y2, uint8 color)
{
  if(y1 == y2){
    for(u16 i = x1; i <= x2; i++)
    {
        p->x=i;
        p->y=y1;
        p->color=color;
        putpixel(p);
        //putpixel(i, y1, color);
    }
    return;
  }

  if(x1 == x2){
    for(u16 i = y1; i <= y2; i++){
        p->x=x1;
        p->y=i;
        p->color=color;
        putpixel(p);
      //sputpixel(x1, i, color);
    }
    return;
  }
}

void draw_rect(u16 x, u16 y, u16 width, u16 height, uint8 color)
{
  draw_line(x, y, x, y + height, color);
  draw_line(x, y, x + width, y, color);
  draw_line(x + width, y, x + width, y + height, color);
  draw_line(x, y + height, x + width, y + height, color);
}

void fill_rect(u16 x, u16 y, u16 width, u16 height, uint8 color)
{
  draw_line(x, y, x, y + height, color);
  draw_line(x, y, x + width, y, color);
  draw_line(x + width, y, x + width, y + height, color);
  draw_line(x, y + height, x + width, y + height, color);
  for(int i = y; i < y + height; i++){
    draw_line(x, i, x + width, i, color);
  }
}

void draw_bresenham_circle(int xc, int yc, int x, int y, uint8 color) 
{ 
  p->x=xc+x;
  p->y= yc+y;
  p->color=color;
  putpixel(p);
  //putpixel(xc+x, yc+y, color); 
  //分割线
  p->x=xc-x;
  p->y= yc+y;
  p->color=color;
  putpixel(p);
  //putpixel(xc-x, yc+y, color); 
  //分割线
  p->x=xc+x;
  p->y= yc-y;
  p->color=color;
  putpixel(p);
  //putpixel(xc+x, yc-y, color); 
   //分割线
   p->x=xc-x;
  p->y= yc-y;
  p->color=color;
  putpixel(p);
  //putpixel(xc-x, yc-y, color); 
   //分割线
   p->x=xc+y;
  p->y= yc+x;
  p->color=color;
  putpixel(p);
 // putpixel(xc+y, yc+x, color); 
   //分割线
   p->x=xc-y;
  p->y= yc+x;
  p->color=color;
  putpixel(p);
  //putpixel(xc-y, yc+x, color); 
   //分割线
  p->x=xc+y;
  p->y= yc-x;
  p->color=color;
  putpixel(p);
  //putpixel(xc+y, yc-x, color); 
   //分割线
  p->x=xc-y;
  p->y= yc-x;
  p->color=color;
  putpixel(p);
  //putpixel(xc-y, yc-x, color); 
} 

void draw_circle(u16 x, u16 y, u16 radius, uint8 color)
{
  int x2 = 0, y2 = radius;
  int d = 3 - 2 * radius;
  draw_bresenham_circle(x, y, x2, y2, color);
  while(y2 >= x2){
    x2++;
    if(d > 0){
      y2--;
      d = d + 4 * (x2 - y2) + 10;
    }else{
      d = d + 4 * x2 + 6;
    } 
    draw_bresenham_circle(x, y, x2, y2, color);
  } 
}

void draw_diamond(u16 x, u16 y, u16 radius, uint8 color)
{
  u16 x2 = 0, y2 = radius;
  u16 d = 3 - 2 * radius;
  draw_bresenham_circle(x, y, x2, y2, color);
  while(y2 >= x2){
    x2++;
    if(d > 0){
      y2--;
      d = d + 4 * (x2 - y2) + 10;
    }else{
      d = d + 4 * x2 + 6;
    } 
    draw_bresenham_circle(x, y, x2, y2, color);
  } 
}


// --------------------------------------------------------------
//                          bitmap.c
// --------------------------------------------------------------
// 0 = no-pixel, 1 = pixel

uint8 bitmaps_0_9[10][BITMAP_SIZE] = {
  // 0
  {0b01111110, 0b11000011, 0b11000111, 0b11001111,
   0b11011011, 0b11110011, 0b11100011, 0b01111110},

  // 1
  {0b00011000, 0b00111000, 0b00111000, 0b00011000,
   0b00011000, 0b00011000, 0b01111110, 0b01111110},

  // 2
  {0b00111100, 0b11100111, 0b00000111, 0b00000110,
   0b00011110, 0b01111000, 0b11100011, 0b11111111},

  // 3
  {0b00111100, 0b11100111, 0b00000111, 0b00011100,
   0b00000111, 0b00000111, 0b11100110, 0b00111100},

  // 4
  {0b00011100, 0b00111100, 0b01101100, 0b11001100,
   0b11001100, 0b11111110, 0b00001100, 0b00011110},

  // 5
  {0b11111111, 0b11000000, 0b11111110, 0b00000111,
   0b00000111, 0b00000111, 0b11000110, 0b01111110},

  // 6
  {0b00011100, 0b00110000, 0b01100000, 0b11000000,
   0b11111110, 0b11000011, 0b11000011, 0b01111110},

  // 7
  {0b11111111, 0b11111111, 0b11000111, 0b00000111,
   0b00001110, 0b00111000, 0b00111000, 0b00111000},

  // 8
  {0b01111110, 0b01111110, 0b11000011, 0b11000011,
   0b01111110, 0b11000011, 0b11000011, 0b01111110},

  // 9
  {0b01111110, 0b11000011, 0b11000011, 0b01111111,
   0b00000011, 0b00000111, 0b00001110, 0b01111100},
};


uint8 bitmaps_A_Z[26][BITMAP_SIZE] = {
  // A
  {0b00011000, 0b00111100, 0b01100110, 0b11000011,
   0b11000011, 0b11111111, 0b11000011, 0b11000011},

  // B
  {0b11111100, 0b01100110, 0b01100110, 0b01111100,
   0b01111100, 0b01100110, 0b01100110, 0b11111100},

  // C
  {0b00111110, 0b01100011, 0b11000000, 0b11000000,
   0b11000000, 0b11000000, 0b01100011, 0b00111110},

  // D
  {0b11111100, 0b01100110, 0b01100011, 0b01100011,
   0b01100011, 0b01100011, 0b01100110, 0b11111100},
  
  // E
  {0b11111111, 0b01100001, 0b01100000, 0b01100100,
   0b01111100, 0b01100100, 0b01100001, 0b11111111},

  // F
  {0b11111111, 0b01100001, 0b01100000, 0b01100100,
   0b01111100, 0b01100100, 0b01100000, 0b11110000},

  // G
  {0b00111110, 0b01100011, 0b11000000, 0b11000000,
   0b11000111, 0b11100011, 0b01100011, 0b00111111},

  // H
  {0b11000011, 0b11000011, 0b11000011, 0b11000011,
   0b11111111, 0b11000011, 0b11000011, 0b11000011},

  // I
  {0b01111110, 0b00011000, 0b00011000, 0b00011000,
   0b00011000, 0b00011000, 0b00011000, 0b01111110},

  // J
  {0b00001111, 0b00000110, 0b00000110, 0b00000110,
   0b00000110, 0b11000110, 0b11000110, 0b01111100},

   // K
  {0b11100011, 0b01100011, 0b01100110, 0b01101100,
   0b01111000, 0b01101100, 0b01100110, 0b11100011},

  // L
  {0b11110000, 0b01100000, 0b01100000, 0b01100000,
   0b01100000, 0b01100001, 0b01100011, 0b11111111},

  // M
  {0b11000011, 0b11100111, 0b11111111, 0b11111111,
   0b11011011, 0b11000011, 0b11000011, 0b11000011},

  // N
  {0b11000011, 0b11100011, 0b11110011, 0b11011011,
   0b11001111, 0b11000111, 0b11000011, 0b11000011},

  // O
  {0b00111100, 0b01100110, 0b11000011, 0b11000011,
   0b11000011, 0b11000011, 0b01100110, 0b00111100},

  // P
  {0b11111110, 0b01100011, 0b01100011, 0b01100011,
   0b01111110, 0b01100000, 0b01100000, 0b11110000},

  // Q
  {0b01111110, 0b11000011, 0b11000011, 0b11000011,
   0b11000011, 0b11001111, 0b01111110, 0b00001111},

  // R
  {0b11111110, 0b01100011, 0b01100011, 0b01111110,
   0b01101110, 0b01100110, 0b01100011, 0b11100011},

  // S
  {0b01111110, 0b11000011, 0b11100000, 0b01110000,
   0b00011111, 0b00000011, 0b11000110, 0b01111100},

  // T
  {0b11111111, 0b10011001, 0b00011000, 0b00011000,
   0b00011000, 0b00011000, 0b00011000, 0b00111100},

  // U
  {0b11000011, 0b11000011, 0b11000011, 0b11000011,
   0b11000011, 0b11000011, 0b11000011, 0b11111111},

  // V
  {0b11000011, 0b11000011, 0b11000011, 0b11000011,
   0b11000011, 0b11000011, 0b00111100, 0b00011000},

  // W
  {0b11000011, 0b11000011, 0b11000011, 0b11000011,
   0b11011011, 0b11111111, 0b11100111, 0b11000011},

  // X
  {0b11000011, 0b11000011, 0b01100110, 0b01100110,
   0b00111100, 0b00111100, 0b01100111, 0b11000011},

  // Y
  {0b11000011, 0b11000011, 0b11000011, 0b11000011,
   0b01111110, 0b000011000, 0b00011000, 0b00111100},

  // Z
  {0b11111111, 0b11000011, 0b10000110, 0b00001100,
   0b00011000, 0b00110001, 0b01100011, 0b11111111}

};

// putpixels of 0-9 bits from right-to-left
void draw_num_bitmaps(u16 index, u16 x, u16 y, uint8 color)
{
  u16 temp = 0, pix = 0;

  for(uint8 i = 0; i < BITMAP_SIZE; i++){
    temp = x;
    x += BITMAP_SIZE;
    pix = bitmaps_0_9[index][i];
    while(pix > 0){
      if(pix & 1){
        p->x=x;
        p->y= y;
        p->color=color;
        putpixel(p);
        //putpixel(x, y, color);
      }
      pix >>= 1;
      x--;  
    }
    x = temp;
    y++;
  }
}

// putpixels of A-Z bits from right-to-left
void draw_alpha_bitmaps(u16 index, u16 x, u16 y, uint8 color)
{
  u16 temp = 0, pix = 0;

  for(uint8 i = 0; i < BITMAP_SIZE; i++){
    temp = x;
    x += BITMAP_SIZE;
    pix = bitmaps_A_Z[index][i];
    while(pix > 0){
      if(pix & 1){
        p->x=x;
        p->y= y;
        p->color=color;
        putpixel(p);
        //putpixel(x, y, color);
      }
      pix >>= 1;
      x--;  
    }
    x = temp;
    y++;
  }
}

void draw_char(u16 x, u16 y, uint8 color, char ch)
{
  if(ch >= '0' && ch <= '9'){
    draw_num_bitmaps(ch - '0', x, y, color);
  }else if(ch >= 'A' && ch <= 'Z'){
    draw_alpha_bitmaps((ch - '0') - 17, x, y, color);
  }
}

void draw_string(u16 x, u16 y, uint8 color, char *str)
{
  u32 index = 0;

  while(str[index]){
    draw_char(x, y, color, str[index]);
    x += BITMAP_SIZE + 1;
    index++;
  }
}

// --------------------------------------------------------------
//                          utils.c
// --------------------------------------------------------------
u32 strlen1(const char* str)
{
  u32 length = 0;
  while(str[length])
    length++;
  return length;
}

u32 digit_count(int num)
{
  u32 count = 0;
  if(num == 0)
    return 1;
  while(num > 0){
    count++;
    num = num/10;
  }
  return count;
}

void itoa(int num, char *number)
{
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}

// --------------------------------------------------------------
//                          kernel.c
// --------------------------------------------------------------
/*
uint8 inb(u16 port)
{
  uint8 data;
  __asm__ __volatile__("inb %1, %0" : "=a"(data) : "Nd"(port));
  return data;
}

void outb(u16 port, uint8 data)
{
  __asm__ __volatile__("outb %0, %1" : : "a"(data), "Nd"(port));
}
*/

uint8 get_input_keycode()
{
  uint8 keycode = 0;
  while((keycode = inb(KEYBOARD_PORT)) != 0){
    if(keycode > 0)
      return keycode;
  }
  return keycode;
}

/*
keep the cpu busy for doing nothing(nop)
so that io port will not be processed by cpu
here timer can also be used, but lets do this in looping counter
*/
void wait_for_io(u32 timer_count)
{
  while(1){
    __asm__ __volatile__("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}

void sleep1(u32 timer_count)
{
  u32 t = 0xeeeeef * timer_count;
  wait_for_io(t);
}

/*
void kernel_entry()
{
  init_vga();
  pong_game();
}
*/


// --------------王翊堃， 新添加----------------------------
#define	VGA_NUM_SEQ_REGS	5
#define	VGA_NUM_CRTC_REGS	25
#define	VGA_NUM_GC_REGS		9
#define	VGA_NUM_AC_REGS		21


static void dump(unsigned char *regs, unsigned count)
{
	unsigned i;

	i = 0;
	printf("\t");
	for(; count != 0; count--)
	{
		printf("0x%02X,", *regs);
		i++;
		if(i >= 8)
		{
			i = 0;
			printf("\n\t");
		}
		else
			printf(" ");
		regs++;
	}
	printf("\n");
}



void read_regs(unsigned char *regs)
{
	unsigned i;


	*regs = inb(VGA_MISC_READ);
	regs++;
  
	for(i = 0; i < VGA_NUM_SEQ_REGS; i++)
	{
    // udisp_str("hahahahahah\n");
    argport->port=VGA_SEQ_INDEX;
    argport->data=i;
    // udisp_str("w2w2w22w2w2w2\n");
    outb(argport);
    // udisp_str("1234567890\n");
		*regs = inb(VGA_SEQ_DATA);
    // udisp_str("98765432\n");
		regs++;
	}
  // udisp_str("qwertyu\n");

	for(i = 0; i < VGA_NUM_CRTC_REGS; i++)
	{
    argport->port=VGA_CRTC_INDEX;
    argport->data=i;
    outb(argport);
		// outportb(VGA_CRTC_INDEX, i);
		*regs = inb(VGA_CRTC_DATA);
		regs++;
	}

	for(i = 0; i < VGA_NUM_GC_REGS; i++)
	{
    argport->port=VGA_GC_INDEX;
    argport->data=i;
    outb(argport);
		// outportb(VGA_GC_INDEX, i);
		*regs = inb(VGA_GC_DATA);
		regs++;
	}

	for(i = 0; i < VGA_NUM_AC_REGS; i++)
	{
		(void)inb(VGA_INSTAT_READ);
    argport->port=VGA_AC_INDEX;
    argport->data=i;
    outb(argport);
		// outportb(VGA_AC_INDEX, i);
		*regs = inb(VGA_AC_READ);
		regs++;
	}

	(void)inb(VGA_INSTAT_READ);
  argport->port=VGA_AC_INDEX;
  argport->data=0x20;
  outb(argport);
	// outportb(VGA_AC_INDEX, 0x20);
}


void dump_regs(unsigned char *regs)
{
	printf("unsigned char g_mode[] =\n");
	printf("{\n");
/* dump MISCELLANEOUS reg */
  printf("/* MISC */\n");
	printf("\t0x%02X,\n", *regs);
	regs++;
  printf("/* SEQ */\n");
	dump(regs, VGA_NUM_SEQ_REGS);
	regs += VGA_NUM_SEQ_REGS;
  printf("/* CRTC */\n");
	dump(regs, VGA_NUM_CRTC_REGS);
	regs += VGA_NUM_CRTC_REGS;
  printf("/* GC */\n");
	dump(regs, VGA_NUM_GC_REGS);
	regs += VGA_NUM_GC_REGS;
  printf("/* AC */\n");
	dump(regs, VGA_NUM_AC_REGS);
	regs += VGA_NUM_AC_REGS;
  printf("};\n");
}



void dump_state(void){
  unsigned char state[61];
  read_regs(state);
  dump_regs(state);
}



void main(int arg,char *argv[])
{
  argport=(PORTDATA*)malloc(sizeof(PORTDATA));
  udisp_str("before dump\n");
  // dump_state();
  udisp_str("after dump\n");
  udisp_str("---------------------------------\n");
  set_misc();
  udisp_str("!!!!!!!!\n");
  // set_seq();
  set_crtc();
  set_gc();
  set_ac();

  dump_regs(seq_data);





  p=(PIXEL*)malloc(sizeof(PIXEL));
  // vga_buffer = (uint8*)VGA_ADDRESS;
  // init_vga();

  // draw_string(60, 160, BRIGHT_GREEN, "PRESS ENTER TO START");
  // pong_game();
}