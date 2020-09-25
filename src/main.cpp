#include "NaughtsAndCrosses.h"
#include <QApplication>
#include "Application.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
	app.setApplicationName(QObject::tr("Naughts and Crosses"));
	app.setApplicationDisplayName(QObject::tr("Naughts and Crosses"));
    Ext_NaughtsAndCrosses w;

	Application::Instance(); // Create instance of Application

    w.show();
    return app.exec();
}