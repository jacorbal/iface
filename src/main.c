/**
 * @file main.c
 *
 * @brief Print local IP for a given net interface
 *
 * @author J. A. Corbal <jacorbal@gmail.com>
 * @date Creation date: Sat Mar  9 02:04:00 UTC 2019
 * @date Last update: Tue May 19 16:43:24 UTC 2026
 */

/* System includes */
#include <stdio.h>

/* Local includes */
#include <iface.h>
#include <show.h>


/* Main entry */
int main(int argc, char *const argv[])
{
    char *ip;

    if (argc < 2) {
        show_usage(stdout);
        show_version(stdout);
        return 0;
    }

    if (!iface_exists(argv[1])) {
        fprintf(stderr, "Interface '%s' does not exist\n", argv[1]);
        return 1;
    }

    ip = iface_ip(argv[1]);
    if (ip == NULL) {
        fprintf(stderr, "Cannot find IPv4 for '%s'\n", argv[1]);
        return 1;
    }

    fprintf(stdout, "%s\n", ip);

    return 0;

}
