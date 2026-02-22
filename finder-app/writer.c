#include <stdio.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
  FILE *file = NULL;
  openlog(NULL, 0, LOG_USER);
  
  /* Check for the correct number of arguments */
  if (argc != 3)
  {
    syslog(LOG_ERR, "Invalid number of arguments: %d. Should be path and write-string", argc);
    return 1;
  }
  
  /* Open the file. Create the file if it doesn't exist.*/
  file = fopen(argv[1], "w+");
  if (file == NULL)
  {
    /* Failed to open the file. */
    syslog(LOG_ERR,"Failed to open file %s.", argv[1]);
    return 1;
  }
  
  /* Write the contents to the file */
  syslog(LOG_DEBUG, "Writing %s to file %s", argv[2], argv[1]);
  fprintf(file, "%s", argv[2]);
  fclose(file);
  return 0;
}
