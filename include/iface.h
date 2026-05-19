/**
 * @file iface.h
 *
 * @brief IP address getter declaration
 */

#ifndef IFACE_H
#define IFACE_H


/**
 * @brief Test if the interface exist
 *
 * @param iface Net interface to check
 *
 * @return 0 if the interface does not exist, or otherwise
 */
int iface_exists(const char *iface);

/**
 * @brief Return the IP address given a net interface name
 *
 * @param iface Net interface
 *
 * @return IP address
 */
char *iface_ip(const char *iface);


#endif  /* IFACE_H */
