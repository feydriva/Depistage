
#include "ExcelTests.hpp"

#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
#include <office/ExcelOnglet.hpp>

#include <ActiveQt/QAxObject>
#include <QtTest/QtTest>

#include <QDesktopServices>
#include <QUrl>

#include <iostream>
#include <sstream>

namespace depistage { namespace office { namespace test {

ExcelTests::ExcelTests()
{
}

const std::string NoError = "No error";

void ExcelTests::init()
{
   m_lastErrorMessage = NoError;
}

void ExcelTests::checkLastErrorMessage()
{
   QCOMPARE( m_lastErrorMessage, NoError );
}

void ExcelTests::testLaunchExcel()
{
   Excel Excel( this );
   QVERIFY( Excel.isLaunched() );
   checkLastErrorMessage();
}

void ExcelTests::testOpenDocumentBody( const std::string & path, const std::string & tempPath )
{
   QFile::copy( path.c_str(), tempPath.c_str() );
   {
      Excel Excel( this );
      ExcelDocument xlsTest = Excel.open( tempPath );
      QVERIFY( xlsTest.isOpen() );
   }
   QFile::remove( tempPath.c_str() );
}

void ExcelTests::testOpenDocument()
{
   testOpenDocumentBody( ":/input/test.xls", "d:\\test_temp.xls" );
   testOpenDocumentBody( ":/input/test.xlsx", "d:\\test_temp.xlsx" );
   checkLastErrorMessage();
}

void ExcelTests::testAjoutLigne()
{
   const std::string tempPath = "d:\\test_temp2.xls";
   QFile::copy( ":/input/test.xls", tempPath.c_str() );
   {
      Excel Excel( this );
      ExcelDocument xlsTest = Excel.open( tempPath );
      QVERIFY( xlsTest.isOpen() );
      ExcelOnglet xlsOngletTest = xlsTest.recupererOnglet( 1 );
      QVERIFY( xlsOngletTest.isOpen() );

      std::vector< std::string > informations;
      informations.push_back( "Toto" );
      informations.push_back( "Tutu" );
      xlsOngletTest.ajouterLigne( informations );
   }
   //QFile::remove( tempPath.c_str() );
}

void ExcelTests::catchException( int code, const QString & source, const QString & desc, const QString & help )
{
   std::ostringstream oss;
   oss << "Exception Catched! \n";
   oss << "Code: " << code << "\n";
   oss << "Source: " << source.toStdString() << "\n";
   oss << "Description: " << desc.toStdString() << "\n";
   oss << "Help: " << help.toStdString() << "\n";
}

} } }

QTEST_MAIN( depistage::office::test::ExcelTests )
