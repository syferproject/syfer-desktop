// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2022 Conceal Network & Conceal Devs

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QDialog>
#include <QTimer>

#include "EditableStyle.h"

namespace Ui
{
  class Notification;
}

namespace WalletGui
{
  class Notification : public QDialog, EditableStyle
  {
    Q_OBJECT

  public:
    explicit Notification(QWidget* parent = nullptr);
    Notification(const Notification& notification);
    Notification& operator=(const Notification& notification);
    ~Notification();
    void notify(const QString& message);
    
    void applyStyles() override;

  private:
    QWidget* parent;
    Ui::Notification* m_ui;
    QTimer* timer;
    void fadeOut();
  };
}  // namespace WalletGui
#endif  // NOTIFICATION_H
