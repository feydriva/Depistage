
#include "WordTests.hpp"

#include <office/Word.hpp>
#include <office/WordDocument.hpp>

#include <ActiveQt/QAxObject>
#include <QtTest/QtTest>

#include <QDesktopServices>
#include <QUrl>

#include <iostream>
#include <sstream>

namespace depistage { namespace office { namespace test {

WordTests::WordTests()
{
}

const std::string NoError = "No error";

void WordTests::init()
{
   m_lastErrorMessage = NoError;
}

void WordTests::checkLastErrorMessage()
{
   QCOMPARE( m_lastErrorMessage, NoError );
}

void WordTests::testLaunchWord()
{
   Word word( this );
   QVERIFY( word.isLaunched() );
   checkLastErrorMessage();
}

void WordTests::testOpenDocumentBody( const std::string & path, const std::string & tempPath )
{
   QFile::copy( path.c_str(), tempPath.c_str() );
   {
      Word word( this );
      WordDocument docTest = word.open( tempPath );
      QVERIFY( docTest.isOpen() );
   }
   QFile::remove( tempPath.c_str() );
}

void WordTests::testOpenDocument()
{
   testOpenDocumentBody( ":/input/test.doc", "d:\\test_temp.doc" );
   testOpenDocumentBody( ":/input/test.docx", "d:\\test_temp.docx" );
   checkLastErrorMessage();
}

void WordTests::testReplaceInDocument()
{
   const std::string tempPath = "d:\\test_temp2.doc";
   QFile::copy( ":/input/test.doc", tempPath.c_str() );
   {
      Word word( this );
      WordDocument docTest = word.open( tempPath );
      QVERIFY( docTest.isOpen() );
      docTest.replace( "toto", "tata" );
   }
   //QFile::remove( tempPath.c_str() );
}

void WordTests::catchException( int code, const QString & source, const QString & desc, const QString & help )
{
   std::ostringstream oss;
   oss << "Exception Catched! \n";
   oss << "Code: " << code << "\n";
   oss << "Source: " << source.toStdString() << "\n";
   oss << "Description: " << desc.toStdString() << "\n";
   oss << "Help: " << help.toStdString() << "\n";
}

} } }

QTEST_MAIN( depistage::office::test::WordTests )
