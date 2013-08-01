#include "qdbox.h"
#include "qjson/parser.h"
#include <QtCore/QCoreApplication>
#include <QVariant>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QtDebug>
#include <QList>
#include <QUrl>
#include <QPair>
#include <QVariant>
#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDateTime>

qdbox::qdbox()
{
    //
}

QString qdbox::generateNonce(qint32 length)
{
    QString clng = "";
    for(int i=0; i<length; ++i)
        clng += QString::number(int( qrand() / (RAND_MAX + 1.0) * (16 + 1 - 0) + 0 ), 16).toUpper();
    return clng;
}

void qdbox::obtain_req_token(){
    timestamp = QDateTime::currentMSecsSinceEpoch()/1000;
    nonce = generateNonce(8);
    QUrl url("https://api.dropbox.com/1/oauth/request_token");
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&");
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");

    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    m_networkManager = new QNetworkAccessManager;   // Instance variable


//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(slotFinished(QNetworkReply *)));
    //qDebug() << url;
    m_networkManager->post(request,"");

}

void qdbox::slotFinished(QNetworkReply* reply){
    qDebug() << "here";
    QByteArray data = reply->readAll();
    qDebug() << data;
    QString oauthtoken = parseToken(data);

    qDebug() << "123" << oauthtoken;
    build_url(oauthtoken);
}

void qdbox::build_url(QString &x){
    QUrl url("https://api.dropbox.com/1/oauth/authorize");
    url.addQueryItem("oauth_token",x);
    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    m_netManager = new QNetworkAccessManager;   // Instance variable


//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_netManager, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(urlslotFinished(QNetworkReply *)));
    qDebug() << "Go to foll. url";
    qDebug() << url;
    m_netManager->post(request,"");

}

void qdbox::urlslotFinished(QNetworkReply* reply){
    qDebug() << "456";
    QByteArray data = reply->readAll();
    qDebug() << data;
    qDebug() << "press enter after allowing app permission";
    QTextStream strin(stdin);
    strin.readLine();
    obtain_access_token();
}

void qdbox::obtain_access_token(){
    QUrl url("https://api.dropbox.com/1/oauth/access_token");
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&"+oauthTokenSecret);
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");
    url.addQueryItem("oauth_token",oauthToken);

    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    m_netMan = new QNetworkAccessManager;   // Instance variable


//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_netMan, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(accessslotFinished(QNetworkReply *)));
    //qDebug() << url;
    m_netMan->post(request,"");

}

void qdbox::accessslotFinished(QNetworkReply* reply){
    qDebug() << "access slot";
    QByteArray data = reply->readAll();
    qDebug() << data;
    parseToken(data);
    upload();
    //createFolder();
    //listFolder("/");
    //accountInfo();
}

void qdbox::accountInfo(){
    QUrl url("https://api.dropbox.com/1/account/info");
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&"+oauthTokenSecret);
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");
    url.addQueryItem("oauth_token",oauthToken);
    //url.addQueryItem("contents","false");

    QNetworkAccessManager* m_netw = new QNetworkAccessManager;   // Instance variable
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    qDebug() << "in account info";

//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_netw, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(accountInfoFinished(QNetworkReply *)));
    //qDebug() << url;
    m_netw->post(request,"");

}

void qdbox::createFolder(){
    qDebug() << "in create folder";
    QString a = QString("https://api.dropbox.com/1/fileops/create_folder?root=") + QString("dropbox&path=/saurabh/newnew");
    qDebug() << "in create folder 1";
    QUrl url(a);
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&"+oauthTokenSecret);
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");
    url.addQueryItem("oauth_token",oauthToken);
    //url.addQueryItem("contents","false");

    qDebug() << "in create folder 2";
    QNetworkAccessManager* m_netw = new QNetworkAccessManager;   // Instance variable
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    qDebug() << "in create folder 3";

//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_netw, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(createFolderFinished(QNetworkReply *)));
    //qDebug() << url;
    m_netw->post(request,"");

}


void qdbox::listFolder(QString x){
    //qDebug() << "in list folder";
    QString a = QString("https://api.dropbox.com/1/metadata/dropbox/") + x;
    //qDebug() << "in list folder 1";
    QUrl url(a);
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&"+oauthTokenSecret);
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");
    url.addQueryItem("oauth_token",oauthToken);
    //url.addQueryItem("overwrite","false");

    //qDebug() << "in list folder 2";
    QNetworkAccessManager* m_netw = new QNetworkAccessManager;   // Instance variable
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    //qDebug() << "in list folder 3";

//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_netw, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(listFolderFinished(QNetworkReply *)));
    //qDebug() << url;
    m_netw->get(request);

}

void qdbox::upload(){
    QString x = QString("https://api-content.dropbox.com/1/files_put/dropbox/") + QString("/saurabh/random.jpg");
    QUrl url(x);
    url.addQueryItem("oauth_consumer_key","bznn0lmg4cv6fj9");
    url.addQueryItem("oauth_nonce", nonce);
    url.addQueryItem("oauth_signature","hsqe2d4eeg2ms0m&"+oauthTokenSecret);
    url.addQueryItem("oauth_signature_method","PLAINTEXT");
    url.addQueryItem("oauth_timestamp", QString::number(timestamp));
    url.addQueryItem("oauth_version","1.0");
    url.addQueryItem("oauth_token",oauthToken);
    url.addQueryItem("overwrite","false");

    QFile file("4.jpg");
    file.open(QIODevice::ReadOnly);

    QByteArray arr = file.readAll();

    file.close();

    QNetworkRequest request;
    request.setUrl(url);

    request.setRawHeader("Content-Type","text/plain");
    m_net = new QNetworkAccessManager;   // Instance variable


//    QObject::connect(m_networkManager, SIGNAL(finished(QNetworkReply *)),
  //  this, SLOT(finishedSlot(QNetworkReply *)));
    QObject::connect(m_net, SIGNAL(finished(QNetworkReply *)),
    this, SLOT(uploadslotFinished(QNetworkReply *)));
    //qDebug() << url;
    m_net->put(request,arr);

}

void qdbox::uploadslotFinished(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    qDebug() << data;
    QJson::Parser parser;
    bool ok;
    QVariant result = parser.parse(data,&ok);
    QVariantMap rmap = result.toMap();
    //qDebug() << "x " << rmap.size();
    QList<QString> a = rmap.uniqueKeys();
    for(int i=0;i<rmap.size();i++){
        qDebug() << i << " " << a[i] << " " << rmap[a[i]].value<QString>();
    }
    qDebug() << "Upload successful";
    createFolder();
}

void qdbox::createFolderFinished(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    qDebug() << data;
    QJson::Parser parser;
    bool ok;
    QVariant result = parser.parse(data,&ok);
    QVariantMap rmap = result.toMap();
    //qDebug() << "x " << rmap.size();
    QList<QString> a = rmap.uniqueKeys();
    for(int i=0;i<rmap.size();i++){
        qDebug() << i << " " << a[i] << " " << rmap[a[i]].value<QString>();
    }
    qDebug() << "Creating folder successful";
    listFolder("/");
}

void qdbox::accountInfoFinished(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    qDebug() << data;
    qDebug() << "Account Info successful";
    QJson::Parser parser;
    bool ok;
    QVariant result = parser.parse(data,&ok);
    QVariantMap rmap = result.toMap();
    //qDebug() << "x " << rmap.size();
    QList<QString> a = rmap.uniqueKeys();
    for(int i=0;i<rmap.size();i++){
        qDebug() << i << " " << a[i] << " " << rmap[a[i]].value<QString>();
    }
}

void qdbox::listFolderFinished(QNetworkReply *reply){
    QByteArray data = reply->readAll();
    //qDebug() << data;
    QJson::Parser parser;
    bool ok;
    QVariant result = parser.parse(data,&ok);
    QVariantMap rmap = result.toMap();
    //qDebug() << "x " << rmap.size();
    QList<QString> a = rmap.uniqueKeys();
    for(int i=0;i<rmap.size();i++){
        //qDebug() << i << " " << a[i] << endl;
        if(a[i] == "contents"){
            //qDebug() << "inside " << rmap[a[i]];
            QVariantList qwe = rmap[a[i]].toList();
            foreach(QVariant abc,qwe){
                //qDebug() << "in " << abc << endl;
                QVariantMap qwer = abc.toMap();
                QList<QString> b = qwer.uniqueKeys();
                //QString temp;
                for(int i=0;i<qwer.size();i++){
                    if((b[i] == "is_dir") || (b[i] == "path")){
                    //qDebug() << i << " " << b[i] << " : " << qwer[b[i]] << " " << qwer[b[i]].value<QString>() << endl;
                    //temp = qwer[b[i]].value<QString>();
                    if(b[i] == "path" && i==4){
                        qDebug() << i << " " << b[i] << " : " << qwer[b[i]] << " " << qwer[b[i]].value<QString>() << endl;
                        QString str = qwer[b[i]].value<QString>().section('/',-1);
                        qDebug() << "str " << str;
                        listFolder(qwer[b[i]].value<QString>());
                        break;
                    }
                    }
                }
            }
        }
    }
    qDebug() << "out";
    return;
    //obtain_req_token();

}

QString qdbox::parseToken(QString response)
{
    //clearError();

    QStringList split = response.split("&");
    /*if(split.size() < 2)
    {
        errorState = QDropbox::APIError;
        errorText  = "The Dropbox API did not respond as expected.";
        emit errorOccured(errorState);
#ifdef QTDROPBOX_DEBUG
        qDebug() << "error " << errorState << "(" << errorText << ") in request" << endl;
#endif
        return;
    }*/

    /*if(!split.at(0).startsWith("oauth_token_secret") ||
            !split.at(1).startsWith("oauth_token"))
    {
        errorState = QDropbox::APIError;
        errorText  = "The Dropbox API did not respond as expected.";
        emit errorOccured(errorState);
#ifdef QTDROPBOX_DEBUG
        qDebug() << "error " << errorState << "(" << errorText << ") in request" << endl;
#endif
        return;
    }*/

    QStringList tokenSecretList = split.at(0).split("=");
    oauthTokenSecret = tokenSecretList.at(1);
    QStringList tokenList = split.at(1).split("=");
    oauthToken = tokenList.at(1);


    return oauthToken;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qdbox w;
    w.obtain_req_token();
    return a.exec();
}
