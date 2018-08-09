#ifndef GRADIENTVIEW_H
#define GRADIENTVIEW_H

#include <QtGui/QWidget>
#include <QtCore/QMap>
#include "ui_qtgradientview.h"

class QtGradientManager;
class QListViewItem;
class QAction;

class QtGradientView : public QWidget
{
	Q_OBJECT
public:
	QtGradientView(QWidget *parent = 0);

	void setGradientManager(QtGradientManager *manager);
	QtGradientManager *gradientManager() const;

	void setCurrentGradient(const QString &id);
	QString currentGradient() const;

signals:
	void currentGradientChanged(const QString &id);
	void gradientActivated(const QString &id);

	private slots:
		void slotGradientAdded(const QString &id, const QGradient &gradient);
		void slotGradientRenamed(const QString &id, const QString &newId);
		void slotGradientChanged(const QString &id, const QGradient &newGradient);
		void slotGradientRemoved(const QString &id);
		void slotNewGradient();
		void slotEditGradient();
		void slotRemoveGradient();
		void slotRenameGradient();
		void slotRenameGradient(QListWidgetItem *item);
		void slotCurrentItemChanged(QListWidgetItem *item);
		void slotGradientActivated(QListWidgetItem *item);

private:
	QMap<QString, QListWidgetItem *> m_idToItem;
	QMap<QListWidgetItem *, QString> m_itemToId;

	QAction *m_newAction;
	QAction *m_editAction;
	QAction *m_renameAction;
	QAction *m_removeAction;

	QtGradientManager *m_manager;
	Ui::QtGradientView m_ui;
};

#endif