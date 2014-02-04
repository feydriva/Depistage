
#ifndef DEPISTAGE_TEST_WORD_DOCUMENT_HPP
#define DEPISTAGE_TEST_WORD_DOCUMENT_HPP

#include <ActiveQt/QAxObject>
#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class WordDocument
{
public:
      WordDocument( QAxObject * wordDocument, QObject * parent = nullptr );

      void replace( const std::string & textToFind, const std::string & textToReplace );
      void imprimer() const;

      bool isOpen() const;

   private:
      std::unique_ptr< QAxObject > m_document;

      QObject * m_parent;
};

} }

#endif
