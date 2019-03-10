/**
 * @file iface.c
 *
 * @brief IP address getter implementation
 */

/* System includes */
#include <arpa/inet.h>  /* inet_ntoa */
#include <net/if.h>     /* ifr, IFNAMSIZ */
#include <sys/ioctl.h>  /* ioctl, SIOCGIFADDR */
#include <string.h>     /* strncmp */
#include <unistd.h>     /* close */

/* Local includes */
#include <iface.h>


/* Return IP for a given net interface */
char *iface_ip(const char *iface)
{
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    /* Type of address to retrieve - IPv4 IP address */
    ifr.ifr_addr.sa_family = AF_INET;

    /* Copy the interface name in the ifreq structure */
    strncpy(ifr.ifr_name , iface , IFNAMSIZ - 1);

    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);

    return inet_ntoa(((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr);
}

