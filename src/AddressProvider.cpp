// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2017 Karbowanec developers
// Copyright (c) 2017-2018 The Circle Foundation & Conceal Devs
// Copyright (c) 2018-2022 Conceal Network & Conceal Devs

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QStringList>
#include <QUrl>
#include "Settings.h"
#include "AddressProvider.h"

namespace WalletGui
{

AddressProvider::AddressProvider(QObject *parent) : QObject(parent), m_networkManager()
{
}

AddressProvider::~AddressProvider()
{
}

void AddressProvider::getAddress()
{

  QString _urlString = Settings::instance().getCurrentRemoteNode() + "/feeaddress";
  QUrl url = QUrl::fromUserInput(_urlString);
  if (!url.isValid())
  {
    return;
  }

  QNetworkRequest request(url);
  QNetworkReply *reply = m_networkManager.get(request);
  connect(reply, &QNetworkReply::readyRead, this, &AddressProvider::readyRead);
  connect(reply, &QNetworkReply::finished, reply, &QNetworkReply::deleteLater);
}

void AddressProvider::readyRead()
{
  QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
  QByteArray data = reply->readAll();
  QJsonDocument doc = QJsonDocument::fromJson(data);
  if (doc.isNull())
  {
    return;
  }

  QJsonObject obj = doc.object();
  QString address = obj.value("fee_address").toString();

  if (!address.isEmpty())
  {
    Q_EMIT addressFoundSignal(address);
  }
}

} // namespace WalletGui
