#ifndef BIN_PHG_HDR
#define BIN_PHG_HDR

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
#include "simset/LbParamFile.h"
#include "simset/LbInterface.h"
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
#include "simset/PhgHdr.h"
#include "simset/ProdTbl.h"
#include "simset/PhoTrk.h"
#include "simset/SubObj.h"
#include "simset/EmisList.h"
#include "simset/Collimator.h"
#include "simset/Detector.h"
#include "simset/phg.h"
#include "simset/PhgBin.h"
/* clang-format on */

/* LOCAL CONSTANTS */
#define PHGRDHST_IsUsePHGHistory()                                            \
  LbFgIsSet (PhgOptions, LBFlag0) /* Will we use the PHG history file */
#define PHGRDHST_IsUseColHistory()                                            \
  LbFgIsSet (PhgOptions, LBFlag1) /* Will we use the Collimator history file  \
                                   */
#define PHGRDHST_IsUseDetHistory()                                            \
  LbFgIsSet (PhgOptions, LBFlag2) /* Will we use the Detector history file */

#define PHGRDHST_NumFlags 3 /* Number of flags defined */

/* LOCAL TYPES */
typedef enum
{
  Null,
  Decay,
  Photon
} EventTy;

#ifdef __cplusplus
extern "C"
{
#endif

  Boolean phgrdhstInitialize (int argc, char *argv[]);
  void phgrdhstTerminate (void);
  Boolean phgbin (int argc, char *argv[]);
  EventTy readEvent (FILE *historyFile, PHG_Decay *decayPtr,
                     PHG_DetectedPhoton *photonPtr);
  EventTy oldReadEvent (FILE *historyFile, PHG_Decay *decayPtr,
                        PHG_DetectedPhoton *photonPtr, Boolean isOldPhotons1,
                        Boolean isOldPhotons2);
  Boolean phgrdhstStandard (char *argv[]);
  Boolean phgrdhstCustom (char *argv[]);
  void phgbinProcessPhotons (PhoHFileHkTy *histHk, PHG_Decay *decayPtr,
                             PHG_TrackingPhoton *bluePhotons,
                             LbUsFourByte numBlues,
                             PHG_TrackingPhoton *pinkPhotons,
                             LbUsFourByte numPinks);

#ifdef __cplusplus
}
#endif

#endif
