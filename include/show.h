/**
 * @file show.h
 *
 * @brief Routines to show information on screen declaration
 */

#ifndef SHOW_H
#define SHOW_H

#define PROG_NAME "iface"
#define PROG_VERSION "1.0.2"
#define PROG_BUILD "2026-05-19"
#define PROG_COPYR "(c) 2019-2026"
#define PROG_AUTHOR "J. A. Corbal"
#define PROG_LICENSE "Unlicense license"


/* Public interface */
/**
 * @brief Print usage information
 *
 * @param fp FILE pointer where to print the usage information
 */
void show_usage(FILE *fp);

/**
 * @brief Print version information
 *
 * @param fp FILE pointer where to print the version information
 */
void show_version(FILE *fp);


#endif  /* SHOW_H */
