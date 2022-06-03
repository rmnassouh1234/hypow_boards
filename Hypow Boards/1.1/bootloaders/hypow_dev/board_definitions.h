

#if defined(BOARD_ID_hypow_dev)
  #include "board_definitions_hypow_dev.h"
#else
  #error You must define a BOARD_ID and add the corresponding definitions in board_definitions.h
#endif

// Common definitions
// ------------------

#define BOOT_PIN_MASK (1U << (BOOT_LOAD_PIN & 0x1f))

