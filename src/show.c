/**
 * @file show.c
 *
 * @brief Routines for showing information on screen implementation
 */

/* System includes */
#include <stdio.h>

/* Local includes */
#include <show.h>


/* Print usage information */
void show_usage(FILE *fp)
{
    fprintf(fp, "Usage: %s <interface>\n", PROG_NAME);
}


/* Print version information */
void show_version(FILE *fp)
{
    fprintf(fp, "Version: %s (%s)\n", PROG_VERSION, PROG_BUILD);
}

