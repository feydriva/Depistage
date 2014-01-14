
#ifndef DEPISTAGE_TEST_EXCELTESTS_HPP
#define DEPISTAGE_TEST_EXCELTESTS_HPP

#include <QObject>
#include <ActiveQt/QAxObject>

//#include <src/office/[...].hpp"

namespace depistage { namespace office { namespace test {

class ExcelTests : public QObject
{
   Q_OBJECT
public:
   ExcelTests();

private:
   std::string m_lastErrorMessage;

   void connectException( const QAxObject * axObject );
   void checkLastErrorMessage();

   void testOpenDocumentBody( const std::string & path, const std::string & tempPath );

private slots:
   void init();
   void testLaunchExcel();
   void testOpenDocument();
   void testAjoutLigne();

   void catchException(int code, const QString &source, const QString &desc, const QString &help);
};

} } }

#endif // SQLTRANSACTIONTESTS_H
