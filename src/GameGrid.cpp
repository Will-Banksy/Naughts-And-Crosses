#include "GameGrid.h"

GameGrid::GameGrid() {
	cells = QList<Cell*>();
	for(int i = 0; i < 9; i++) {
		cells.append(nullptr);
	}
}

void GameGrid::putAt(uchar i, uchar j, Cell* cell) {
	int index = i + j * 3;
	if(index < 9) {
		cells[index] = cell;
	}
}

Cell* GameGrid::at(uchar i, uchar j) const {
	int index = i + j * 3;
	if(index < 9) {
		return cells.at(index);
	}
	return nullptr;
}

QPoint GameGrid::find(Cell* cell) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(at(i, j) == cell) {
				return QPoint(i, j);
			}
		}
	}
	return QPoint(-1, -1);
}

Type GameGrid::checkCells(QList<QPoint> points) {
	Type type = EMPTY;
	for(int i = 0; i < points.size(); i++) {
		const QPoint& p = points.at(i);
		if(i == 0) {
			type = at(p.x(), p.y())->GetType();
		} else {
			if(type != at(p.x(), p.y())->GetType()) {
				type = EMPTY;
				break;
			}
		}
	}
	return type;
}
