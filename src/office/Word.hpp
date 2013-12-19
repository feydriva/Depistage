
#ifndef DEPISTAGE_TEST_WORD_HPP
#define DEPISTAGE_TEST_WORD_HPP

#include "WordDocument.hpp"

#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class Word
{
   public:
      Word( QObject * parent = NULL );
      ~Word();

      WordDocument open( const std::string & path );

      bool isLaunched() const;

   private:
      std::unique_ptr< QAxObject > m_word;
      std::unique_ptr< QAxObject > m_documents;

      QObject * m_parent;

      void initializeDocuments();
};

} }

#endif
