#ifndef GAMEGRID_H
#define GAMEGRID_H

#include "Cell.h"

/**
 * @todo write docs
 */
class GameGrid {
	public:
		GameGrid();
		~GameGrid() = default;
		Cell* at(uchar i, uchar j) const;
		/// Doesn't take ownership of Cell pointer
		void putAt(uchar i, uchar j, Cell* cell);
		QPoint find(Cell* cell);
		/// Checks if all cells in the positions in the list are the same type - If so, return that type, else return EMPTY
		Type checkCells(QList<QPoint> points);

	private:
		QList<Cell*> cells;
};

#endif // GAMEGRID_H
