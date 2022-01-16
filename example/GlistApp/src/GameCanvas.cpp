/*
 * GameCanvas.cpp
 *
 *  Created on: May 6, 2020
 *      Author: noyan
 */


#include "GameCanvas.h"


GameCanvas::GameCanvas(gApp* root) : gBaseCanvas(root) {
	this->root = root;
}

GameCanvas::~GameCanvas() {
}

void GameCanvas::setup() {
	gLogi("GameCanvas") << "setup";
	logo.loadImage("glistengine_logo.png");

	cairo.create("Test.pdf", 620, 877, gipCairo::FILETYPE_PDF);

	cairo.setColor(128, 0, 0);
	cairo.drawRectangle(5, 5, cairo.getWidth() / 2, cairo.getHeight() / 2, false);

	cairo.setColor(0, 0, 128);
	cairo.drawCircle(300, 300, 50, false);

	cairo.setColor(0, 128, 0);
	cairo.drawArc(100, 300, 50, PI / 4, PI, false, false);

	cairo.setColor(255, 255, 0);
	cairo.drawLine(10, 30, 100, 100);

	cairo.setColor(0, 128, 0);
	cairo.drawEllipse(100, 300, 50, 200, false);

	cairo.drawImage("gameicon/icon.png", 200, 400);

	cairo.setFontFace(gipCairo::FONTFAMILY_SANS, gipCairo::FONTSLANT_ITALIC, gipCairo::FONTWEIGHT_NORMAL);
	cairo.setFontSize(20);
	cairo.setColor(255, 255, 0);
	cairo.drawText("Hello GlistEngine Cairo", 10, 20);

	cairo.setFontFace(gipCairo::FONTFAMILY_SANS, gipCairo::FONTSLANT_NORMAL, gipCairo::FONTWEIGHT_BOLD);
	cairo.setFontSize(40);
	cairo.setColor(255, 255, 0);
	cairo.drawTextOutlined("Hello GlistEngine Cairo", 10, 400);

	cairo.close();
	cairo.show();
}

void GameCanvas::update() {
//	gLogi("GameCanvas") << "update";
}

void GameCanvas::draw() {
//	gLogi("GameCanvas") << "draw";
	logo.draw((getWidth() - logo.getWidth()) / 2, (getHeight() - logo.getHeight()) / 2);
}

void GameCanvas::keyPressed(int key) {
//	gLogi("GameCanvas") << "keyPressed:" << key;
}

void GameCanvas::keyReleased(int key) {
//	gLogi("GameCanvas") << "keyReleased:" << key;
}

void GameCanvas::charPressed(unsigned int codepoint) {
//	gLogi("GameCanvas") << "charPressed:" << gCodepointToStr(codepoint);
}

void GameCanvas::mouseMoved(int x, int y) {
//	gLogi("GameCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseDragged(int x, int y, int button) {
//	gLogi("GameCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void GameCanvas::mousePressed(int x, int y, int button) {
}

void GameCanvas::mouseReleased(int x, int y, int button) {
//	gLogi("GameCanvas") << "mouseReleased" << ", button:" << button;
}

void GameCanvas::mouseScrolled(int x, int y) {
//	gLogi("GameCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseEntered() {
}

void GameCanvas::mouseExited() {
}

void GameCanvas::showNotify() {

}

void GameCanvas::hideNotify() {

}

