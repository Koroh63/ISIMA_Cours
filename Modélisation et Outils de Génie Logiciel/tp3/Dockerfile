FROM gcc:latest

RUN apt-get update && apt-get install -y git 

WORKDIR /app

COPY main.cpp /app/main.cpp


RUN git clone https://github.com/nlohmann/json.git && \
    mkdir -p /app/json/include

RUN g++ main.cpp -o main -I/app/json/single_include -std=c++17

CMD ["./main"]