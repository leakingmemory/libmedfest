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