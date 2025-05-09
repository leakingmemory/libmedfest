//
// Created by jeo on 12/8/22.
//

#include <FestObjectStream.h>
#include <XMLParser.h>
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
#include "Fest/KatVilkar.h"
#include "Fest/XmlVilkar.h"
#include "Fest/KatVarselSlv.h"
#include "Fest/XmlVarselSlv.h"
#include "Fest/XmlReferanseelement.h"
#include "Fest/KatKodeverk.h"
#include "Fest/XmlInfo.h"
#include "Fest/XmlElement.h"
#include "Fest/KatByttegruppe.h"
#include "Fest/XmlByttegruppe.h"
#include "Fest/KatLegemiddeldose.h"
#include "Fest/XmlLegemiddeldose.h"
#include "Fest/KatInteraksjon.h"
#include "Fest/XmlInteraksjon.h"
#include "Fest/XmlReferanse.h"
#include "Fest/XmlSubstansgruppe.h"
#include "Fest/XmlSubstans.h"
#include "Fest/XmlInteraksjonIkkeVurdert.h"
#include "Fest/KatStrDosering.h"
#include "Fest/XmlLegemiddelforbruk.h"
#include "Fest/XmlDosering.h"
#include "Fest/XmlDoseFastTidspunkt.h"
#include "Fest/XmlFastDose.h"
#include <iostream>

void FestObjectStream::progress(size_t count, size_t total) {
    auto pct = (count * 100) / total;
    std::cout << "\rDecoding XML data " << pct << "%..." << std::flush;
}

void FestObjectStream::progress_finished() {
    std::cout << "\n";
}

std::shared_ptr<Fest> FestObjectStream::read() {
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
    parser.AddHandler("TilDato", std::make_shared<XmlTilDatoHandler>());
    parser.AddHandler("KatVilkar", std::make_shared<KatVilkarHandler>());
    parser.AddHandler("OppfVilkar", std::make_shared<OppfVilkarHandler>());
    parser.AddHandler("Vilkar", std::make_shared<XmlVilkarHandler>());
    parser.AddHandler("VilkarNr", std::make_shared<XmlVilkarNrHandler>());
    parser.AddHandler("Gruppe", std::make_shared<XmlGruppeHandler>());
    parser.AddHandler("GjelderFor", std::make_shared<XmlGjelderForHandler>());
    parser.AddHandler("Tekst", std::make_shared<XmlTekstHandler>());
    parser.AddHandler("StrukturertVilkar", std::make_shared<XmlStrukturertVilkarHandler>());
    parser.AddHandler("VerdiKodet", std::make_shared<XmlVerdiKodetHandler>());
    parser.AddHandler("VerdiTekst", std::make_shared<XmlVerdiTekstHandler>());
    parser.AddHandler("KatVarselSlv", std::make_shared<KatVarselSlvHandler>());
    parser.AddHandler("OppfVarselSlv", std::make_shared<XmlOppfVarselSlvHandler>());
    parser.AddHandler("VarselSlv", std::make_shared<XmlVarselSlvHandler>());
    parser.AddHandler("Overskrift", std::make_shared<XmlOverskriftHandler>());
    parser.AddHandler("Varseltekst", std::make_shared<XmlVarseltekstHandler>());
    parser.AddHandler("Visningsregel", std::make_shared<XmlVisningsregelHandler>());
    parser.AddHandler("Beskrivelse", std::make_shared<XmlBeskrivelseHandler>());
    parser.AddHandler("Referanseelement", std::make_shared<XmlReferanseelementHandler>());
    parser.AddHandler("Klasse", std::make_shared<XmlKlasseHandler>());
    parser.AddHandler("RefElement", std::make_shared<XmlRefElementHandler>());
    parser.AddHandler("KatKodeverk", std::make_shared<KatKodeverkHandler>());
    parser.AddHandler("OppfKodeverk", std::make_shared<OppfKodeverkHandler>());
    parser.AddHandler("Info", std::make_shared<XmlInfoHandler>());
    parser.AddHandler("Betegnelse", std::make_shared<XmlBetegnelseHandler>());
    parser.AddHandler("Kortnavn", std::make_shared<XmlKortnavnHandler>());
    parser.AddHandler("AnsvarligUtgiver", std::make_shared<XmlAnsvarligUtgiverHandler>());
    parser.AddHandler("Element", std::make_shared<XmlElementHandler>());
    parser.AddHandler("Kode", std::make_shared<XmlKodeHandler>());
    parser.AddHandler("Term", std::make_shared<XmlTermHandler>());
    parser.AddHandler("Sprak", std::make_shared<XmlSprakHandler>());
    parser.AddHandler("BeskrivelseTerm", std::make_shared<XmlBeskrivelseTermHandler>());
    parser.AddHandler("KatByttegruppe", std::make_shared<KatByttegruppeHandler>());
    parser.AddHandler("OppfByttegruppe", std::make_shared<XmlOppfByttegruppeHandler>());
    parser.AddHandler("Byttegruppe", std::make_shared<XmlByttegruppeHandler>());
    parser.AddHandler("MerknadTilByttbarhet", std::make_shared<XmlMerknadTilByttbarhetHandler>());
    parser.AddHandler("BeskrivelseByttbarhet", std::make_shared<XmlBeskrivelseByttbarhetHandler>());
    parser.AddHandler("KatLegemiddeldose", std::make_shared<KatLegemiddeldoseHandler>());
    parser.AddHandler("OppfLegemiddeldose", std::make_shared<XmlOppfLegemiddeldoseHandler>());
    parser.AddHandler("Legemiddeldose", std::make_shared<XmlLegemiddeldoseHandler>());
    parser.AddHandler("LmrLopenr", std::make_shared<XmlLmrLopenrHandler>());
    parser.AddHandler("KatInteraksjon", std::make_shared<KatInteraksjonHandler>());
    parser.AddHandler("OppfInteraksjon", std::make_shared<XmlOppfInteraksjonHandler>());
    parser.AddHandler("Interaksjon", std::make_shared<XmlInteraksjonHandler>());
    parser.AddHandler("Relevans", std::make_shared<XmlRelevansHandler>());
    parser.AddHandler("KliniskKonsekvens", std::make_shared<XmlKliniskKonsekvensHandler>());
    parser.AddHandler("Interaksjonsmekanisme", std::make_shared<XmlInteraksjonsmekanismeHandler>());
    parser.AddHandler("Kildegrunnlag", std::make_shared<XmlKildegrunnlagHandler>());
    parser.AddHandler("Handtering", std::make_shared<XmlHandteringHandler>());
    parser.AddHandler("Referanse", std::make_shared<XmlReferanseHandler>());
    parser.AddHandler("Kilde", std::make_shared<XmlKildeHandler>());
    parser.AddHandler("Substansgruppe", std::make_shared<XmlSubstansgruppeHandler>());
    parser.AddHandler("Substans", std::make_shared<XmlSubstansHandler>());
    parser.AddHandler("Situasjonskriterium", std::make_shared<XmlSituasjonskriteriumHandler>());
    parser.AddHandler("InteraksjonIkkeVurdert", std::make_shared<XmlInteraksjonIkkeVurdertHandler>());
    parser.AddHandler("KatStrDosering", std::make_shared<KatStrDoseringHandler>());
    parser.AddHandler("OppfStrDosering", std::make_shared<XmlOppfStrDoseringHandler>());
    parser.AddHandler("Legemiddelforbruk", std::make_shared<XmlLegemiddelforbrukHandler>());
    parser.AddHandler("Lopenr", std::make_shared<XmlLopenrHandler>());
    parser.AddHandler("Periode", std::make_shared<XmlPeriodeHandler>());
    parser.AddHandler("Iterasjoner", std::make_shared<XmlIterasjonerHandler>());
    parser.AddHandler("Dosering", std::make_shared<XmlDoseringHandler>());
    parser.AddHandler("DoseFastTidspunkt", std::make_shared<XmlDoseFastTidspunktHandler>());
    parser.AddHandler("Intervall", std::make_shared<XmlIntervallHandler>());
    parser.AddHandler("Tidsomrade", std::make_shared<XmlTidsomradeHandler>());
    parser.AddHandler("GisEksakt", std::make_shared<XmlGisEksaktHandler>());
    parser.AddHandler("FastDose", std::make_shared<XmlFastDoseHandler>());
    parser.AddHandler("DagerPa", std::make_shared<XmlDagerPaHandler>());
    parser.AddHandler("DagerAv", std::make_shared<XmlDagerAvHandler>());
    const auto totalSize = source->size();
    std::remove_const<decltype(totalSize)>::type countSize = 0;
    do {
        int num = source->read(&(buf[0]), sizeof(buf));
        if (num < 0) {
            std::cerr << "Read error, xml stream\n";
            return {};
        }
        if (num == 0) {
            break;
        }
        if (!parser.ParseBuffer(&(buf[0]), num, false)) {
            std::cerr << "XML Parse error\n";
            return {};
        }
        countSize += num;
        progress(countSize, totalSize);
    } while (true);
    progress_finished();
    parser.ParseBuffer(nullptr, 0, true);
    return parser.GetRoot<Fest>();
}