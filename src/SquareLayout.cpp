#include "SquareLayout.h"
#include <iostream>
#include <QWidget>

SquareLayout::SquareLayout(QWidget* parent) : QLayout(parent) {
}

SquareLayout::~SquareLayout() {
// 	QLayoutItem *l;
// 	while ((l = takeAt(0))) {
// 		delete l;
// 	}
	// Seems to crash the program when closed
}

int SquareLayout::count() const {
	return items.size();
}

QLayoutItem* SquareLayout::takeAt(int index) {
	return items.takeAt(index);
}

QLayoutItem* SquareLayout::itemAt(int index) const {
	return items.value(index);
}

void SquareLayout::addItem(QLayoutItem* item) {
	if(count() == 0) {
		items.append(item);
	}
}

QSize SquareLayout::sizeHint() const {
	QSize maxSize;
	for(QLayoutItem* item : items) {
		maxSize = maxSize.expandedTo(item->sizeHint());
	}
	return maxSize;
}

QSize SquareLayout::minimumSize() const {
	QSize maxSize;
	for(QLayoutItem* item : items) {
		maxSize = maxSize.expandedTo(item->minimumSize());
	}
	return maxSize;
}

void SquareLayout::setGeometry(const QRect& available) {
	if(count() == 1) {
		QLayoutItem* item = items.at(0);

		int size = std::min(available.width(), available.height());
		QPoint pos;

		if(size == available.width()) {
			pos.setY((available.height() / 2) - (size / 2));
		} else {
			pos.setX((available.width() / 2) - (size / 2));
		}

		item->setGeometry(QRect(pos.x(), pos.y(), size, size));
	}
}