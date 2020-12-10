#include <aio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    void * buf = malloc(8);


    struct aiocb * aiocbp = (struct aiocb *) malloc(sizeof(struct aiocb));
    aiocbp->aio_nbytes = 8;
    aiocbp->aio_offset = 0;
    aiocbp->aio_fildes = open(argv[1], O_RDONLY);
    aiocbp->aio_buf = buf;
    aio_read(aiocbp);
    //read(aiocbp->aio_fildes, aiocbp->aio_buf, aiocbp->aio_nbytes);
    char * a = (char *) aiocbp->aio_buf;
    for(int i = 0; i < 8; i++){
        printf("%c\n", *a);
        a++;
    }

    free(buf);
}