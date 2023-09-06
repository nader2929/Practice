#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

int copyFile(char *src, char *dest){
    printf("Copying: %s to %s\n-\n", src, dest);

    FILE *stream_src;
    FILE *stream_dest;
    stream_src = fopen (src, "r+");
    // stream_src = fopen ("/home/nader/Pictures/My Pictures/2016-09-07 Pafos Airport photos/IMG_20160907_184436.jpg", "r+");
    stream_dest = fopen (dest, "w+");
    int c;
    while ((c = fgetc(stream_src)) != EOF){
        fputc (c, stream_dest);
    }
    fclose(stream_src);
    fclose(stream_dest);
}

int getFilesFromDir(char *directory, char *destDir, long recurse){

    DIR *pDir;
    pDir = opendir (directory);
    if (pDir == NULL) {
        printf ("Cannot open directory '%s'\n", directory);
        return 1;
    }
    printf("\tDir: %s\n", directory);
    // Process each entry.
    struct dirent *pDirent;
    long srcPathLength = strlen(directory);
    while ((pDirent = readdir(pDir)) != NULL) {
        // printf("Filename: %s\n", pDirent->d_name);
        if(strcmp(pDirent->d_name, "..") == 0 || strcmp(pDirent->d_name, ".") == 0) continue;

        long fileLength = strlen(pDirent->d_name);
        long srcFilePathLength = srcPathLength + fileLength + 2;
        char srcFullPath[srcFilePathLength];
        memset(srcFullPath, 0, srcFilePathLength);

        strcat(srcFullPath, directory);
        strcat(srcFullPath, "/");
        strcat(srcFullPath, pDirent->d_name);

        struct stat s;
        stat(srcFullPath, &s);
        int isFile = S_ISREG(s.st_mode);
        // printf ("[%s][%d]\n", srcFullPath, isFile);
        if(isFile != 1 && recurse != 0){
            printf("\t\tRecursing\n");
            getFilesFromDir(srcFullPath, destDir, recurse);
        }
        else if(isFile == 1){
            long destPathLength = strlen(destDir);
            long destFilePathLength = destPathLength + fileLength + 2;
            char destFullPath[destFilePathLength];
            memset(destFullPath, 0, destFilePathLength);

            strcat(destFullPath, destDir);
            strcat(destFullPath, "/");
            strcat(destFullPath, pDirent->d_name);

            copyFile(srcFullPath, destFullPath);
        }
    }
}

int main(int argc, char **argv){
    char *sourceDir;
    char *temp;
    long recurse = 0; 
    if(argc < 2){
        printf("Please give the path from which to extract all files\n");
        return 1;
    }
    printf("\tTo recurse through all the sub directories, give an extra number arguement of any value\n");
    if(argc > 2){
        recurse = strtol(argv[2], &temp, 10);
    }

    sourceDir = argv[1];
    printf("Path: %s\n", sourceDir);

    int file_exists;
    if (access(sourceDir, F_OK) == 0) {
        file_exists = 1;
    } else {
        file_exists = 0;
        printf("This path does not exist, goodbye\n");
        return 1;
    }

    if(recurse != 0){
        printf("Will recurse through subdirectories\n");
    }
    else{
        printf("Will not recurse through subdirectories\n");
    }

    char cwd[250];
    getcwd(cwd, sizeof(cwd));
    printf("I am working in: %s\n", cwd);

    char *destDir = strcat(cwd, "/recursive_file_extractor");
    mkdir(destDir, 0777);
    printf("Will save files to: %s\n", destDir);

    getFilesFromDir(sourceDir, destDir, recurse);

    printf("\n");

}