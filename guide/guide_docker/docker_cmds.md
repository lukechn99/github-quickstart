```docker ps``` will tell you about all running docker processes  
```docker exec -it <container-id>``` spins up a container  
```docker run -it <image>``` runs a specific docker image  
```docker run -it -d <image>``` runs the image in a detached state so that you can exit and still come back to it  
```docker cp <container-id>:/<path/to/file> <path/to/local/directory``` copies a file from inside of the docker image and puts it at the directory you specify  
