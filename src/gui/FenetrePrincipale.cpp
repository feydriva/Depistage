
#include "FenetrePrincipale.hpp"

#include <QAxObject>
#include <QAxWidget>
#include <QDebug>

#include <iostream>

namespace depistage { namespace gui {

FenetrePrincipale::FenetrePrincipale( QWidget * parent )
	: QMainWindow( parent )
{

QAxObject *word, *doc;
word = new QAxObject("Word.Application", this);
word->setProperty("DisplayAlerts", false);
word->setProperty("Visible", true);
doc = word->querySubObject("Documents");
const std::string chemin =  "d:\\test__.doc";
std::cout << "chemin: " << chemin << std::endl;
doc->dynamicCall("Open(const QString&)", chemin.c_str());
QAxObject *act = word->querySubObject("ActiveDocument");
QAxObject *next = act->querySubObject("Content");
//next->dynamicCall("Select()");
//next->dynamicCall("Copy()");
QAxObject * find = next->querySubObject("find");
if ( !find )
{
   std::cerr << "find content." << std::endl;
   exit( -1 );
}
find->dynamicCall("ClearFormatting()");
    QList<QVariant> params;
    params.operator << (QVariant("HMCZNIX"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant(true));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("toto"));
    params.operator << (QVariant("2")); //valeur de wdRepalceAll
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
    params.operator << (QVariant("0"));
 
    find->dynamicCall("Execute(const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&, const QVariant&)", params);
    
act->dynamicCall("Close(void)");
   
   // QAxWidget* word = new QAxWidget("Word.Application", NULL);
   // word->setProperty("Visible", true);
   // QAxObject *doc = word->querySubObject("Documents");
   // doc->dynamicCall("Open(QVariant)", "d:\\test.doc");
   
   // QAxObject * activeDocument = word->querySubObject("ActiveDocument");
   // if (doc)
   // {
      
      // QAxObject * content = activeDocument->querySubObject("Content");
      // if ( content )
      // {
         // //content->querySubObject("Content");

         // QAxObject * find = content->querySubObject("Find");
         // if ( !find )
         // {
            // std::cerr << "find content." << std::endl;
            // exit( -1 );
         // }
         
   // connect(find, SIGNAL(exception(int, const QString&, const QString&, const QString&)),
           // this, SLOT(catchException(int, const QString&, const QString&, const QString&)));

          // QList<QVariant> list;
          // list.push_back("chat");
          // list.push_back(true);
          // list.push_back(true);
          // list.push_back(false);
          // list.push_back(false);
          // list.push_back(false);
          // list.push_back(true);
          // list.push_back(QVariant());
          // list.push_back(QVariant());
          // list.push_back("ours");
          // list.push_back(QVariant());
          // list.push_back(QVariant("all"));
          // list.push_back(false);
          // list.push_back(false);
          // list.push_back(false);
    // find->dynamicCall("Execute(QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant&, QVariant& ,QVariant& ,QVariant& , QVariant&, QVariant&, QVariant&, QVariant&)", list);

      // }
      // else
      // {
         // std::cerr << "Erreur content." << std::endl;
      // }

      // // QAxObject * storyRanges = activeDocument->querySubObject("StoryRanges");
      // // if (storyRanges)
      // // {
         // // std::cout << "count : " << storyRanges->property("Count").toInt() << std::endl;
         // // QAxObject * item = storyRanges->property("Item").value<QAxObject *>();
         // // if ( item )
         // // {
         // // }
         // // else
         // // {
            // // std::cerr << "Erreur item." << std::endl;
         // // }
         // // for ( int i = 0; i < storyRanges->property("Count").toInt(); ++i )
         // // {
            // // QAxObject * storyRange;
            // // /*QAxObject * storyRange = */storyRanges->property( "Item" );
            // // //storyRange = activeDocument->querySubObject( "StoryRanges(int)", WdHeaderFooterIndex.wdMainTextStory );
            // // //WdStoryType.wdTextFrameStory
            // // //storyRange = storyRanges->property( "Item(0)" );
            // // if ( storyRange )
            // // {
            // // }
            // // else
            // // {
               // // std::cerr << "Erreur storyRange n°" << i << "." << std::endl;
            // // }
         // // }/*
         // // for ( int i = 0; i < 100; ++i )
         // // {
            // // QAxObject * storyRange;
            // // storyRange = activeDocument->querySubObject( "StoryRanges(int)", i );
            // // if ( storyRange )
            // // {
               // // std::cout << "Okkkkkkkkkkkkk n°" << i << "." << std::endl;
            // // }
            // // else
            // // {
               // // std::cerr << "Erreur storyRange n°" << i << "." << std::endl;
            // // }
         // // }*/
      // // }
      // // else
      // // {
         // // std::cerr << "Erreur storyRanges." << std::endl;
      // // }
   // }
   // else
   // {
      // std::cerr << "Erreur activeDocument." << std::endl;
   // }
/*
   QAxObject* content = doc->querySubObject("Content");
   if ( content )
   {
      content->dynamicCall("InsertAfter (Text:=QVariant&)", "hello");
      content = doc->querySubObject("Content");
      QAxObject* find = content->querySubObject("chat");
      find->dynamicCall("InsertAfter (Text:=QVariant&)", "te");
   }
   else
   {
      std::cerr << "Erreur get content." << std::endl;
   }
*/
    //   mWordWidget->setVisible(true);
    //mWordWidget->dynamicCall( "SetVisible(bool)", true);

}



void FenetrePrincipale::catchException(int code, const QString &source, const QString &desc, const QString &help) {
    qDebug() << "\n Exception Catched! \n Code: " << code << "\n Source: " << source << " \n Description:" << desc << "\n Help: " << help;
}

} }
