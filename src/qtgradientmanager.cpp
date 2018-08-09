#include "qtgradientmanager.h"
#include <QtGui/QPixmap>
#include <QtCore/QMetaEnum>

QtGradientManager::QtGradientManager(QObject *parent)
	: QObject(parent)
{
}

QMap<QString, QGradient> QtGradientManager::gradients() const
{
	return m_idToGradient;
}

QString QtGradientManager::uniqueId(const QString &id) const
{
	if (!m_idToGradient.contains(id))
		return id;

	QString base = id;
	while (base.count() > 0 && base.at(base.count() - 1).isDigit())
		base = base.left(base.count() - 1);
	QString newId = base;
	int counter = 0;
	while (m_idToGradient.contains(newId)) {
		++counter;
		newId = base + QString::number(counter);
	}
	return newId;
}

QString QtGradientManager::addGradient(const QString &id, const QGradient &gradient)
{
	QString newId = uniqueId(id);

	m_idToGradient[newId] = gradient;

	emit gradientAdded(newId, gradient);

	return newId;
}

void QtGradientManager::removeGradient(const QString &id)
{
	if (!m_idToGradient.contains(id))
		return;

	emit gradientRemoved(id);

	m_idToGradient.remove(id);
}

void QtGradientManager::renameGradient(const QString &id, const QString &newId)
{
	if (!m_idToGradient.contains(id))
		return;

	if (newId == id)
		return;

	QString changedId = uniqueId(newId);
	QGradient gradient = m_idToGradient.value(id);

	emit gradientRenamed(id, changedId);

	m_idToGradient.remove(id);
	m_idToGradient[changedId] = gradient;
}

void QtGradientManager::changeGradient(const QString &id, const QGradient &newGradient)
{
	if (!m_idToGradient.contains(id))
		return;

	if (m_idToGradient.value(id) == newGradient)
		return;

	emit gradientChanged(id, newGradient);

	m_idToGradient[id] = newGradient;
}

void QtGradientManager::clear()
{
	QMap<QString, QGradient> grads = gradients();
	QMapIterator<QString, QGradient> itGrad(grads);
	while (itGrad.hasNext()) {
		removeGradient(itGrad.next().key());
	}
}
