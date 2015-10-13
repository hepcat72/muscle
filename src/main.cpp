//@@TODO reconcile /muscle with /muscle3.6

// Author: Robert C. Edgar
// Ported into R by Alex T. Kalinka (alex.t.kalinka@gmail.com)


#include "muscle.h"
#include <stdio.h>

#include "msa.h" // Added for R port.

#ifdef	WIN32
#include <windows.h>	// for SetPriorityClass()
#include <io.h>			// for isatty()
#else
#include <unistd.h>		// for isatty()
#endif


// For R.
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>



const char *MUSCLE_LONG_VERSION	= "MUSCLE v" SHORT_VERSION "."
#include "svnversion.h"
" by Robert C. Edgar";


int g_argc;
char **g_argv;



extern "C" {



void muscleR(int *argc, char **argv)
	{

	int nargs = *argc;

	MSA::m_uIdCount = 0; // To avoid carry-over variable assignments between runs in R.

#if	WIN32
// Multi-tasking does not work well in CPU-bound
// console apps running under Win32.
// Reducing the process priority allows GUI apps
// to run responsively in parallel.
	SetPriorityClass(GetCurrentProcess(), BELOW_NORMAL_PRIORITY_CLASS);
#endif
	g_argc = nargs;
	g_argv = argv;

	SetNewHandler();
	SetStartTime();

	default_params();
	blank_params();

	ProcessArgVect(nargs, argv);
	SetParams();

	SetLogFile();

	//extern void TestSubFams(const char *);
	//TestSubFams(g_pstrInFileName);
	//return 0;

	if (g_bVersion)
		{
		Rprintf("%s\n", MUSCLE_LONG_VERSION);
		return;
		}

	if (!g_bQuiet)
		Credits();

	if (MissingCommand() && isatty(0))
		{
		Usage();
		return;
		}

	if (g_bCatchExceptions)
		{
		try
			{
			Run();
			}
		catch (...)
			{
			OnException();
			return;
			}
		}
	else
		Run();

	return;
	}


// Register the native code in R.

R_CMethodDef cMethods[] = {
   {"muscleR", (DL_FUNC) &muscleR, 2},
   NULL
};



void R_init_muscle(DllInfo *info)
{
   R_registerRoutines(info, cMethods, NULL, NULL, NULL);
}


}















