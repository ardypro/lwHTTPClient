#ifndef MEMFREE_H_INCLUDED
#define MEMFREE_H_INCLUDED

// MemoryFree library based on code posted here:
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1213583720/15
//
// Extended by Matthew Murdoch to include walking of the free list.



#ifdef __cplusplus
extern "C" {
#endif

  int freeMemory();

#ifdef  __cplusplus
}
#endif



#endif // MEMFREE_H_INCLUDED
