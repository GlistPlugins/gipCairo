/*
 * gipCairo.cpp
 *
 *  Created on: 15 Jan 2022
 *      Author: noyan
 */

#include "gipCairo.h"


gipCairo::gipCairo() {
	filepath = "";
	filetype = FILETYPE_PDF;
	width = 0;
	height = 0;
	color_r = 0.0;
	color_g = 0.0;
	color_b = 0.0;
	color_a = 1.0;
	fontsize = 10.0;
	fontfamilytype[FONTFAMILY_SANS] = "sans-serif";
	fontfamilytype[FONTFAMILY_SERIF] = "serif";
	fontfamilytype[FONTFAMILY_MONOSPACE] = "monospace";
	fontfamilytype[FONTFAMILY_CURSIVE] = "cursive";
	fontfamilytype[FONTFAMILY_FANTASY] = "fantasy";
	fontslanttype[FONTSLANT_NORMAL] = CAIRO_FONT_SLANT_NORMAL;
	fontslanttype[FONTSLANT_ITALIC] = CAIRO_FONT_SLANT_ITALIC;
	fontslanttype[FONTSLANT_OBLIQUE] = CAIRO_FONT_SLANT_OBLIQUE;
	fontweighttype[FONTWEIGHT_NORMAL] = CAIRO_FONT_WEIGHT_NORMAL;
	fontweighttype[FONTWEIGHT_BOLD] = CAIRO_FONT_WEIGHT_BOLD;
	fontfamily = FONTFAMILY_SANS;
	fontslant = FONTSLANT_NORMAL;
	fontweight = FONTWEIGHT_NORMAL;
}

gipCairo::~gipCairo() {
}

void gipCairo::create(std::string fileName, int width, int height, int fileType) {
	filepath = gGetFilesDir() + fileName;
	filetype = fileType;
	this->width = width;
	this->height = height;

	if(filetype == FILETYPE_PDF) {
		csurface = cairo_pdf_surface_create(filepath.c_str(), width, height);
	} else if (filetype == FILETYPE_SVG) {
		csurface = cairo_svg_surface_create(filepath.c_str(), width, height);
	} else if (filetype == FILETYPE_PNG) {
		csurface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
	}

	// Creating a cairo context
	ctx = cairo_create(csurface);
	setColor(color_r, color_g, color_b, color_a);
	setFontFace(fontfamily, fontslant, fontweight);
}

void gipCairo::close() {
	if(filetype == FILETYPE_PNG) {
		cairo_surface_write_to_png(csurface, filepath.c_str());
	} else {
		cairo_show_page(ctx);
		cairo_surface_flush(csurface);
	}

	cairo_destroy(ctx);
	cairo_surface_destroy(csurface);
}

void gipCairo::show() {
	std::string command = "xdg-open " + filepath;
	system(command.c_str());
}

std::string gipCairo::getPath() {
	return filepath;
}

int gipCairo::getType() {
	return filetype;
}

int gipCairo::getWidth() {
	return width;
}

int gipCairo::getHeight() {
	return height;
}

void gipCairo::setColor(int r, int g, int b, int a) {
	color_r = r / 255.0;
	color_g = g / 255.0;
	color_b = b / 255.0;
	color_a = a / 255.0;
	cairo_set_source_rgba(ctx, color_r, color_g, color_b, color_a);
}

void gipCairo::setColor(double r, double g, double b, double a) {
	color_r = r;
	color_g = g;
	color_b = b;
	color_a = a;
	cairo_set_source_rgba(ctx, color_r, color_g, color_b, color_a);
}

double gipCairo::getColorRed() {
	return color_r;
}

double gipCairo::getColorGreen() {
	return color_g;
}

double gipCairo::getColorBlue() {
	return color_b;
}

double gipCairo::getColorAlpha() {
	return color_a;
}

void gipCairo::setFontSize(double fontSize) {
	fontsize = fontSize;
	cairo_set_font_size(ctx, fontsize);
}

double gipCairo::getFontSize() {
	return fontsize;
}

void gipCairo::setFontFace(int fontFamily, int fontSlant, int fontWeight) {
	fontfamily = fontFamily;
	fontslant = fontSlant;
	fontweight = fontWeight;
	cairo_select_font_face(ctx, fontfamilytype[fontfamily].c_str(), fontslanttype[fontslant], fontweighttype[fontweight]);
}

int gipCairo::getFontFamily() {
	return fontfamily;
}

int gipCairo::getFontSlant() {
	return fontslant;
}

int gipCairo::getFontWeight() {
	return fontweight;
}

void gipCairo::drawLine(double x1, double y1, double x2, double y2, double thickness) {
	cairo_set_line_width(ctx, thickness);
	cairo_move_to(ctx, x1, y1);
	cairo_line_to(ctx, x2, y2);
	cairo_stroke(ctx);
}

void gipCairo::drawRectangle(double x, double y, double width, double height, bool isFilled, double thickness) {
	cairo_set_line_width(ctx, thickness);
	cairo_rectangle(ctx, x, y, width, height);
	if(isFilled) cairo_fill(ctx);
	else cairo_stroke(ctx);
}

void gipCairo::drawCircle(double x, double y, double radius, bool isFilled, double thickness) {
	cairo_set_line_width(ctx, thickness);
	cairo_arc(ctx, x, y, radius, 0, 2 * PI);
	if(isFilled) cairo_fill(ctx);
	else cairo_stroke(ctx);
}

void gipCairo::drawArc(double x, double y, double radius, double startAngle, double endAngle, bool isClosed, bool isFilled, double thickness) {
	cairo_set_line_width(ctx, thickness);
	cairo_arc(ctx, x, y, radius, startAngle, endAngle);
	if(isClosed) cairo_close_path(ctx);
	if(isFilled) cairo_fill(ctx);
	else cairo_stroke(ctx);
}

void gipCairo::drawEllipse(double x, double y, double radius1, double radius2, bool isFilled, double thickness) {
	cairo_set_line_width(ctx, thickness);
	cairo_translate(ctx, x, y);
	cairo_scale(ctx, 1, radius2 / radius1);
	cairo_arc(ctx, 0, 0, radius1, 0, PI * 2);
	if(isFilled) cairo_fill(ctx);
	else cairo_stroke(ctx);
	cairo_scale(ctx, 1, radius1 / radius2);
	cairo_translate(ctx, -x, -y);
}

void gipCairo::drawText(std::string text, double x, double y) {
	cairo_move_to(ctx, x, y);
	cairo_show_text(ctx, text.c_str());
}

void gipCairo::drawTextOutlined(std::string text, double x, double y, double thickness, int out_r, int out_g, int out_b, int out_a) {
	cairo_move_to(ctx, x, y);
	cairo_text_path(ctx, text.c_str());
	cairo_set_source_rgba(ctx, color_r, color_g, color_b, color_a);
	cairo_fill_preserve(ctx);
	cairo_set_source_rgba(ctx, out_r / 255.0, out_g / 255.0, out_b / 255.0, out_a / 255.0);
	cairo_set_line_width(ctx, thickness);
	cairo_stroke(ctx);
}

void gipCairo::drawImage(std::string fileName, double x, double y, double width, double height) {
	std::string imagepath = gGetImagesDir() + fileName;
	cairo_surface_t* image = cairo_image_surface_create_from_png(imagepath.c_str());
	double imagewidth = cairo_image_surface_get_width(image);
	double imageheight = cairo_image_surface_get_height(image);
	double drawx = x;
	double drawy = y;
	bool scaling = false;
	if (width == 0.0 && height == 0) {
		width = imagewidth;
		height = imageheight;
	}
	if(width != imagewidth || height != imageheight) {
		scaling = true;
		drawx = 0;
		drawy = 0;
	}

	if(scaling) {
		cairo_translate(ctx, x, y);
		cairo_scale(ctx, width / imagewidth, height / imageheight);
	}
	cairo_set_source_surface(ctx, image, drawx, drawy);
	cairo_paint(ctx);
	cairo_surface_destroy(image);
	if(scaling) {
		cairo_scale(ctx, imagewidth / width, imageheight / height);
		cairo_translate(ctx, -x, -y);
	}
}

