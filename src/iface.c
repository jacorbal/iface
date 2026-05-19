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


/* Test if the interface extist */
int iface_exists(const char *iface)
{
    if (iface == NULL || *iface == '\0')
        return 0;

    return if_nametoindex(iface) != 0;
}


/* Return IP for a given net interface */
char *iface_ip(const char *iface)
{
    static char ip[INET_ADDRSTRLEN];
    int fd;
    struct ifreq ifr;

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
        return NULL;

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_addr.sa_family = AF_INET;

    strncpy(ifr.ifr_name, iface, IFNAMSIZ - 1);
    ifr.ifr_name[IFNAMSIZ - 1] = '\0';

    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
        close(fd);
        return NULL;
    }

    close(fd);

    if (inet_ntop(AF_INET,
                  &((struct sockaddr_in *) &ifr.ifr_addr)->sin_addr,
                  ip, sizeof(ip)) == NULL) {
        return NULL;
    }

    return ip;
}
