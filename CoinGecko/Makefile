# Build CoinGecko Library

.PHONY : clean

CC = g++
CPPFLAGS = -fPIC -Wall -c -std=c++14 -I./include
LDFLAGS  = -shared

SOURCES  = ./src/asset_platforms.cpp \
	./src/categories.cpp \
	./src/coins.cpp \
	./src/companies.cpp \
	./src/contract.cpp \
	./src/derivatives.cpp \
	./src/events.cpp \
	./src/exchange_rates.cpp \
	./src/exchanges.cpp \
	./src/finance.cpp \
	./src/gecko.cpp \
	./src/global.cpp \
	./src/indexes.cpp \
	./src/simple.cpp \
	./src/status_updates.cpp \
	./src/trending.cpp \
	./src/web.cpp
OBJECTS  = $(SOURCES:.cpp=.o)

TARGET   = ../Libraries/libcoingecko.so

all: $(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)
