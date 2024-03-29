/* Setup for initial conditions*/
#include "cctk.h"
#include "cctk_Arguments.h"
#include "cctk_Parameters.h"
//#include "CactusBase/IOUtil/src/ioutil_CheckpointRecovery.h"


/*namespace iBrillwavelike {*/

void initial_conditions(CCTK_ARGUMENTS)
{
  DECLARE_CCTK_ARGUMENTS;
  DECLARE_CCTK_PARAMETERS;

  int index;

  int i,j,k;
  int ierr;

/*  if (verbose > 1)
  {
    CCTK_VInfo(CCTK_THORNSTRING,"Entering initial_conditions_Body");
  }
*/

/* Read the initial data */

/*  if (read_idata == 1)
  {
  	//ierr = IOUtil_RecoverVarsFromDatafiles (cctkGH,ic_file,"IDBrillMoL::brillsource{ alias=’IDBrillMoL::phi’ }");
  	ierr = IOUtil_RecoverVarsFromDatafiles (cctkGH,ic_file,"IDBrillMoL::phi");

	  if (ierr<0)
	  {
	  	CCTK_WARN(0, "Brill wave initial data not found!");
	  }
	}
*/
  if (read_idata == 0 )
  {
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
  }
/*  if (verbose > 1)
  {
    CCTK_VInfo(CCTK_THORNSTRING,"Leaving initial_conditions_Body");
  }
   return;
*/
}
/*}*/

