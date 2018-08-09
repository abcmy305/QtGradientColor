#ifndef GRADIENTMANAGER_H
#define GRADIENTMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QSize>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtGui/QGradient>

class QGradient;
class QPixmap;
class QColor;

class QtGradientManager : public QObject
{
	Q_OBJECT
public:
	QtGradientManager(QObject *parent = 0);

	QMap<QString, QGradient> gradients() const;

	QString uniqueId(const QString &id) const;

	public slots:

		QString addGradient(const QString &id, const QGradient &gradient);
		void renameGradient(const QString &id, const QString &newId);
		void changeGradient(const QString &id, const QGradient &newGradient);
		void removeGradient(const QString &id);

		//utils
		void clear();

signals:

		void gradientAdded(const QString &id, const QGradient &gradient);
		void gradientRenamed(const QString &id, const QString &newId);
		void gradientChanged(const QString &id, const QGradient &newGradient);
		void gradientRemoved(const QString &id);

private:

	QMap<QString, QGradient> m_idToGradient;
};

#endif
