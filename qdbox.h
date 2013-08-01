#ifndef QDBOX_H
#define QDBOX_H
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QStringList>

class qdbox : public QObject
{
    Q_OBJECT

public:
    qdbox();
    void obtain_req_token();
    QString generateNonce(qint32);
    QString parseToken(QString response);
    void build_url(QString& );
    void obtain_access_token();
    void upload();
    void createFolder();
    void listFolder(QString x);
    void accountInfo();
public slots:
    void slotFinished(QNetworkReply *);
    void urlslotFinished(QNetworkReply *);
    void accessslotFinished(QNetworkReply *);
    void uploadslotFinished(QNetworkReply *);
    void createFolderFinished(QNetworkReply *);
    void listFolderFinished(QNetworkReply *);
    void accountInfoFinished(QNetworkReply *);
signals:
    void finished(QNetworkReply *);

private:
    QNetworkAccessManager *m_networkManager;
    QNetworkAccessManager *m_netManager;
    QNetworkAccessManager *m_netMan;
    QNetworkAccessManager *m_net;
    long timestamp;
    QString nonce;
    int continuePos;
    QString oauthToken;
    QString oauthTokenSecret;
};

#endif // QDBOX_H
