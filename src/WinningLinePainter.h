#ifndef WINNINGLINEPAINTER_H
#define WINNINGLINEPAINTER_H

#include <QWidget>

/**
 * @todo write docs
 */
class WinningLinePainter : public QWidget {
	public:
		WinningLinePainter(QWidget* parent);
		/// lines are in grid coordinates
		void SetDrawLines(QList<QLine> lines);

	private:
		QList<QLine> lines;

	protected:
		void paintEvent(QPaintEvent* event) override;
};

#endif // WINNINGLINEPAINTER_H
