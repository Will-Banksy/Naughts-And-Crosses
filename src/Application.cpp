#include "Application.h"
#include <iostream>

Application::Application() {
}

Application& Application::Instance() {
	static Application app;
	return app;
}

void Application::SwitchPlayer() {
	// Check for win
	Type* winner = new Type();
	QList<QLine> winLines = HasWin(winner);
	if(!winLines.isEmpty()) {
		if(*winner == CROSSES) {
			messageArea->showMessage(QObject::tr("Winner: Crosses - Click on board to play again"));
		} else {
			messageArea->showMessage(QObject::tr("Winner: Naughts - Click on board to play again"));
		}
		gameFinished = true;
		winPainter->SetDrawLines(winLines);
		winPainter->update();
	}

	// Check for draw
	bool anyEmpty = false;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(grid.at(i, j)->GetType() == EMPTY) {
				anyEmpty = true;
			}
		}
	}
	if(!anyEmpty) {
		gameFinished = true;
		messageArea->showMessage(QObject::tr("Draw - Click on board to play again"));
	}

	if(!gameFinished) {
		if(player == P_CROSSES) {
			player = P_NAUGHTS;
			messageArea->showMessage(QObject::tr("Turn: Naughts"));
		} else {
			player = P_CROSSES;
			messageArea->showMessage(QObject::tr("Turn: Crosses"));
		}
	}
}

// Need to check for possibly multiple winning lines. The way I've done it is terrible but it'll work
QList<QLine> Application::HasWin(Type* winner) {
	if(!winner) {
		winner = new Type();
		*winner = EMPTY;
	}
	QList<QLine> winningLines;
	{ // Check horizontal wins
		Type topWin = grid.checkCells({ QPoint(0, 0), QPoint(0, 1), QPoint(0, 2) });
		Type middleWin = grid.checkCells({ QPoint(1, 0), QPoint(1, 1), QPoint(1, 2) });
		Type bottomWin = grid.checkCells({ QPoint(2, 0), QPoint(2, 1), QPoint(2, 2) });
		if(topWin != EMPTY) {
			winningLines.append(QLine(QPoint(0, 0), QPoint(0, 2)));
			*winner = topWin;
		}
		if(middleWin != EMPTY) {
			winningLines.append(QLine(QPoint(1, 0), QPoint(1, 2)));
			*winner = middleWin;
		}
		if(bottomWin != EMPTY) {
			winningLines.append(QLine(QPoint(2, 0), QPoint(2, 2)));
			*winner = bottomWin;
		}
	}
	{ // Check diagonal wins
		Type diagNegative = grid.checkCells({ QPoint(0, 0), QPoint(1, 1), QPoint(2, 2) }); // Dir: \ :
		Type diagPositive = grid.checkCells({ QPoint(0, 2), QPoint(1, 1), QPoint(2, 0) }); // Dir: / :
		if(diagNegative != EMPTY) {
			winningLines.append(QLine(QPoint(0, 0), QPoint(2, 2)));
			*winner = diagNegative;
		}
		if(diagPositive != EMPTY) {
			winningLines.append(QLine(QPoint(0, 2), QPoint(2, 0)));
			*winner = diagPositive;
		}
	}
	{ // Check vertical wins
		Type leftWin = grid.checkCells({ QPoint(0, 0), QPoint(1, 0), QPoint(2, 0) });
		Type middleWin = grid.checkCells({ QPoint(0, 1), QPoint(1, 1), QPoint(2, 1) });
		Type rightWin = grid.checkCells({ QPoint(0, 2), QPoint(1, 2), QPoint(2, 2) });
		if(leftWin != EMPTY) {
			winningLines.append(QLine(QPoint(0, 0), QPoint(2, 0)));
			*winner = leftWin;
		}
		if(middleWin != EMPTY) {
			winningLines.append(QLine(QPoint(0, 1), QPoint(2, 1)));
			*winner = middleWin;
		}
		if(rightWin != EMPTY) {
			winningLines.append(QLine(QPoint(0, 2), QPoint(2, 2)));
			*winner = rightWin;
		}
	}

	return winningLines;
}

void Application::NewGame() {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			Cell* cell = grid.at(i, j);
			cell->SetType(EMPTY);
			cell->update();
		}
	}
	messageArea->showMessage("Turn: Crosses");
	gameFinished = false;
	player = P_CROSSES;
	winPainter->SetDrawLines(QList<QLine>());
	winPainter->update();
}