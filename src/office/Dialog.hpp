
#ifndef DEPISTAGE_TEST_DIALOG_HPP
#define DEPISTAGE_TEST_DIALOG_HPP

#include <ActiveQt/QAxObject>

#include <QtCore/QObject>

#include <memory>

namespace depistage { namespace office {

class Dialog
{
   public:
      Dialog( QAxObject * dialog, QObject * parent = nullptr );

      void show();

      enum Enum
      {
         parametreImpression = 88 // wdDialogFilePrint
      };

   private:
      std::unique_ptr< QAxObject > m_dialog;

      QObject * m_parent;
};

} }

#endif
