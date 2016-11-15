/*
 * gui_components.h
 *
 *  Created on: Nov 14, 2016
 *      Author: root
 */

#ifndef GUI_COMPONENTS_H_
#define GUI_COMPONENTS_H_


/**
 * -----------------------------------------------------------------------------------------------------
 * 												INCLUDES
 * -----------------------------------------------------------------------------------------------------
 */
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cmsis_device.h"
#include "sam3x_conf.h"

#include "display_driver.h"
#include "graphic_driver.h"

/**
 * -----------------------------------------------------------------------------------------------------
 * 											USED COMPONENTS
 * -----------------------------------------------------------------------------------------------------
 */
#define USE_TEXTFIELD
#define USE_TEXTFEED

/**
 * -----------------------------------------------------------------------------------------------------
 * 												DEFINES
 * -----------------------------------------------------------------------------------------------------
 */

/**
 * -----------------------------------------------------------------------------------------------------
 * 										   TYPEDEFS, variables
 * -----------------------------------------------------------------------------------------------------
 */
typedef struct TextField {
	char text[40];				/* The text contained within this TextField_t instance. */
	uint16_t row;				/* Row of the first character */
	uint16_t col;				/* column of the first character, defines location for the TextField */
	uint16_t width;				/* width in terms of characters */
	bool isSelected;			/* true if this TextField is selected */
	char align;					/* Align struct */
	void (*cbTextField)(void);	/* Callback function for this TextField */
} TextField_t;

TextField_t* selectedTextField; /* the currently selected TextField */

typedef struct TextFeed {
	char strings[16][40];		/* The strings displayed in this TextFeed */
	uint16_t head;				/* The index of the first string */
	uint16_t tail;				/* The index of the last added string */
	uint16_t size;
	uint16_t row;				/* Row of the first character */
	uint16_t col;				/* column of the first character, defines location for the TextFeed */
	uint16_t width;				/* width in terms of characters */
	uint16_t height;			/* height in terms of characters */
} TextFeed_t;

/**
 * -----------------------------------------------------------------------------------------------------
 * 												PROTOTYPES
 * -----------------------------------------------------------------------------------------------------
 */
/**
 * Creates a TextField.
 */
void gui_TextField_init(
		TextField_t* field,
		char* initText,
		uint16_t row,				/* Row of the first character */
		uint16_t col,				/* column of the first character, defines location for the TextField */
		uint16_t width,				/* width in terms of characters */
		void (*cbTextField)(void)   /* Callback function for this TextField */
);

/**
 * Select textField.
 */
void gui_TextField_select(TextField_t* txtField);

/**
 * Shows the specified TextField on the screen.
 */
void gui_TextField_show(TextField_t* txtField);

/**
 * Set the text contained within a TextField.
 */
void gui_TextField_setText(TextField_t* field, char* text);

/**
 * Handles a keypress.
 */
void gui_handle_keypress(char ch);

/*
 * Creates a TextFeed.
 */
void gui_TextFeed_init(
		TextFeed_t* feed,
		uint16_t row,				/* Row of the first character */
		uint16_t col,				/* column of the first character, defines location for the TextFeed */
		uint16_t width,				/* width in terms of characters */
		uint16_t height				/* height in terms of characters */
);

/*
 * Displays the TextFeed on the screen.
 */
void gui_TextFeed_show(TextFeed_t* feed);

/**
 * Adds a string to the TextFeed.
 */
void gui_TextFeed_puts(TextFeed_t* feed, char* text);

#endif /* GUI_COMPONENTS_H_ */
