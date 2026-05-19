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
 * @return 1 if the interface exist (true), or otherwise (false) 
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
