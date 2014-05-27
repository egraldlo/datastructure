#include <stdint.h>

#define int1store(T,A)       do { *((uint8_t *)(T)) = (uint8_t)(A); } while (0)
#define int2store(T,A)       do { uint def_temp= (uint) (A) ;   \
    *((uint8_t*) (T))=  (uint8_t)(def_temp);                    \
    *((uint8_t*) (T)+1)=(uint8_t)((def_temp >> 8));             \
  } while(0)
#define int3store(T,A)       do { /*lint -save -e734 */ \
    *((uint8_t*)(T))=(uint8_t) ((A));                   \
    *((uint8_t*) (T)+1)=(uint8_t) (((A) >> 8));         \
    *((uint8_t*)(T)+2)=(uint8_t) (((A) >> 16));         \
    /*lint -restore */} while(0)
#define int4store(T,A)       do { *((char *)(T))=(char) ((A));  \
    *(((char *)(T))+1)=(char) (((A) >> 8));                     \
    *(((char *)(T))+2)=(char) (((A) >> 16));                    \
    *(((char *)(T))+3)=(char) (((A) >> 24)); } while(0)

#define C_SUCCESS 0

#define C_SIZE_OVERFLOW -1
