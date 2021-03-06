#include "7seg.h"


/*

   AAAAA
  F     B
  F     B
  F     B
   GGGGG
  E     C
  E     C
  E     C
   DDDDD   dp


*/

 unsigned char CG[] = { 
  (1<<A|1<<B|1<<C|1<<D|1<<E|1<<F),     /* 0 */
  (1<<B|1<<C),                         /* 1 */
  (1<<A|1<<B|1<<D|1<<E|1<<G),          /* 2 */
  (1<<A|1<<B|1<<C|1<<D|1<<G),          /* 3 */
  (1<<B|1<<C|1<<F|1<<G),               /* 4 */
  (1<<A|1<<C|1<<D|1<<F|1<<G),          /* 5 */
  (1<<A|1<<C|1<<D|1<<E|1<<F|1<<G),     /* 6 */
  (1<<A|1<<B|1<<C),                    /* 7 */
  (1<<A|1<<B|1<<C|1<<D|1<<E|1<<F|1<<G),/* 8 */  
  (1<<A|1<<B|1<<C|1<<D|1<<F|1<<G),     /* 9 */  
  (1<<A|1<<B|1<<C|1<<E|1<<F|1<<G),     /* A */
  (1<<C|1<<D|1<<E|1<<F|1<<G),          /* B */
  (1<<A|1<<D|1<<E|1<<F),               /* C */
  (1<<B|1<<C|1<<D|1<<E|1<<G),          /* D */
  (1<<A|1<<D|1<<E|1<<F|1<<G),          /* E */
  (1<<A|1<<E|1<<F|1<<G),               /* F */
  0                                    /* Blank */
};



 unsigned char CG2[] = { 
  (1<<A|1<<B|1<<C|1<<D|1<<E|1<<F),     /* 0 */
  (1<<B|1<<C),                         /* 1 */
  (1<<A|1<<B|1<<D|1<<E|1<<G),          /* 2 */
  (1<<A|1<<B|1<<C|1<<D|1<<G),          /* 3 */
  (1<<B|1<<C|1<<F|1<<G),               /* 4 */
  (1<<A|1<<C|1<<D|1<<F|1<<G),          /* 5 */
  (1<<A|1<<C|1<<D|1<<E|1<<F|1<<G),     /* 6 */
  (1<<A|1<<B|1<<C),                    /* 7 */
  (1<<A|1<<B|1<<C|1<<D|1<<E|1<<F|1<<G),/* 8 */  
  (1<<A|1<<B|1<<C|1<<D|1<<F|1<<G),     /* 9 */  
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  (1<<A|1<<B|1<<C|1<<E|1<<F|1<<G),     /* A */
  (1<<C|1<<D|1<<E|1<<F|1<<G),          /* B */
  (1<<A|1<<D|1<<E|1<<F),               /* C */
  (1<<B|1<<C|1<<D|1<<E|1<<G),          /* D */
  (1<<A|1<<D|1<<E|1<<F|1<<G),          /* E */
  (1<<A|1<<E|1<<F|1<<G),               /* F */
  (1<<A|1<<C|1<<D|1<<E|1<<F),          /* G */
  (1<<B|1<<C|1<<E|1<<F|1<<G),          /* H */
  (1<<E|1<<F),                         /* I */
  (1<<B|1<<C|1<<D|1<<E),               /* J */
  0,                                   /* K */
  (1<<D|1<<E|1<<F),                    /* L */
  0,                                   /* M */
  (1<<C|1<<E|1<<G),                    /* N */
  (1<<C|1<<D|1<<E|1<<G),               /* O */
  (1<<A|1<<B|1<<E|1<<F|1<<G),          /* P */
  (1<<A|1<<B|1<<C|1<<F|1<<G),          /* Q */
  (1<<E|1<<G),                         /* R */
  (1<<A|1<<C|1<<D|1<<F|1<<G),          /* S */
  (1<<D|1<<E|1<<F|1<<G),               /* T */
  (1<<C|1<<D|1<<E),                    /* U */
  0, 
  0, 
  0, 
  (1<<B|1<<C|1<<D|1<<F|1<<G),
  0
};


