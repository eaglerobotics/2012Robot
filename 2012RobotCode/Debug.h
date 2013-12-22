#ifndef DEBUG_H
#define DEBUG_H

/**
 * This file will make it easy to quickly and simply enable debug messages
 */

// Define for enabling debug messages
#define DEBUG_MODE false

// Define a print command for debug messages
#define printDebug(_message_) printf("%s",(DEBUG_MODE ? _message_ "\n" : ""))
#endif
