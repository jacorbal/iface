/*
 * Print local IP for a given net interface
 *
 * J. A. Corbal <jacorbal@gmail.com>
 * Last update: 2019-03-09 02:04 UTC
 */

/* System includes */
#include <stdio.h>

/* Local includes */
#include <iface.h>
#include <show.h>


/* Main entry */
int main(int argc, char *argv[])
{
    if (argc < 2) {
        show_usage(stderr);
        show_version(stderr);
        return 1;
    }

    printf("%s\n", iface_ip(argv[1]));

    return 0;
}

