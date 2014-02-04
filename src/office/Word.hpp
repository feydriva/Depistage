
#ifndef DEPISTAGE_TEST_WORD_HPP
#define DEPISTAGE_TEST_WORD_HPP

#include "Dialog.hpp"
#include "WordDocument.hpp"

#include <QtCore/QObject>

#include <memory>
#include <string>

namespace depistage { namespace office {

class Word
{
   public:
     struct ModeFermeture
      {
         enum Enum
         {
            ProposerSauvegarde = -2,
            Sauvegarde = -1,
            SansSauvegarde = 0
         };
      };

      Word( QObject * parent = nullptr );

      void quit( ModeFermeture::Enum  modeFermetur = ModeFermeture::ProposerSauvegarde );

      WordDocument open( const std::string & path );
      Dialog recupererDialog( Dialog::Enum nom );

      bool isLaunched() const;

   private:
      std::unique_ptr< QAxObject > m_word;
      std::unique_ptr< QAxObject > m_documents;

      QObject * m_parent;

      void initializeDocuments();
};

} }

#endif
