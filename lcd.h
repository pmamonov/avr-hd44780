#pragma once

#include <avr/io.h>

// Edit these
#define LCD_RS 5
#define LCD_RS_PORT B
#define LCD_RW 4
#define LCD_RW_PORT B
#define LCD_EN 3
#define LCD_EN_PORT B
#define LCD_D0 0
#define LCD_D0_PORT C
#define LCD_D1 1
#define LCD_D1_PORT C
#define LCD_D2 2
#define LCD_D2_PORT C
#define LCD_D3 3
#define LCD_D3_PORT C

#define LCD_COL_COUNT 8
#define LCD_ROW_COUNT 2

// The rest should be left alone
#define __cat1(A, B)	A ## B
#define __cat(A, B)	__cat1(A, B)

#define LCD_DDR_RS	__cat(DDR, LCD_RS_PORT)
#define LCD_PORT_RS	__cat(PORT, LCD_RS_PORT)
#define LCD_DDR_RW	__cat(DDR, LCD_RW_PORT)
#define LCD_PORT_RW	__cat(PORT, LCD_RW_PORT)
#define LCD_DDR_EN	__cat(DDR, LCD_EN_PORT)
#define LCD_PORT_EN	__cat(PORT, LCD_EN_PORT)
#define LCD_DDR_D0	__cat(DDR, LCD_D0_PORT)
#define LCD_PORT_D0	__cat(PORT, LCD_D0_PORT)
#define LCD_DDR_D1	__cat(DDR, LCD_D1_PORT)
#define LCD_PORT_D1	__cat(PORT, LCD_D1_PORT)
#define LCD_DDR_D2	__cat(DDR, LCD_D2_PORT)
#define LCD_PORT_D2	__cat(PORT, LCD_D2_PORT)
#define LCD_DDR_D3	__cat(DDR, LCD_D3_PORT)
#define LCD_PORT_D3	__cat(PORT, LCD_D3_PORT)

#define LCD_CLEARDISPLAY   0x01
#define LCD_RETURNHOME     0x02
#define LCD_ENTRYMODESET   0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT    0x10
#define LCD_FUNCTIONSET    0x20
#define LCD_SETCGRAMADDR   0x40
#define LCD_SETDDRAMADDR   0x80

#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON  0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON   0x02
#define LCD_CURSOROFF  0x00
#define LCD_BLINKON    0x01
#define LCD_BLINKOFF   0x00

#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE  0x00
#define LCD_MOVERIGHT   0x04
#define LCD_MOVELEFT    0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE    0x08
#define LCD_1LINE    0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS  0x00

void lcd_init(void);

void lcd_command(uint8_t command);
void lcd_write(uint8_t value);

void lcd_on(void);
void lcd_off(void);

void lcd_clear(void);
void lcd_return_home(void);

void lcd_enable_blinking(void);
void lcd_disable_blinking(void);

void lcd_enable_cursor(void);
void lcd_disable_cursor(void);

void lcd_scroll_left(void);
void lcd_scroll_right(void);

void lcd_set_left_to_right(void);
void lcd_set_right_to_left(void);

void lcd_enable_autoscroll(void);
void lcd_disable_autoscroll(void);

void lcd_create_char(uint8_t location, uint8_t *charmap);

void lcd_set_cursor(uint8_t col, uint8_t row);

void lcd_puts(char *string);
void lcd_printf(char *format, ...);
