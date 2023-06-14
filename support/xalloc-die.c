/* xalloc_die -- fatal error message when malloc fails.  */

#include <config.h>
#include "xalloc.h"
#include "verify.h"
#include <awk.h>

void
xalloc_die (void)
{
  r_fatal (_("xalloc: malloc failed: %s"), strerror (errno));
  assume (false);
}
