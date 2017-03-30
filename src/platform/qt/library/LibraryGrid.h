/* Copyright (c) 2014-2017 waddlesplash
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef QGBA_LIBRARY_GRID
#define QGBA_LIBRARY_GRID

#include <QListWidget>

#include "LibraryController.h"

// Predefinitions
namespace Ui { class LibraryGrid; }

namespace QGBA {

class LibraryGrid final : public QListWidget, public AbstractGameList {
Q_OBJECT

public:
	explicit LibraryGrid(QWidget* parent = nullptr);

	// AbstractGameList stuff
	virtual LibraryEntryRef selectedEntry() override;
	virtual void selectEntry(LibraryEntryRef game) override;

	virtual void setViewStyle(LibraryStyle newStyle) override;

	virtual void addEntry(LibraryEntryRef item) override;
	virtual void removeEntry(LibraryEntryRef entry) override;

signals:
	void startGame();

private:
	std::unique_ptr<Ui::LibraryGrid> m_ui;

	QMap<LibraryEntryRef, QListWidgetItem*> m_items;
	LibraryStyle m_currentStyle;
};

}

#endif
