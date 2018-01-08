/*
 * This program goes over some complex declarations in C
 */

int main()
{
  /* TODO: Write an explanation for this and
   * 	   then write the same line of code with
   *	   typedefs for better readability.
   */ 
  void (* ( *f [5] ) (void) ) (void);
  
  /* TODO: Verify.
   * My attempt at deciphering this: 
   * This a function pointer called signal that takes in the following arguments:
   * 1) an int
   * 2) a function pointer that takes in an int and returns a double
   * Additionally, signal will return a function pointer that takes in an int and a char as args, and will return a float. 
   * Is that correct?
   */
  float ( * (*signal) ( int, double (*) (int) ) ) (int, char);
  return 0;
}
