//
// Created by jeo on 12/8/22.
//

#include "FestObjectStream.h"
#include "XMLParser.h"
#include "Fest/Fest.h"
#include "Fest/FestIdObject.h"
#include "Fest/KatLegemiddelMerkevare.h"
#include "Fest/TidspunktObject.h"
#include "Fest/StatusObject.h"
#include "Fest/XmlLegemiddelMerkevare.h"
#include "Fest/XmlLegemiddel.h"
#include "Fest/XmlPreparattypeObject.h"
#include "Fest/XmlAdministreringLegemiddel.h"
#include "Fest/XmlSortertVirkestoffMedStyrke.h"
#include "Fest/XmlSortering.h"
#include "Fest/XmlRefVirkestoffMedStyrke.h"
#include "Fest/XmlProduktInfo.h"
#include "Fest/XmlReseptgyldighet.h"
#include "Fest/XmlVarighet.h"
#include "Fest/XmlPreparatomtaleavsnitt.h"
#include "Fest/XmlRefVirkestoff.h"
#include "Fest/XmlSortertVirkestoffUtenStyrke.h"
#include "Fest/XmlKjonn.h"
#include "Fest/XmlLegemiddelpakning.h"
#include "Fest/XmlPakningsinfo.h"
#include "Fest/XmlRefLegemiddelMerkevare.h"
#include "Fest/XmlMarkedsforingsinfo.h"
#include "Fest/XmlPrisVare.h"
#include "Fest/XmlPakningskomponent.h"
#include "Fest/XmlPakningstype.h"
#include "Fest/XmlRefusjon.h"
#include "Fest/XmlPakningByttegruppe.h"
#include "Fest/KatVirkestoff.h"
#include "Fest/XmlVirkestoff.h"
#include "Fest/XmlVirkestoffMedStyrke.h"
#include "Fest/KatLegemiddelVirkestoff.h"
#include "Fest/XmlLegemiddelVirkestoff.h"
#include "Fest/XmlRefPakning.h"
#include "Fest/KatHandelsvare.h"
#include "Fest/XmlHandelsvare.h"
#include "Fest/XmlProduktInfoVare.h"
#include "Fest/XmlLeverandor.h"
#include "Fest/KatRefusjon.h"
#include "Fest/XmlRefusjonshjemmel.h"
#include "Fest/XmlRefusjonsgruppe.h"
#include "Fest/XmlRefusjonskode.h"
#include "Fest/XmlRefusjonsvilkar.h"
#include "Fest/XmlRefVilkar.h"
#include <iostream>

void FestObjectStream::read() {
    XMLParser parser{};
    parser.AddHandler("FEST", std::make_shared<FestHandler>());
    parser.AddHandler("HentetDato", std::make_shared<HentetDatoHandler>());
    parser.AddHandler("Id", std::make_shared<FestIdHandler>());
    parser.AddHandler("KatLegemiddelMerkevare", std::make_shared<KatLegemiddelMerkevareHandler>());
    parser.AddHandler("OppfLegemiddelMerkevare", std::make_shared<OppfLegemiddelMerkevareHandler>());
    parser.AddHandler("Tidspunkt", std::make_shared<XmlTidspunktObjectHandler>());
    parser.AddHandler("Status", std::make_shared<XmlStatusObjectHandler>());
    parser.AddHandler("LegemiddelMerkevare", std::make_shared<XmlLegemiddelMerkevareHandler>());
    parser.AddHandler("Atc", std::make_shared<XmlAtcHandler>());
    parser.AddHandler("NavnFormStyrke", std::make_shared<XmlNavnFormStyrkeHandler>());
    parser.AddHandler("Reseptgruppe", std::make_shared<XmlReseptgruppeHandler>());
    parser.AddHandler("LegemiddelformKort", std::make_shared<XmlLegemiddelformKortHandler>());
    parser.AddHandler("RefVilkar", std::make_shared<XmlRefVilkarHandler>());
    parser.AddHandler("Preparattype", std::make_shared<XmlPreparattypeObjectHandler>());
    parser.AddHandler("TypeSoknadSlv", std::make_shared<XmlTypeSoknadSlvHandler>());
    parser.AddHandler("AdministreringLegemiddel", std::make_shared<XmlAdministreringLegemiddelHandler>());
    parser.AddHandler("Administrasjonsvei", std::make_shared<XmlAdministrasjonsveiHandler>());
    parser.AddHandler("EnhetDosering", std::make_shared<XmlEnhetDoseringHandler>());
    parser.AddHandler("Varenavn", std::make_shared<XmlVarenavnHandler>());
    parser.AddHandler("LegemiddelformLang", std::make_shared<XmlLegemiddelformLangHandler>());
    parser.AddHandler("SortertVirkestoffMedStyrke", std::make_shared<XmlSortertVirkestoffMedStyrkeHandler>());
    parser.AddHandler("Sortering", std::make_shared<XmlSorteringHandler>());
    parser.AddHandler("RefVirkestoffMedStyrke", std::make_shared<XmlRefVirkestoffMedStyrkeHandler>());
    parser.AddHandler("ProduktInfo", std::make_shared<XmlProduktInfoHandler>());
    parser.AddHandler("Produsent", std::make_shared<XmlProdusentHandler>());
    parser.AddHandler("Reseptgyldighet", std::make_shared<XmlReseptgyldighetHandler>());
    parser.AddHandler("Varighet", std::make_shared<XmlVarighetHandler>());
    parser.AddHandler("BruksomradeEtikett", std::make_shared<XmlBruksomradeEtikettHandler>());
    parser.AddHandler("KanKnuses", std::make_shared<XmlKanKnusesHandler>());
    parser.AddHandler("ForhandsregelInntak", std::make_shared<XmlForhandsregelInntakHandler>());
    parser.AddHandler("Varseltrekant", std::make_shared<XmlVarseltrekantHandler>());
    parser.AddHandler("Referanseprodukt", std::make_shared<XmlReferanseproduktHandler>());
    parser.AddHandler("Preparatomtaleavsnitt", std::make_shared<XmlPreparatomtaleavsnittHandler>());
    parser.AddHandler("Avsnittoverskrift", std::make_shared<XmlAvsnittoverskriftHandler>());
    parser.AddHandler("Lenke", std::make_shared<XmlLenkeHandler>());
    parser.AddHandler("Www", std::make_shared<XmlWwwHandler>());
    parser.AddHandler("Kortdose", std::make_shared<XmlKortdoseHandler>());
    parser.AddHandler("Opioidsoknad", std::make_shared<XmlOpioidsoknadHandler>());
    parser.AddHandler("Deling", std::make_shared<XmlDelingHandler>());
    parser.AddHandler("SvartTrekant", std::make_shared<XmlSvartTrekantHandler>());
    parser.AddHandler("Smak", std::make_shared<XmlSmakHandler>());
    parser.AddHandler("RefVirkestoff", std::make_shared<XmlRefVirkestoffHandler>());
    parser.AddHandler("SortertVirkestoffUtenStyrke", std::make_shared<XmlSortertVirkestoffUtenStyrkeHandler>());
    parser.AddHandler("KanApnes", std::make_shared<XmlKanApnesHandler>());
    parser.AddHandler("Kjonn", std::make_shared<XmlKjonnHandler>());
    parser.AddHandler("Bolus", std::make_shared<XmlBolusHandler>());
    parser.AddHandler("Vaksinestandard", std::make_shared<XmlVaksinestandardHandler>());
    parser.AddHandler("InjeksjonshastighetBolus", std::make_shared<XmlInjeksjonshastighetBolusHandler>());
    parser.AddHandler("Blandingsveske", std::make_shared<XmlBlandingsveskeHandler>());
    parser.AddHandler("KatLegemiddelpakning", std::make_shared<KatLegemiddelpakningHandler>());
    parser.AddHandler("OppfLegemiddelpakning", std::make_shared<OppfLegemiddelpakningHandler>());
    parser.AddHandler("Legemiddelpakning", std::make_shared<XmlLegemiddelpakningHandler>());
    parser.AddHandler("Varenr", std::make_shared<XmlVarenrHandler>());
    parser.AddHandler("Oppbevaring", std::make_shared<XmlOppbevaringHandler>());
    parser.AddHandler("Pakningsinfo", std::make_shared<XmlPakningsinfoHandler>());
    parser.AddHandler("RefLegemiddelMerkevare", std::make_shared<XmlRefLegemiddelMerkevareHandler>());
    parser.AddHandler("Pakningsstr", std::make_shared<XmlPakningsstrHandler>());
    parser.AddHandler("EnhetPakning", std::make_shared<XmlEnhetPakningHandler>());
    parser.AddHandler("Pakningstype", std::make_shared<XmlPakningstypeHandler>());
    parser.AddHandler("Mengde", std::make_shared<XmlMengdeHandler>());
    parser.AddHandler("DDD", std::make_shared<XmlDDDHandler>());
    parser.AddHandler("Statistikkfaktor", std::make_shared<XmlStatistikkfaktorHandler>());
    parser.AddHandler("Markedsforingsinfo", std::make_shared<XmlMarkedsforingsinfoHandler>());
    parser.AddHandler("Markedsforingsdato", std::make_shared<XmlMarkedsforingsdatoHandler>());
    parser.AddHandler("Ean", std::make_shared<XmlEanHandler>());
    parser.AddHandler("Antall", std::make_shared<XmlAntallHandler>());
    parser.AddHandler("PrisVare", std::make_shared<XmlPrisVareHandler>());
    parser.AddHandler("Type", std::make_shared<XmlTypeHandler>());
    parser.AddHandler("Pris", std::make_shared<XmlPrisHandler>());
    parser.AddHandler("GyldigFraDato", std::make_shared<XmlGyldigFraDatoHandler>());
    parser.AddHandler("Pakningskomponent", std::make_shared<XmlPakningskomponentHandler>());
    parser.AddHandler("Refusjon", std::make_shared<XmlRefusjonHandler>());
    parser.AddHandler("RefRefusjonsgruppe", std::make_shared<XmlRefRefusjonsgruppeHandler>());
    parser.AddHandler("PakningByttegruppe", std::make_shared<XmlPakningByttegruppeHandler>());
    parser.AddHandler("RefByttegruppe", std::make_shared<XmlRefByttegruppeHandler>());
    parser.AddHandler("VarenrUtgaende", std::make_shared<XmlVarenrUtgaendeHandler>());
    parser.AddHandler("GyldigTilDato", std::make_shared<XmlGyldigTilDatoHandler>());
    parser.AddHandler("IkkeKonservering", std::make_shared<XmlIkkeKonserveringHandler>());
    parser.AddHandler("MidlUtgattDato", std::make_shared<XmlMidlUtgattDatoHandler>());
    parser.AddHandler("ForskrivesTilDato", std::make_shared<XmlForskrivesTilDatoHandler>());
    parser.AddHandler("UtleveresTilDato", std::make_shared<XmlUtleveresTilDatoHandler>());
    parser.AddHandler("AvregDato", std::make_shared<XmlAvregDatoHandler>());
    parser.AddHandler("Multippel", std::make_shared<XmlMultippelHandler>());
    parser.AddHandler("KatVirkestoff", std::make_shared<KatVirkestoffHandler>());
    parser.AddHandler("OppfVirkestoff", std::make_shared<XmlOppfVirkestoffHandler>());
    parser.AddHandler("Virkestoff", std::make_shared<XmlVirkestoffHandler>());
    parser.AddHandler("Navn", std::make_shared<XmlNavnHandler>());
    parser.AddHandler("NavnEngelsk", std::make_shared<XmlNavnEngelskHandler>());
    parser.AddHandler("VirkestoffMedStyrke", std::make_shared<XmlVirkestoffMedStyrkeHandler>());
    parser.AddHandler("Styrke", std::make_shared<XmlStyrkeHandler>());
    parser.AddHandler("Styrkeoperator", std::make_shared<XmlStyrkeoperatorHandler>());
    parser.AddHandler("StyrkeNevner", std::make_shared<XmlStyrkeNevnerHandler>());
    parser.AddHandler("AlternativStyrke", std::make_shared<XmlAlternativStyrkeHandler>());
    parser.AddHandler("AlternativStyrkeNevner", std::make_shared<XmlAlternativStyrkeNevnerHandler>());
    parser.AddHandler("AtcKombipreparat", std::make_shared<XmlAtcKombipreparatHandler>());
    parser.AddHandler("StyrkeOvreVerdi", std::make_shared<XmlStyrkeOvreVerdiHandler>());
    parser.AddHandler("KatLegemiddelVirkestoff", std::make_shared<KatLegemiddelVirkestoffHandler>());
    parser.AddHandler("OppfLegemiddelVirkestoff", std::make_shared<OppfLegemiddelVirkestoffHandler>());
    parser.AddHandler("LegemiddelVirkestoff", std::make_shared<XmlLegemiddelVirkestoffHandler>());
    parser.AddHandler("RefPakning", std::make_shared<XmlRefPakningHandler>());
    parser.AddHandler("ForskrivningsenhetResept", std::make_shared<XmlForskrivningsenhetReseptHandler>());
    parser.AddHandler("KatHandelsvare", std::make_shared<KatHandelsvareHandler>());
    parser.AddHandler("OppfHandelsvare", std::make_shared<OppfHandelsvareHandler>());
    parser.AddHandler("MedForbMatr", std::make_shared<XmlMedForbrMatrHandler>());
    parser.AddHandler("Nr", std::make_shared<XmlNrHandler>());
    parser.AddHandler("ProduktInfoVare", std::make_shared<XmlProduktInfoVareHandler>());
    parser.AddHandler("ProduktNr", std::make_shared<XmlProduktNrHandler>());
    parser.AddHandler("Volum", std::make_shared<XmlVolumHandler>());
    parser.AddHandler("EnhetStorrelse", std::make_shared<XmlEnhetStorrelseHandler>());
    parser.AddHandler("AntPerPakning", std::make_shared<XmlAntPerPakningHandler>());
    parser.AddHandler("TillattMerMakspris", std::make_shared<XmlTillattMerMaksprisHandler>());
    parser.AddHandler("Leverandor", std::make_shared<XmlLeverandorHandler>());
    parser.AddHandler("Adresse", std::make_shared<XmlAdresseHandler>());
    parser.AddHandler("Telefon", std::make_shared<XmlTelefonHandler>());
    parser.AddHandler("Naringsmiddel", std::make_shared<XmlNaringsmiddelHandler>());
    parser.AddHandler("Brystprotese", std::make_shared<XmlBrystproteseHandler>());
    parser.AddHandler("KatRefusjon", std::make_shared<KatRefusjonHandler>());
    parser.AddHandler("OppfRefusjon", std::make_shared<OppfRefusjonHandler>());
    parser.AddHandler("Refusjonshjemmel", std::make_shared<XmlRefusjonshjemmelHandler>());
    parser.AddHandler("KreverVarekobling", std::make_shared<XmlKreverVarekoblingHandler>());
    parser.AddHandler("KreverVedtak", std::make_shared<XmlKreverVedtakHandler>());
    parser.AddHandler("Refusjonsgruppe", std::make_shared<XmlRefusjonsgruppeHandler>());
    parser.AddHandler("GruppeNr", std::make_shared<XmlGruppeNrHandler>());
    parser.AddHandler("KreverRefusjonskode", std::make_shared<XmlKreverRefusjonskodeHandler>());
    parser.AddHandler("RefusjonsberettighetBruk", std::make_shared<XmlRefusjonsberettigetBrukHandler>());
    parser.AddHandler("Refusjonskode", std::make_shared<XmlRefusjonskodeHandler>());
    parser.AddHandler("Underterm", std::make_shared<XmlUndertermHandler>());
    parser.AddHandler("Refusjonsvilkar", std::make_shared<XmlRefusjonsvilkarHandler>());
    parser.AddHandler("FraDato", std::make_shared<XmlFraDatoHandler>());
    do {
        int num = source->read(&(buf[0]), sizeof(buf));
        if (num < 0) {
            std::cerr << "Read error, xml stream\n";
            return;
        }
        if (num == 0) {
            break;
        }
        std::cout << "Read " << num << " bytes\n";
        if (!parser.ParseBuffer(&(buf[0]), num, false)) {
            std::cerr << "XML Parse error\n";
            return;
        }
    } while (true);
    parser.ParseBuffer(nullptr, 0, true);
}