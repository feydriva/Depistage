
#include "ProgrammeEtiquettes.hpp"

#include <config/ConfigProgramme.hpp>

#include <gui/BasicElementGUI.hpp>
#include <gui/BoutonAction.hpp>
#include <gui/RemplacerCombo.hpp>
#include <gui/RemplacerDate.hpp>
#include <gui/RemplacerMot.hpp>

#include <office/Word.hpp>
#include <office/WordDocument.hpp>
#include <office/Dialog.hpp>
#include <office/Excel.hpp>
#include <office/ExcelDocument.hpp>
#include <office/ExcelOnglet.hpp>

#include <string>
#include <vector>

namespace depistage { namespace main {

namespace {

const QString chemin = "config.xml";
const QString labelCodePatient = "codePatient";
const QString labelSex = "sex";
const QString labelDateDeNaissance = "dateDeNaissance";
const QString labelWord = "word";
const QString labelExcel = "excel";

depistage::gui::MetaRemplacer * creerRemplacerMot( ProgrammeEtiquettes * programme,
                                                   config::ConfigProgramme & config,
                                                   const QString & labelAffichage,
                                                   const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   depistage::gui::RemplacerMot * remplacerMot =
      new depistage::gui::RemplacerMot( labelAffichage );
   QObject::connect( remplacerMot, SIGNAL( texteModifie( const QString & ) ),
                     programme,    SLOT( codePatientModifie( const QString & ) ) );
   return new depistage::gui::MetaRemplacer( remplacerMot, labelAffichage, motARemplacer );
}

depistage::gui::MetaRemplacer * creerRemplacerDate( config::ConfigProgramme & config,
                                                    const QString & labelAffichage,
                                                    const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   return new depistage::gui::MetaRemplacer(
      new depistage::gui::RemplacerDate( labelAffichage ),
      labelAffichage,
      motARemplacer );
}

depistage::gui::MetaRemplacer * creerRemplacerCombo( config::ConfigProgramme & config,
                                                     const QString & labelAffichage,
                                                     const std::vector< QString > & choix,
                                                     const QString & labelXML )
{
   QString motARemplacer = config.recupRemplacerMot( labelXML ).getMotARemplacer();
   return new depistage::gui::MetaRemplacer(
      new depistage::gui::RemplacerCombo( labelAffichage, choix ),
      labelAffichage,
      motARemplacer );
}

depistage::gui::SelectionFichier * creerSelectionFichier( config::ConfigProgramme & config,
   const QString & labelAffichage,
   const QString & labelFenetre,
   const QString & filtre,
   const QString & labelXML )
{
   QString chemin = config.recupSelectionFichier( labelXML ).getChemin();
   return new depistage::gui::SelectionFichier( labelAffichage, labelFenetre, filtre, chemin );
}

}

ProgrammeEtiquettes::ProgrammeEtiquettes()
{
   config::ConfigProgramme config = config::ConfigProgramme::chargerXML( chemin );

   m_codePatient = creerRemplacerMot( this, config, tr( "Code patient" ), labelCodePatient );
   m_elementsGUI.push_back( m_codePatient );

   m_nombreCodePatient = new gui::WidgetCompteur( tr( "Nombre de code patient : " ) );
   connect( m_nombreCodePatient, SIGNAL( nouvelleValeur( int ) ),
            this,                SLOT( nouveauNombreCodePatient( int ) ) );
   m_elementsGUI.push_back( new gui::BasicElementGUI( m_nombreCodePatient, nullptr ) );

   m_dernierCodePatient = new gui::WidgetTexteReadOnly( tr( "Dernier code patient : " ), "" );
   m_elementsGUI.push_back( new gui::BasicElementGUI( m_dernierCodePatient, nullptr ) );

   std::vector< QString > choix;
   choix.push_back( "M" );
   choix.push_back( "F" );
   m_sex = creerRemplacerCombo( config, tr( "Sexe" ), choix, labelSex );
   m_elementsGUI.push_back( m_sex );

   m_dateDeNaissance =
      creerRemplacerDate( config, tr( "Date de naissance" ), labelDateDeNaissance );
   m_dateDeNaissance->widgetBasic( )->setVisible( m_nombreCodePatient->getNombre() == 1 );
   m_elementsGUI.push_back( m_dateDeNaissance );

   gui::BoutonAction * boutonGeneration = new depistage::gui::BoutonAction( "Lancer génération" );
   m_elementsGUI.push_back( boutonGeneration );
   connect( boutonGeneration, SIGNAL( clique() ),
            this,             SLOT( lancerGeneration( ) ) );

   m_fichierWord = creerSelectionFichier( config,
                                          "Fichier word de rapport : ",
                                          "Ouvrir un document Word",
                                          "Word files  (*.doc *.docx)",
                                          labelWord );
   m_elementsGUI.push_back( m_fichierWord );
}

const std::vector< gui::ElementGUI * > & ProgrammeEtiquettes::getElementsGUI( ) const
{
   return m_elementsGUI;
}

namespace {

void initialiseA( QString & codePatient, int debut, int fin )
{
   for ( int i = debut; i <= fin; ++i )
   {
      codePatient[ i ] = QChar( 'A' );
   }
}

void initialiseToutA( QString & codePatient )
{
   initialiseA( codePatient, 0, codePatient.length() - 1 );
}

void incrementCodePatient( QString & codePatient, int placeLettre = 0 )
{
   if ( placeLettre == codePatient.length() )
   {
      initialiseToutA( codePatient );
      codePatient = "A" + codePatient;
      return;
   }

   int placeDeLaGauche = codePatient.length() - placeLettre - 1;
   int caractereValue = codePatient[ placeDeLaGauche ].unicode();
   if ( caractereValue >= QChar( 'A' ).unicode() &&
        caractereValue < QChar( 'Z' ).unicode() )
   {
      codePatient[ placeDeLaGauche ] = caractereValue + 1;
   }
   else
   {
      codePatient[ placeDeLaGauche ] = QChar( 'A' );
      incrementCodePatient( codePatient, placeLettre + 1 );
   }
}

QString genererDernierCodePatient( const QString & premierCodePatient, int nombreCodePatient )
{
   QString dernierCodePatient = premierCodePatient;
   for ( int i = 1; i < nombreCodePatient; ++i )
   {
      incrementCodePatient( dernierCodePatient );
   }
   return dernierCodePatient;
}

}

void ProgrammeEtiquettes::nouveauDernierCodePatient()
{
   if ( m_codePatient && m_nombreCodePatient && m_dernierCodePatient )
   {
      m_dernierCodePatient->setTexte(
         genererDernierCodePatient( m_codePatient->motParLequelRemplacer(),
                                    m_nombreCodePatient->getNombre() ) );
   }
}

void ProgrammeEtiquettes::nouveauNombreCodePatient( int nouveauNombre )
{
   if ( m_dateDeNaissance )
   {
      m_dateDeNaissance->widgetBasic()->setVisible( nouveauNombre == 1 );
   }
   nouveauDernierCodePatient();
}

void ProgrammeEtiquettes::codePatientModifie( const QString & )
{
   nouveauDernierCodePatient();
}

namespace {

void lancerGenerationWord( const QString & cheminWord,
                           const QString & codePatientAvant, const QString & codePatientApres,
                           const QString & sexAvant, const QString & sexApres,
                           const QString & dateAvant, const QString & dateApres,
                           int nombreCodePatient )
{
   QString dateVrai = nombreCodePatient == 1 ? dateApres : "";
   depistage::office::Word word;
   depistage::office::WordDocument document = word.open( cheminWord.toStdString() );
   document.replace( sexAvant.toStdString(), sexApres.toStdString() );
   document.replace( dateAvant.toStdString(), dateVrai.toStdString() );

   QString precCodePatient = codePatientAvant;
   QString prochainCodePatient = codePatientApres;
   for ( int i = 1; i <= nombreCodePatient; ++i )
   {
      document.replace( precCodePatient.toStdString(), prochainCodePatient.toStdString() );
      if ( i == 1 )
      {
         depistage::office::Dialog paramImpression =
            word.recupererDialog( depistage::office::Dialog::parametreImpression );
         paramImpression.show();
      }
      else
      {
         document.imprimer();
      }
      precCodePatient = prochainCodePatient;
      incrementCodePatient( prochainCodePatient );
   }
   word.quit( depistage::office::Word::ModeFermeture::SansSauvegarde );
}

}

void ProgrammeEtiquettes::lancerGeneration()
{

   if ( m_fichierWord->getChemin() != "" &&
        m_codePatient->motARemplacer( ) != "" &&
        m_sex->motARemplacer( ) != "" &&
        ( m_nombreCodePatient->getNombre() > 1 ||  m_dateDeNaissance->motARemplacer( ) != "" ) )
   {
      lancerGenerationWord(
         m_fichierWord->getChemin(),
         m_codePatient->motARemplacer(), m_codePatient->motParLequelRemplacer(),
         m_sex->motARemplacer(), m_sex->motParLequelRemplacer(),
         m_dateDeNaissance->motARemplacer(), m_dateDeNaissance->motParLequelRemplacer(),
         m_nombreCodePatient->getNombre() );
   }
}

void ProgrammeEtiquettes::sauverConfig( ) const
{
   config::ConfigProgramme config( "etiquettes" );
   config.miseAJourRemplacerConfig(
      config::RemplacerConfig( labelCodePatient, m_codePatient->motARemplacer( ) ) );
   config.miseAJourRemplacerConfig(
      config::RemplacerConfig( labelSex, m_sex->motARemplacer( ) ) );
   config.miseAJourRemplacerConfig(
      config::RemplacerConfig( labelDateDeNaissance, m_dateDeNaissance->motARemplacer( ) ) );
   config.miseAJourSelectionFichierConfig(
      config::SelectionFichierConfig( labelWord, m_fichierWord->getChemin( ) ) );
   config::ConfigProgramme::sauverXML( config, chemin );
}

} }
