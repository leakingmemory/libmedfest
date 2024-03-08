//
// Created by sigsegv on 2/14/23.
//

#include <Struct/Packed/PDoseFastTidspunkt.h>
#include <Struct/Decoded/DoseFastTidspunkt.h>

PDoseFastTidspunkt::PDoseFastTidspunkt(const DoseFastTidspunkt &doseFastTidspunkt, std::string &strblock,
                                       std::map<std::string, uint32_t> &cache) :
    mengde(doseFastTidspunkt.mengde, strblock, cache),
    intervall(doseFastTidspunkt.intervall, strblock, cache),
    tidsomrade(doseFastTidspunkt.tidsomrade, strblock, cache),
    dagerPa(doseFastTidspunkt.fastDose.dagerPa),
    dagerAv(doseFastTidspunkt.fastDose.dagerAv),
    gisEksakt(doseFastTidspunkt.gisEksakt)
{
}

bool PDoseFastTidspunkt::operator==(const PDoseFastTidspunkt &other) const {
    return mengde == other.mengde &&
           intervall == other.intervall &&
           tidsomrade == other.tidsomrade &&
           dagerPa == other.dagerPa &&
           dagerAv == other.dagerAv &&
           gisEksakt == other.gisEksakt;
}
