#ifndef SQUARELAYOUT_H
#define SQUARELAYOUT_H

#include <QLayout>

/**
 * @todo write docs
 */
class SquareLayout : public QLayout {
	public:
		SquareLayout(QWidget* parent = nullptr);
		~SquareLayout();
		int count() const override;
		QLayoutItem* takeAt(int index) override;
		QLayoutItem* itemAt(int index) const override;
		void addItem(QLayoutItem*) override;
		QSize sizeHint() const override;
		QSize minimumSize() const override;
		void setGeometry(const QRect&) override;

	private:
		QList<QLayoutItem*> items;
};

#endif // SQUARELAYOUT_H
