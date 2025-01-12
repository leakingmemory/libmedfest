//
// Created by jan-e on 11.01.2025.
//

#ifndef PACKED_H
#define PACKED_H

#ifdef _MSC_VER
#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop))
#else
#define PACK( __Declaration__ ) __Declaration__ __attribute__((__packed__))
#endif

#endif //PACKED_H
