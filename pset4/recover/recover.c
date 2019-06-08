#include <stdio.h>

#define buf_size 512


int main(int argc, char *argv[])
{


    //To ensure proper usage of the programs command line.
    if(argc!=2)
    {

        printf("\n Usage: ./recover card.raw");
        return 1;
    }

    char *infile = argv[1];

    //To ensure proper usage of the file that has to be opened.
    FILE *file = fopen(infile,"r");
    if(file == NULL)
    {

        fprintf(stderr,"file could not be opened");//To check for standard errors.
        return 1;

    }

    //This creats a memory block which has a size of 255 bytes because the ff means 255.
    unsigned char buffer[buf_size];

    //A file counter that represents the file number(The name of the file in the document).
    int filecount =0;


    //This pointer is used to open the file that has the jpeg image, here we use it to open images continuesly.
    FILE *picture = NULL;

    //To check if the file is a JPEG we make a signal.
    int isjpeg = 0; // It is set to false.

    //To iterate over the memory card till there is no bloks left.
    while(fread(buffer, buf_size, 1, file) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if(isjpeg == 1)
            {

                fclose(picture);

            }
            else
            {

                isjpeg = 1;

            }

            char filename[8];
            sprintf(filename,"%03d.jpg",filecount);
            picture = fopen(filename,"a");
            filecount++;

        }
        if(isjpeg == 1)
        {
            //This is to write 512 bytes once we find jpegs.
            fwrite(&buffer, buf_size, 1, picture);

        }

    }

    //To close the open files.
    fclose(file);
    fclose(picture);

}