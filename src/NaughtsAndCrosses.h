#ifndef EXT_NAUGHTSANDCROSSES_H
#define EXT_NAUGHTSANDCROSSES_H

#include <QMainWindow>

class Ext_NaughtsAndCrosses : public QMainWindow {
    Q_OBJECT

	public:
		explicit Ext_NaughtsAndCrosses(QWidget *parent = nullptr);
		~Ext_NaughtsAndCrosses() override = default;
};

#endif // EXT_NAUGHTSANDCROSSES_H