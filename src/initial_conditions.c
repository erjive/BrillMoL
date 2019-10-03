/* Setup for initial conditions*/
#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"



/*namespace iBrillwavelike {*/

void initial_conditions(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;

  int index;

  int i,j,k;
/*  if (verbose > 1)
  {
    CCTK_VInfo(CCTK_THORNSTRING,"Entering initial_conditions_Body");
  }
*/
  for (k=0; k<cctk_lsh[2]; k++)
    {
      for (j=0; j<cctk_lsh[1]; j++)
        {
          for (i=0; i<cctk_lsh[0]; i++)
            {
              index = CCTK_GFINDEX3D(cctkGH,i,j,k);
              phi[index] = 1.0;
              pi [index] = 0.0;
            }
        }
    }
/*  if (verbose > 1)
  {
    CCTK_VInfo(CCTK_THORNSTRING,"Leaving initial_conditions_Body");
  }
   return;
*/
}
/*}*/

