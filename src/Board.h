#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

/**
 * @todo write docs
 */
class Board : public QWidget {
	public:
		Board(QWidget* parent = nullptr);
		virtual void paintEvent(QPaintEvent* event) override;
		void resizeEvent(QResizeEvent* event) override;
};

#endif // BOARD_H
