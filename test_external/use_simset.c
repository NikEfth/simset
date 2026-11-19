#include "simset/bin.phg.h"
#include "simset/print.header.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
        char* argv[3];
        argv[0] = "phgbin";
        argv[1] = "-d";
        argv[2] = "somefilename";

        int argc = 3;

        char* knownOptions = "pcd\0";
        char* optStr = knownOptions;

        char optArgs[PHGRDHST_NumFlags][LBEnMxArgLen];
        LbUsFourByte optArgFlags = LBFlag0;
        LbUsFourByte firstArg = 0;

        /* Get our options */
        if (!LbEnGetOptions( argc, argv, &knownOptions, &PhgOptions, optArgs, optArgFlags, &firstArg )) {
                fprintf( stderr, "Unable to get options." );
                exit( 1 );
        }

        return 0;
}