FROM ubuntu:latest
RUN apt-get update && apt-get install -y supervisor
RUN apt-get -y install curl
RUN apt-get -y install gnupg
RUN apt-get -y install nano


ENV NODE_VERSION=16.13.0
RUN apt install -y curl
RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.0/install.sh | bash
ENV NVM_DIR=/root/.nvm
RUN . "$NVM_DIR/nvm.sh" && nvm install ${NODE_VERSION}
RUN . "$NVM_DIR/nvm.sh" && nvm use v${NODE_VERSION}
RUN . "$NVM_DIR/nvm.sh" && nvm alias default v${NODE_VERSION}
ENV PATH="/root/.nvm/versions/node/v${NODE_VERSION}/bin/:${PATH}"
RUN node --version
RUN npm --version

RUN npm install -g --unsafe-perm node-red
RUN npm install -g --unsafe-perm node-red-admin
EXPOSE 1481-1900
CMD ["/usr/bin/supervisord"]
#docker run -p 1581-1600:1581-1600 -v ${PWD}/etc/supervisor:/etc/supervisor -v ${PWD}/var/log/supervisor:/var/log/supervisor -v ${PWD}/rules:/rules --name IBB_clusters ibb-docker