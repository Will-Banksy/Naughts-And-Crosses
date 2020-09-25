#include "WinningLinePainter.h"
#include <QPainter>
#include "Application.h"

WinningLinePainter::WinningLinePainter(QWidget* parent) : QWidget(parent) {

}

void WinningLinePainter::SetDrawLines(QList<QLine> lines) {
	this->lines = lines;
}

void WinningLinePainter::paintEvent(QPaintEvent* event) {
	QColor background = palette().window().color();
	int backBright = background.value();
	int brightness = backBright > 128 ? backBright - 127 : backBright + 127;
	QColor col = QColor::fromHsl(0, 0, brightness);
	const QBrush brush = QBrush(col);

	float lineSize = width() / 20;

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setPen(QPen(brush, lineSize, Qt::SolidLine, Qt::RoundCap));

	for(QLine line : lines) {
		QPoint start = Application::Instance().grid.at(line.p1().x(), line.p1().y())->geometry().center();
		QPoint end = Application::Instance().grid.at(line.p2().x(), line.p2().y())->geometry().center();

		painter.drawLine(start, end);
	}
}