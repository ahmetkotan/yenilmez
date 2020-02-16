FROM alpine:latest
LABEL maintainer="Ahmet Kotan ahmet.kotan@invictuseurope.com"

RUN apk update

# Install Compiler
RUN apk add --virtual build-deps gcc musl-dev make

# Install Cmake
RUN apk add pkgconfig cmake

# Install Glib (Requirement)
RUN apk add glib-dev

# Install and Configure OpenSSH
RUN apk add --no-cache openssh
RUN mkdir /var/run/sshd
RUN echo 'root:YenilmezDev' | chpasswd
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# Generate SSH Keys
RUN ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key -q -N ""
RUN ssh-keygen -t ecdsa -f /etc/ssh/ssh_host_ecdsa_key -q -N ""
RUN ssh-keygen -t ed25519 -f /etc/ssh/ssh_host_ed25519_key -q -N ""


ADD .docker/development/entrypoint.sh /entrypoint.sh
RUN sed -i 's/\r$//g' /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 22
ENTRYPOINT ["/entrypoint.sh"]
