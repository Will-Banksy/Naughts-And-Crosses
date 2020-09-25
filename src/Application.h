#ifndef APPLICATION_H
#define APPLICATION_H

#include <QStatusBar>
#include "GameGrid.h"
#include "WinningLinePainter.h"

enum Player {
	P_NAUGHTS,
	P_CROSSES
};

class Application {
	private:
		Application();
		~Application() = default;

	public:
		static Application& Instance();

		void SwitchPlayer();
		QList<QLine> HasWin(Type* winner = nullptr);
		void NewGame();

		Player player = P_CROSSES;
		QStatusBar* messageArea;
		GameGrid grid;
		bool gameFinished;
		WinningLinePainter* winPainter;
};

#endif // APPLICATION_H