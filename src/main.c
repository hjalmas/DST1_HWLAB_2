/**
 * --------------------------------------------------------------------------------------------------
 * 										INCLUDES
 * --------------------------------------------------------------------------------------------------
 */
#include "main.h"

/**
 * --------------------------------------------------------------------------------------------------
 * 										VARIABLES
 * --------------------------------------------------------------------------------------------------
 */
extern bool kpadFlag;
TextField_t txtField1;
TextField_t txtField2;
TextField_t txtField3;
TextField_t txtField4;
TextField_t txtField5;
TextField_t infoTxt;

TextField_t* textFields[] = {
		&txtField1,
		&txtField2,
		&txtField3,
		&txtField4,
		&txtField5
};

uint32_t txtFIdx = 0;

TextFeed_t txtFeed;

/**
 * --------------------------------------------------------------------------------------------------
 * 										DEFINES
 * --------------------------------------------------------------------------------------------------
 */

/**
 * --------------------------------------------------------------------------------------------------
 * 										PROTOTYPES
 * --------------------------------------------------------------------------------------------------
 */
void lcd_init(void);
void gui_init(void);
void cbKeypad(void);
void cbTextField1(void);
void cbTextField2(void);
void cbTextField3(void);
void cbTextField4(void);
void cbTextField5(void);

/**
 * --------------------------------------------------------------------------------------------------
 * 										COMPILER STUFF
 * --------------------------------------------------------------------------------------------------
 */
/**
 * Sample pragmas to cope with warnings. Please note the related line at
 * the end of this function, used to pop the compiler diagnostics status.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"
#pragma GCC diagnostic ignored "-Wconversion"

/**
 * --------------------------------------------------------------------------------------------------
 * 										MAIN
 * --------------------------------------------------------------------------------------------------
 */

/**
 * Normally at this stage most of the microcontroller subsystems, including
 * the clock, were initialised by the CMSIS SystemInit() function invoked
 * from the startup file, before calling main().
 * (see system/src/cortexm/_initialize_hardware.c)
 */
int main(int argc, char* argv[]) {

	/* Disable watchdog timer */
	WDT->WDT_MR = WDT_MR_WDDIS;

	/* Initialize MCU and software stack */
	kpad_init();
	lcd_init();
	gui_init();

	while (1) {
		if (kpadFlag) {
			cbKeypad();
		}
	}

	return EXIT_SUCCESS;
}

/**
 * Initialize lcd screen.
 */
void lcd_init(void) {
	disp_init();
	disp_wr_cmd(CURS_ON_BLINK_ON | TEXT_ON_GRAPHIC_ON);
	disp_wr_cmd(CURSOR_8_LINE);
	disp_wr_hword(CURSOR_AUTOMOVE, 0x0001);
	disp_wr_hword(SET_ADDRESS_PIONTER, FRAME_TEXT_1);
	disp_set_frame(FRAME_1);
	disp_full_clear();

	graph_draw_rect(0, 0, 240, 128);
	graph_draw_rect(2, 2, 236, 124);
}

/**
 * Initialize the graphical user interface.
 */
void gui_init(void) {
	graph_print_textBox("~DST1 HARDWARE LAB 2~", 2, 1, TEXT_ALIGN_CENTER);
	graph_print_text("", 4, 1, TEXT_ALIGN_LEFT);
	gui_TextField_init(&txtField1, "", 4, 2, 10, cbTextField1);
	gui_TextField_init(&txtField2, "", 6, 2, 10, cbTextField2);
	gui_TextField_init(&txtField3, "", 8, 2, 10, cbTextField3);
	gui_TextField_init(&txtField4, "", 10, 2, 10, cbTextField4);
	gui_TextField_init(&txtField5, "", 12, 2, 10, cbTextField5);
	gui_TextField_init(&infoTxt, "", 15, 2, 36, NULL);
	gui_TextField_show(&txtField1);
	gui_TextField_show(&txtField2);
	gui_TextField_show(&txtField3);
	gui_TextField_show(&txtField4);
	gui_TextField_show(&txtField5);
	gui_TextField_show(&infoTxt);
	gui_TextField_select(&txtField1);

	gui_TextFeed_init(&txtFeed, 4, 14, 24, 10);
	gui_TextFeed_show(&txtFeed);
}

/**
 * Callback funtion to handle presses on the keypad.
 */
void cbKeypad(void) {
	volatile uint32_t key = kpad_get_key();

	switch (key) {
	case KEY_0:
		gui_handle_keypress('0');
		break;
	case KEY_1:
		gui_handle_keypress('1');
		break;
	case KEY_2:
		gui_handle_keypress('2');
		break;
	case KEY_3:
		gui_handle_keypress('3');
		break;
	case KEY_4:
		gui_handle_keypress('4');
		break;
	case KEY_5:
		gui_handle_keypress('5');
		break;
	case KEY_6:
		gui_handle_keypress('6');
		break;
	case KEY_7:
		gui_handle_keypress('7');
		break;
	case KEY_8:
		gui_handle_keypress('8');
		break;
	case KEY_9:
		gui_handle_keypress('9');
		break;
	case KEY_A:
		txtFIdx == 0 ? txtFIdx = 4 : txtFIdx--;
		gui_TextField_select(textFields[txtFIdx]);
		break;
	case KEY_B:
		txtFIdx == 4 ? txtFIdx = 0 : txtFIdx++;
		gui_TextField_select(textFields[txtFIdx]);
		break;
	case KEY_C:
		gui_handle_keypress(0x08);
		break;
	case KEY_D:
		gui_handle_keypress(0x0D);
		break;
	default:
		break;
	}
}

/**
 * Callback function to handle actions on TextField1.
 */
void cbTextField1(void) {
	char text[40] = "TextField 1: ";
	strcat(text, txtField1.text);
	gui_TextField_setText(&infoTxt, text);
	gui_TextFeed_puts(&txtFeed, text);
}

/**
 * Callback function to handle actions on TextField2.
 */
void cbTextField2(void) {
	char text[40] = "TextField 2: ";
	strcat(text, txtField2.text);
	gui_TextField_setText(&infoTxt, text);
	gui_TextFeed_puts(&txtFeed, text);
}

/**
 * Callback function to handle actions on TextField3.
 */
void cbTextField3(void) {
	char text[40] = "TextField 3: ";
	strcat(text, txtField3.text);
	gui_TextField_setText(&infoTxt, text);
	gui_TextFeed_puts(&txtFeed, text);
}

/**
 * Callback function to handle actions on TextField4.
 */
void cbTextField4(void) {
	char text[40] = "TextField 4: ";
	strcat(text, txtField4.text);
	gui_TextField_setText(&infoTxt, text);
	gui_TextFeed_puts(&txtFeed, text);
}

/**
 * Callback function to handle actions on TextField4.
 */
void cbTextField5(void) {
	char text[40] = "TextField 5: ";
	strcat(text, txtField5.text);
	gui_TextField_setText(&infoTxt, text);
	gui_TextFeed_puts(&txtFeed, text);
}

#pragma GCC diagnostic pop

/**
 * --------------------------------------------------------------------------------------------------
 * 										EOF
 * --------------------------------------------------------------------------------------------------
 */
