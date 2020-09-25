#include "NaughtsAndCrosses.h"
#include "Board.h"
#include "SquareLayout.h"
#include <QStatusBar>
#include "Application.h"

Ext_NaughtsAndCrosses::Ext_NaughtsAndCrosses(QWidget *parent) : QMainWindow(parent) {
	setWindowTitle(tr("Naughts and Crosses"));

	Board* board = new Board();
	SquareLayout* layout = new SquareLayout();
	QWidget* widget = new QWidget();

	layout->addItem(new QWidgetItem(board));
	widget->setLayout(layout);
	setCentralWidget(widget); // Takes ownership of pointer

	statusBar()->showMessage(tr("Turn: Crosses"));

	Application::Instance().messageArea = statusBar();
}