
#ifndef DEPISTAGE_TEST_FENETREPRINCIPALE_HPP
#define DEPISTAGE_TEST_FENETREPRINCIPALE_HPP

#include <QObject>
#include <ActiveQt/QAxObject>

//#include <src/office/[...].hpp"

namespace depistage { namespace office { namespace test {

class WordTests : public QObject
{
   Q_OBJECT
public:
   WordTests();

private:
   std::string m_lastErrorMessage;

   void connectException( const QAxObject * axObject );
   void checkLastErrorMessage();

   void testOpenDocumentBody( const std::string & path, const std::string & tempPath );

private slots:
   void init();
   void testLaunchWord();
   void testOpenDocument();
   void testReplaceInDocument();

   void catchException(int code, const QString &source, const QString &desc, const QString &help);
};

} } }

#endif // SQLTRANSACTIONTESTS_H
