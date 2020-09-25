#include "Board.h"
#include <QPainter>
#include <QStylePainter>
#include <QStyleOptionFocusRect>
#include <QGridLayout>
#include "Cell.h"
#include "Application.h"
#include "WinningLinePainter.h"
#include <QResizeEvent>
#include <iostream>

Board::Board(QWidget* parent) : QWidget(parent) {
	WinningLinePainter* overlayWidget = new WinningLinePainter(this);
	Application::Instance().winPainter = overlayWidget;

	QGridLayout* layout = new QGridLayout();
	Application::Instance().grid = GameGrid();

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			Cell* cell = new Cell();
			layout->addWidget(cell, i, j);
			Application::Instance().grid.putAt(i, j, cell);
		}
	}

	setLayout(layout);
}

void Board::paintEvent(QPaintEvent* event) {
	QStylePainter stylePainter(this);

	QStyleOptionFocusRect option;
	option.initFrom(this);
	option.backgroundColor = palette().color(QPalette::Background);

	stylePainter.drawPrimitive(QStyle::PE_FrameWindow, option);

	QColor background = palette().window().color();
	int backBright = background.value();
	int brightness = backBright > 128 ? backBright - 127 : backBright + 127;
	QColor col = QColor::fromHsl(0, 0, brightness);
	const QBrush brush = QBrush(col);

	QPainter painter(this);
	painter.setPen(col);

	painter.drawLine(width() / 3, 5, width() / 3, height() - 6);
	painter.drawLine(2 * width() / 3, 5, 2 * width() / 3, height() - 6);

	painter.drawLine(5, height() / 3, width() - 6, height() / 3);
	painter.drawLine(5, 2 * height() / 3, width() - 6, 2 * height() / 3);
}

void Board::resizeEvent(QResizeEvent* event) {
	if(Application::Instance().winPainter) {
		Application::Instance().winPainter->setGeometry(0, 0, event->size().width(), event->size().height());
	}
}
