/**
 * @file iface.h
 *
 * @brief IP address getter declaration
 */

#ifndef IFACE_H
#define IFACE_H

/**
 * @brief Return the IP address given a net interface name
 *
 * @param iface Net interface
 *
 * @return IP address 
 */
char *iface_ip(const char *iface);


#endif  /* IFACE_H */

