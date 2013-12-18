
#include "WordTests.hpp"

#include <ActiveQt/QAxWidget>
#include <ActiveQt/QAxObject>
#include <QtTest/QtTest>

#include <memory>

#include <QDesktopServices>
#include <QUrl>

#include <iostream>

namespace depistage { namespace office { namespace test {

WordTests::WordTests()
{
}

class WordDocument
{
   public:
      WordDocument( QAxObject * wordDocument );

      bool isOpen() const;

   private:
      std::unique_ptr< QAxObject > m_document;
};

WordDocument::WordDocument( QAxObject * document )
   : m_document( document )
{
}

bool WordDocument::isOpen() const
{
   return m_document.get() != nullptr;
}

class Word
{
   public:
      Word();
      ~Word();

      WordDocument open( const std::string & path );

      bool isLaunched() const;

   private:
      std::unique_ptr< QAxObject > m_word;
      std::unique_ptr< QAxObject > m_documents;

      void initializeDocuments();
};

Word::Word()
   : m_word( new QAxObject( "Word.Application", NULL ) )
{
   m_word->setProperty( "DisplayAlerts", false );
   m_word->setProperty( "Visible", true/*false*/ );
}

Word::~Word()
{
   //m_word->dynamicCall( "Quit(void)" );
}

void Word::initializeDocuments()
{
   if (!m_documents)
   {
      m_documents.reset( (QAxObject *) m_word->querySubObject( "Documents" ) );
   }
}

WordDocument Word::open( const std::string & path )
{
   initializeDocuments();
   m_documents->dynamicCall( "Open(const QString&)", path.c_str() );
   return WordDocument( (QAxObject *) m_word->querySubObject( "ActiveDocument" ) );
}

bool Word::isLaunched() const
{
   return m_word.get() != nullptr;
}

void WordTests::testLaunchWord()
{
   Word word;
   QVERIFY( word.isLaunched() );
}

void testOpenDocument2( const std::string & path, const std::string & tempPath )
{
   QFile::copy( path.c_str(), tempPath.c_str() );
   {
      Word word;
      WordDocument docTest = word.open( tempPath );
      QVERIFY( docTest.isOpen() );
   }
   QFile::remove( "tempPath" );
}

void WordTests::testOpenDocument()
{
   testOpenDocument2( ":/input/test.doc", "d:\\test_temp.doc" );
   testOpenDocument2( ":/input/test.docx", "d:\\test_temp.docx" );
}

} } }

QTEST_MAIN( depistage::office::test::WordTests )
