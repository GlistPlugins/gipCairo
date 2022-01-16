/*
 * gipCairo.h
 *
 *  Created on: 15 Jan 2022
 *      Author: noyan
 */

#ifndef SRC_GIPCAIRO_H_
#define SRC_GIPCAIRO_H_

#include "gBasePlugin.h"
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <cairo/cairo-svg.h>


class gipCairo : public gBasePlugin{
public:
	enum {
		FILETYPE_PDF, FILETYPE_SVG, FILETYPE_PNG
	};

	enum {
		FONTFAMILY_SANS, FONTFAMILY_SERIF, FONTFAMILY_MONOSPACE, FONTFAMILY_CURSIVE, FONTFAMILY_FANTASY
	};

	enum {
		FONTSLANT_NORMAL, FONTSLANT_ITALIC, FONTSLANT_OBLIQUE
	};

	enum {
		FONTWEIGHT_NORMAL, FONTWEIGHT_BOLD
	};

	gipCairo();
	virtual ~gipCairo();

	void create(std::string fileName, int width, int height, int fileType = FILETYPE_PDF);
	void close();
	void show();

	void setColor(int r, int g, int b, int a = 255);
	void setColor(double r, double g, double b, double a = 1.0);
	void setFontSize(double fontSize);
	void setFontFace(int fontFamily, int fontSlant, int fontWeight);

	void drawText(std::string text, double x, double y);
	void drawTextOutlined(std::string text, double x, double y, double thickness = 1.0, int out_r = 0, int out_g = 0, int out_b = 0, int out_a = 255);
	void drawImage(std::string fileName, double x, double y, double width = 0.0, double height = 0.0);
	void drawLine(double x1, double y1, double x2, double y2, double thickness = 1.0);
	void drawRectangle(double x, double y, double width, double height, bool isFilled = false, double thickness = 1.0);
	void drawCircle(double x, double y, double radius, bool isFilled = false, double thickness = 1.0);
	void drawArc(double x, double y, double radius, double startAngle, double endAngle, bool isClosed = false, bool isFilled = false, double thickness = 1.0);
	void drawEllipse(double x, double y, double radius1, double radius2, bool isFilled = false, double thickness = 1.0);


	std::string getPath();
	int getType();
	int getWidth();
	int getHeight();
	double getFontSize();
	int getFontFamily();
	int getFontSlant();
	int getFontWeight();
	double getColorRed();
	double getColorGreen();
	double getColorBlue();
	double getColorAlpha();

private:
	std::string filepath;
	int filetype;
	int width, height;
	cairo_surface_t* csurface;
	cairo_t* ctx;
	double color_r, color_g, color_b, color_a;
	double fontsize;
	int fontfamily, fontslant, fontweight;
	std::string fontfamilytype[5];
	cairo_font_slant_t fontslanttype[3];
	cairo_font_weight_t fontweighttype[2];
};

#endif /* SRC_GIPCAIRO_H_ */
