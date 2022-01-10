FROM gcc:11.2

WORKDIR /usr/src/app

RUN  apt-get update && apt-get install -y libgtest-dev cmake

RUN cd /usr/src/gtest \
    mkdir build \
    cd build \
    cmake .. \
    make \
    make install \
    cd /usr/src/app

COPY . .


RUN make
RUN g++ test/wordcounter_unittest.cpp -o wordcounter_test /usr/src/app/src/wordcounter.cpp -lgtest -lgtest_main -lpthread

CMD [ "./wordcounter_test" ]