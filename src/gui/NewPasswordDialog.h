// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2022 Conceal Network & Conceal Devs

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <QDialog>

#include "EditableStyle.h"

namespace Ui
{
  class NewPasswordDialog;
}

namespace WalletGui
{
  class NewPasswordDialog : public QDialog, public EditableStyle
  {
    Q_OBJECT
    Q_DISABLE_COPY(NewPasswordDialog)

  public:
    explicit NewPasswordDialog(QWidget *_parent);
    ~NewPasswordDialog();
    QString getPassword() const;

    QList<QWidget *> getWidgets() override;
    QList<QPushButton *> getButtons() override;
    QList<QLabel *> getLabels() override;
    void applyStyles() override;

  private:
    QScopedPointer<Ui::NewPasswordDialog> m_ui;

    Q_SLOT void checkPassword(const QString &_password);
  };

}  // namespace WalletGui
