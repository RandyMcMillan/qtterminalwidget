/*
 * Modifications and refactoring. Part of QtTerminalWidget:
 * https://github.com/cybercatalyst/qtterminalwidget
 *
 * Copyright (C) 2015 Jacob Dawid <jacob@omg-it.works>
 */

/*
    Copyright 2013 Christian Surlykke

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
    02110-1301  USA.
*/

#pragma once

// Own includes
#include "ui_SearchBar.h"
#include "historysearch.h"

// Qt includes
#include <QRegExp>

class SearchBar : public QWidget {
    Q_OBJECT
public:
    SearchBar(QWidget* parent = 0);
    virtual ~SearchBar();
    virtual void show();
    QString searchText();
    bool useRegularExpression();
    bool matchCase();
    bool highlightAllMatches();

public slots:
    void noMatchFound();

signals:
    void searchCriteriaChanged();
    void highlightMatchesChanged(bool highlightMatches);
    void findNext();
    void findPrevious();

protected:
    virtual void keyReleaseEvent(QKeyEvent* keyEvent);

private slots:
    void clearBackgroundColor();

private:
    Ui::SearchBar widget;
    QAction *m_matchCaseMenuEntry;
    QAction *m_useRegularExpressionMenuEntry;
    QAction *m_highlightMatchesMenuEntry;
};

