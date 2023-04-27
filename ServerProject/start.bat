docker build -t server_container .
docker run -it -p 34197:34197 --name proj-server server_container
pause