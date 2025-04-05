//
//  offsetdump.h
//  Meridian
//
//  Created by Ben Sparkes on 30/03/2018.
//  Copyright © 2018 Ben Sparkes. All rights reserved.
//

#ifndef offsetdump_h
#define offsetdump_h

#include "offsetfinder.h"

void dumpOffsetsToFile(offsets_t *offsets, uint64_t kernel_base, uint64_t kernel_slide, uint64_t kernprocaddr);

#endif /* offsetdump_h */
