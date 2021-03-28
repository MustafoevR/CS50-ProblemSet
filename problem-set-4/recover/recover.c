#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define BLOCK 512
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
          // Pseudocode

    // Open a memory card
    FILE *recover = fopen(argv[1], "r");
    if(recover == NULL)
    {
        return 1;
    }

    int bytes_read;
    bool is_first_jpg = false, if_found = false;
    char filename[150];
    // Read 512 bytes into a buffer
    BYTE buffer[BLOCK];
    int img_count = 0;
    FILE *current_file;

 //   B1 || B2 || B3 || B4

    // Repeat until end of card
    while(true)
    {
       bytes_read = fread(buffer, sizeof(BYTE), BLOCK, recover);
       if(bytes_read == 0)
       {
           break;
       }

       // If start of new JPEG
       if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
       {
          if_found = true;
          // If first JPEG
          if(!is_first_jpg)
          {
            is_first_jpg = true;
          }
    //      Else if you already found
    //         ......close the file that you were writing too to open up a new one
          else
          {
             fclose(current_file);
          }
          sprintf(filename, "%03i.jpg", img_count);
          current_file = fopen(filename, "w");
          fwrite(buffer, sizeof(BYTE), BLOCK, current_file);
          img_count++;
       }
    //   Else
    //      If already found keep writing to it
       else
       {
          if(if_found)
          {
             fwrite(buffer, sizeof(BYTE), BLOCK, current_file);
          }
       }
    }
}
