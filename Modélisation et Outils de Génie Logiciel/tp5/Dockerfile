# Étape 1 : Build
FROM debian:bullseye-slim AS builder

# Installer les dépendances
RUN apt-get update && apt-get install -y \
    g++ cmake make git libsqlite3-dev wget && \
    apt-get clean

# Installer httplib
WORKDIR /usr/local/src
RUN git clone https://github.com/yhirose/cpp-httplib.git

# Installer SQLiteCpp
RUN git clone https://github.com/SRombauts/SQLiteCpp.git && \
    cd SQLiteCpp && mkdir build && cd build && \
    cmake .. && make && make install

# Copier les fichiers source
WORKDIR /app
COPY . .

# Compiler le serveur
RUN mkdir build && cd build && \
    cmake .. && make

# Étape 2 : Exécution
FROM debian:bullseye-slim

# Copier l'exécutable et les bibliothèques nécessaires
COPY --from=builder /app/build/server /usr/local/bin/server
COPY --from=builder /usr/local/lib/libSQLiteCpp.so /usr/local/lib/
COPY --from=builder /usr/lib/x86_64-linux-gnu/libsqlite3.so.0 /usr/lib/x86_64-linux-gnu/

# Configurer le conteneur
EXPOSE 8080
CMD ["server"]
