//========================================================================
// parcv2-custom.S
//========================================================================

#include "parc-macros.h"

        TEST_PARC_BEGIN



        // Mixed tests

        TEST_RR_OP( mul, 0x0deadbeef, 0x10000000, 0xe0000000 )
        TEST_RR_OP( div, 2000, 5, 4 )
        TEST_RR_OP( rem, 2006, 5, 1 )


        //--------------------------------------------------------------------
        // Bypassing tests
        //--------------------------------------------------------------------

        TEST_RR_DEST_BYP( 0, mul, 13, 11, 143 )
        TEST_RR_DEST_BYP( 1, mul, 14, 11, 154 )

        TEST_RR_SRC01_BYP( 0, 0, mul, 13, 11, 143 )
        TEST_RR_SRC01_BYP( 0, 1, mul, 14, 11, 154 )

        TEST_RR_SRC10_BYP( 2, 1, div, 3024, 11, 274 )
        TEST_RR_SRC10_BYP( 2, 1, rem, 3024, 11, 10 )

        

        TEST_PARC_END

