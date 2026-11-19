#ifndef PRINT_HEADER
#define PRINT_HEADER

/* clang-format off */
#include <stdio.h>
#include <string.h>
#include "simset/SystemDependent.h"
#include "simset/LbTypes.h"
#include "simset/LbError.h"
#include "simset/LbDebug.h"
#include "simset/LbEnvironment.h"
#include "simset/LbFile.h"
#include "simset/LbMemory.h"
#include "simset/LbInterface.h"
#include "simset/LbParamFile.h"
#include "simset/LbHeader.h"
#include "simset/Photon.h"
#include "simset/PhgParams.h"
#include "simset/ColTypes.h"
#include "simset/ColParams.h"
#include "simset/DetTypes.h"
#include "simset/DetParams.h"
#include "simset/CylPos.h"
#include "simset/PhgMath.h"
#include "simset/PhoHFile.h"
#include "simset/ProdTbl.h"
#include "simset/PhoTrk.h"
#include "simset/SubObj.h"
#include "simset/EmisList.h"
#include "simset/Collimator.h"
#include "simset/Detector.h"
#include "simset/PhgHdr.h"
#include "simset/phg.h"
#include "simset/PhgBin.h"
/* clang-format on */

#ifdef __cplusplus
extern "C"
{
#endif

  Boolean PrintHeader (int argc, char *argv[]);

#ifdef __cplusplus
}
#endif

#endif
