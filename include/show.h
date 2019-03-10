/**
 * @file show.h
 *
 * @brief Routines for showing information on screen declaration
 */

#ifndef SHOW_H
#define SHOW_H

#define PROG_NAME "iface"
#define PROG_VERSION "1.0.1"
#define PROG_BUILD   "2019-03-09"


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

