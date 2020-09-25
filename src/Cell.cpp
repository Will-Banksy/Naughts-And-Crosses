#include "Cell.h"
#include "Application.h"
#include <QPainter>

Cell::Cell(QWidget* parent) : QWidget(parent) {
	setMinimumSize(QSize(90, 90));
}

const Type& Cell::GetType() {
	return type;
}

void Cell::SetType(Type type) {
	this->type = type;
}

void Cell::mousePressEvent(QMouseEvent* event) {
	if(Application::Instance().gameFinished) {
		Application::Instance().NewGame();
	} else if(type == EMPTY) {
		Player player = Application::Instance().player;
		if(player == P_CROSSES) {
			SetType(CROSSES);
		} else {
			SetType(NAUGHTS);
		}
		Application::Instance().SwitchPlayer();
		update();
	}
}

void Cell::paintEvent(QPaintEvent* event) { // TODO: Will need to record which position it's in in the matrix/grid
	QColor background = palette().window().color();
	int backBright = background.value();
	int brightness = backBright > 128 ? backBright - 127 : backBright + 127;
	QColor col = QColor::fromHsl(0, 0, brightness);
	const QBrush brush = QBrush(col);

	float lineSize = width() / 30;
	int padding = width() / 6;

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(QPen(brush, lineSize, Qt::SolidLine, Qt::RoundCap));

	if(type == CROSSES) {
		painter.drawLine(padding, padding, width() - padding, height() - padding);
		painter.drawLine(width() - padding, padding, padding, height() - padding);
	} else if(type == NAUGHTS) {
		painter.drawEllipse(padding, padding, width() - padding * 2, height() - padding * 2);
	}

	QPoint thisCellPos = Application::Instance().grid.find(this);
	if(thisCellPos != QPoint(-1, -1)) {
		painter.setPen(QPen(brush, 1));

// 		if(thisCellPos == UPPER_MIDDLE) {
// 			painter.drawLine(0, 0, 0, height() - 1);
// 		} else if(thisCellPos == MIDDLE_MIDDLE) {
// 			painter.drawLine(0, 0, 0, height() - 1);
// 		}
	}
}
