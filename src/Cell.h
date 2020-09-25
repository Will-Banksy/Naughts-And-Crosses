#ifndef CELL_H
#define CELL_H

#include <QWidget>

enum Type {
	EMPTY,
	NAUGHTS,
	CROSSES
};

class Cell : public QWidget {
	public:
		explicit Cell(QWidget* parent = nullptr);
		const Type& GetType();
		void SetType(Type type);

	protected:
		void mousePressEvent(QMouseEvent* event) override;
		void paintEvent(QPaintEvent* event) override;

	private:
		Type type = EMPTY;
};

#endif // CELL_H